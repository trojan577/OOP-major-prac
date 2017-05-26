/* This is a test main for the ncurses library */
#include <iostream>
#include <ncurses.h>
#include <cstdlib>		// For exit()
#include "equipment.h"
#include "character.h"
#include "map.h"

using namespace std;

struct sizeMax
{
	int y, x;
};

/* Function that returns a struct with ymax and xmax */
sizeMax getWinSize(WINDOW *);

/* Function to print the menu items and return the selection */
int menu(WINDOW *, string[]);

/* Initialize the screen */
void initialize();

/* Function that prints help to win3 */
void printHelp(WINDOW *, sizeMax);

/* Function to draw equipment and inventory returns window array for inventory */
WINDOW** drawLoadout(WINDOW*, sizeMax);

/* Function to refresh all windows */
void refreshWins(WINDOW**, int);

/* Function to get string input from user */
string getString(WINDOW *);

/* Function to delete windows */
void deleteWin(WINDOW**, int);

/* Function to update players position on the map */
void drawCharacter(WINDOW*, Player*);

/* Function to remove players position on the map */
void removeCharacter(WINDOW*, Player*);

int main(int argc, char **argv)
{
	/*=====SETUP BEGIN=====*/
																// Setting up ncurses parameters
	initialize();

	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);								// Global max (for the terminal size)

	struct sizeMax terminal = getWinSize(stdscr);	

																// Creating 3 windows with edges that line up
	WINDOW **win = new WINDOW*[3];
	win[0] = newwin(terminal.y/2, terminal.x/2, 		0,	 	0);			// Top left window
	win[1] = newwin(terminal.y/2, terminal.x/2, 		0, 		xMax/2);	// Top right window
	win[2] = newwin(terminal.y/2, 2*(xMax/2), 		yMax/2, 	0);			// Bottom window

	refresh();													// Refreshing stdscr for windows to be drawn

																// Getting each windows maximum x and y size (win3 just fills the rest of the screen)
	struct sizeMax win1Size = getWinSize(win[0]);
	struct sizeMax win2Size = getWinSize(win[1]);
	struct sizeMax win3Size = getWinSize(win[2]);

																// Drawing the box outline for each window
	box(win[0], 0, 0);
	box(win[1], 0, 0);
	box(win[2], 0, 0);

	refreshWins(win, 3);

	werase(win[2]);												// Erases everything in the window
	box(win[2], 0, 0);											// Redrawing the box outline
	keypad(stdscr, true);										// Grabbing input via stdscr (can use individual window)
	/*=====SETUP END=====*/

																// Menu section
	bool finished = false;
	string options[3] = {"Play", "Quit", "Help"};
	int selected;
	do
	{
		werase(win[2]);
		box(win[2], 0, 0);
		selected = menu(win[2], options);
		mvwprintw(win[2], 1, 1, "You chose: %s", options[selected].c_str());
		wrefresh(win[2]);
		switch (selected)
		{
			case 0:												// They chose play
				finished = true;
				break;
			case 1:												// They chose quit
				endwin();
				exit(0);
			case 2:												// They chose help
				printHelp(win[2], win3Size);
				break;
		}

	}while(!finished);

																// Getting data for inventory boxes
	WINDOW **inventory = drawLoadout(win[0], win1Size);
	refreshWins(win, 3);

																// Main game loop
	finished = false;
	bool runOnce = true;
	char c;
	Player *p1 = new Player("unnamed", 100);
	Map *map = new Map(45, 16, 3);								// Map(width, height, pages)
	while(!finished)
	{
																// To quit the game press q at anytime
		c = wgetch(stdscr);
		if(c == 'q')
		{
			finished = true;
		}
		
		if(runOnce == true)
		{
			werase(win[2]);
			box(win[2], 0, 0);

																// Creating a character
			mvwprintw(win[2], 1, 1, "Please enter a name for your character: ");
			refreshWins(win, 3);
			string cName = getString(win[2]);
			p1->setName(cName);
			WINDOW *nameWin = newwin(1, 20, 1, 1);
			mvwprintw(nameWin, 0, 0, p1->getName().c_str());
			wrefresh(nameWin);
			mvwprintw(win[2], 2, 1, "You start with a butterknife");

			Knife butterknife("butterknife", "==--", 1, 1);

			mvwprintw(inventory[0], 1, 1, butterknife.getSymbol().c_str());
			refreshWins(inventory, 6);
			refreshWins(win, 3);

			wgetch(stdscr);
			mvwprintw(win[2], 3, 1, "and a spoon");

			Knife spoon("spoon", "O---", 1, 1);

			mvwprintw(inventory[1], 1, 1, spoon.getSymbol().c_str());
			refreshWins(inventory, 6);
			refreshWins(win, 3);

																// Making a map
			map->createMap();
			map->displayMap(win[1], 0);
			mvwprintw(win[2], 5, 1, "This is the map");
			refreshWins(win, 3);

			runOnce = false;
		}
																// Main game code begins here
		
		p1->move(c, map->getMap());
		drawCharacter(win[1], p1);
		refreshWins(win, 3);
		removeCharacter(win[1], p1);


	}
	deleteWin(inventory, 6);
	deleteWin(win, 3);

	endwin();													// Closes stdscr and returns the terminal

	return 0;
}

sizeMax getWinSize(WINDOW *win)
{
	struct sizeMax s1;
	getmaxyx(win, s1.y, s1.x);

	return s1;
}

void initialize()
{
	initscr(); 													// Creates stdscr
	cbreak();													// Allows CTRL+C and such to force quit program
	noecho();													// Stops user input printing on the screen
	curs_set(0);												// Stops cursor from showing
}																
	
int menu(WINDOW *win, string options[])
{
	int choice;
	int selection = 0;

	struct sizeMax winSize = getWinSize(win);

	/* Menu implementation */
	for(;;)
	{
		for(unsigned int i = 0; i < 3; ++i)
		{
			if(i == selection)
			{
				wattron(win, A_REVERSE);						// Highlights current selection by inverting background and text
			}
			mvwprintw(win, i+winSize.y/2 - 1, winSize.x/2 - 2, options[i].c_str());
			wattroff(win, A_REVERSE);							// Removes the highlight
			wrefresh(win);
		}

		choice = wgetch(stdscr); 								// Waiting for user input

		switch(choice)
		{
			case KEY_UP:
				if(selection > 0)
					selection--;
				break;
			case KEY_DOWN:
				if(selection < 2)
					selection++;
				break;
			default:
				break;
		}

		if(choice == 10)										// 10 == enter key
		{
			break;
		}
	}
	return selection;
}

void printHelp(WINDOW *win, sizeMax win3Size)
{
	werase(win);
	box(win, 0, 0);
	mvwprintw(win, 1, 1, "The #1 aim of this game is to have fun");
	mvwprintw(win, 2, 1, "The #2 aim of this game is to fight as many monsters in the makeshift");
	mvwprintw(win, 3, 1, "dungeon without dying. There are items and weapons that you may find useful");
	mvwprintw(win, 4, 1, "on the ground as you traverse the map.");
	mvwprintw(win, 6, 1, "Use up, down, left and right to move around.");
	mvwprintw(win, win3Size.y/2+5, win3Size.x/2-14, "Press any key to continue...");
	wrefresh(win);
	wgetch(stdscr);												// Wait for the user to press something
}

WINDOW** drawLoadout(WINDOW* win, sizeMax winSize)
{
	mvwprintw(win, 2, 1, " \\_( )_/ ");
	mvwprintw(win, 3, 1, "    |    ");
	mvwprintw(win, 4, 1, "    |    ");
	mvwprintw(win, 5, 1, "   / \\   ");
	mvwprintw(win, 6, 1, " _/   \\_ ");

	int nInv = 8;
	WINDOW** inventory = new WINDOW*[nInv];

	for(unsigned int i = 0; i < nInv; ++i)
	{
																// 5 high 5 across
		if(i < 4)
			*(inventory + i) = newwin(3, 6, 2+3*i, 12);
		else
			*(inventory + i) = newwin(3, 6, 2+3*(i%4), 12+6);
		box(inventory[i], 0, 0);
		wrefresh(*(inventory + i ));
	}
	return inventory;
}

void refreshWins(WINDOW **wins, int n)
{
	for(unsigned int i = 0; i < n; ++i)
		wrefresh(*(wins + i));
}

string getString(WINDOW* win)
{
	echo();														// Lets the user see what they have typed
	string input;
	char c;
	do
	{
		c = wgetch(win);
		input.push_back(c);

	}while(c != '\n');											// While not pressed enter
	noecho();
	return input;
}

void deleteWin(WINDOW **win, int n)
{
	for(unsigned int i = 0; i < n; ++i)
	{
		delwin(*(win + i));
	}
}

void drawCharacter(WINDOW *win, Player* p1)
{
	int x = p1->getPlayerPosX();
	int y = p1->getPlayerPosY();
	mvwprintw(win, 1+y, 1+x, "@");
}

void removeCharacter(WINDOW *win, Player* p1)
{
	int x = p1->getPlayerPosX();
	int y = p1->getPlayerPosY();
	mvwprintw(win, 1+y, 1+x, " ");
}
