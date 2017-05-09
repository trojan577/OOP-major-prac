/* This is a test main for the ncurses library */
#include <iostream>
#include <ncurses.h>

using namespace std;

// TODO: make a function getWinSize(*window) that returns a struct with size.x & size.y

struct sizeMax
{
	int y, x;
};

/* Function that returns a struct with ymax and xmax */
sizeMax getWinSize(WINDOW *);

/* Function to print the menu items and return the selection */
int menu(WINDOW *, string[]);

/* initialize the screen */
void initialize();

int main(int argc, char **argv)
{	
	// Setting up ncurses parameters
	initialize();

	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);	// Global max (for the terminal size)

	int height, width;

	struct sizeMax terminal = getWinSize(stdscr);

	height = 	yMax / 2; 	// Integer division
	width = 	xMax / 2;	// Integer division

	// Creating 3 windows with edges that line up
	WINDOW *win1 = newwin(terminal.y/2, terminal.x/2, 		0,	 	0);			// Top left window
	WINDOW *win2 = newwin(terminal.y/2, terminal.x/2, 		0, 		xMax/2);		// Top right window
	WINDOW *win3 = newwin(terminal.y/2, 2*(xMax/2), 		yMax/2, 0);				// Bottom window

	refresh();			// Refreshing stdscr for windows to be drawn

	// Getting each windows maximum x and y size (win3 just fills the rest of the screen)
	struct sizeMax win1Size = getWinSize(win1);
	struct sizeMax win2Size = getWinSize(win2);

	// Drawing the box outline for each window
	box(win1, 0, 0);
	box(win2, 0, 0);
	box(win3, 0, 0);

	// Move window print window shifts cursor before printing
	mvwprintw(win1, win1Size.y/2 - 1, win1Size.x/2 - 9	, "Centre of window 1");
	mvwprintw(win2, win2Size.y/2 - 1, win2Size.x/2 - 9	, "Centre of window 2");
	mvwprintw(win3, win1Size.y/2 - 1, xMax/2 - 9		, "Centre of window 3");

	// Refreshing all windows to show the text and the boxes
	wrefresh(win1);
	wrefresh(win2);
	wrefresh(win3);

	werase(win3);		// Erases everything in the window
	box(win3, 0, 0);	// Redrawing the box outline
	keypad(stdscr, true);	// Grabbing input via stdscr (can use individual window)

	string options[3] = {"Play", "Quit", "Help"};

	int selected = menu(win3, options);
	mvwprintw(win3, 1, 1, "You chose: %s", options[selected].c_str());
	wrefresh(win3);

	getch();		// Pause until user input
	endwin();		// Closes stdscr and returns the terminal

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
	initscr(); 			// Creates stdscr
	cbreak();			// Allows CTRL+C and such to force quit program
	noecho();			// Stops user input printing on the screen
	curs_set(0);			// Stops cursor from showing
	// resize_term(40, 120);	// Allocates terminal size (y, x)
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
				wattron(win, A_REVERSE);		// Highlights current selection by inverting background and text
			}
			mvwprintw(win, i+winSize.y/2 - 1, winSize.x/2 - 2, options[i].c_str());
			wattroff(win, A_REVERSE);			// Removes the highlight
			wrefresh(win);
		}

		choice = wgetch(stdscr); 	// Waiting for user input

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

		if(choice == 10)		// 10 == enter key
		{
			break;
		}
	}
	return selection;
}
