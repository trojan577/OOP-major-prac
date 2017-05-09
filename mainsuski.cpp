/* This is a test main for the ncurses library */
#include <iostream>
#include <ncurses.h>
#include <windows.h>

using namespace std;

// TODO: make a function getWinSize(*window) that returns a struct with size.x & size.y

struct sizeMax
{
	int y, x;
};

/* Function that returns a struct with ymax and xmax */
sizeMax getWinSize(WINDOW *);

int x=0, y=0; //sets beginning coord of the char in the map  im not sure how to get it to coord inside the map :(
void gotoXY(int argX, int argY);
int main(){
    while(true){
        if(getAsyncKeyState(VK_UP)    && (y+1!="@") && (y+1!="-") && (y+1!="|")) // moves the character around the map if there is nothing in the way
            gotoXY(x, y+1);
        if(getAsyncKeyState(VK_DOWN)  && (y-1!="@") && (y-1!="-") && (y-1!="|")) // all the != are checking for colisions with walls and objects
            gotoXY(x, y-1);
        if(getAsyncKeyState(VK_LEFT)  && (x-1!="@") && (x-1!="-") && (x-1!="|"))
            gotoXY(x-1, y);
        if(getAsyncKetState(VK_RIGHT) && (x+1!="@") && (x+1!="-") && (x+1!="|"))
            gotoXY(x+1, y);
    }
}

void gotoXY(int argX, int argY){
    x=argX;
    y=argY;
}

int main(int argc, char **argv)
{
	initscr(); 		//creates stdscr
	cbreak();		//allows CTRL+C and such to force quit program
	keypad(stdscr, TRUE);	//allows up dwn left right delete bcksp etc.

	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);

	int height, width;

	height = 	yMax / 2; 	//integer division
	width = 	xMax / 2;	//integer division

	/* Creating 3 windows with edges that line up */
	WINDOW *win1 = newwin(height, width, 		0,	 	0);				// Top left
	WINDOW *win2 = newwin(height, width, 		0, 		xMax/2);		// Top right
	WINDOW *win3 = newwin(height, 2*(xMax/2) , 	yMax/2, 0);				// Bottom

	refresh();			//this is NEEDED! for windows to show up

	box(win1, 0, 0);
	box(win2, 0, 0);
	box(win3, 0, 0);

	int win1_y_max, win1_x_max, win2_y_max, win2_x_max;
	// getmaxyx(win1, win1_y_max, win1_x_max);
	struct sizeMax s2 = getWinSize(win1);
	win1_y_max = s2.y;
	win1_x_max = s2.x;
	getmaxyx(win2, win2_y_max, win2_x_max);

	struct sizeMax s1 = getWinSize(win2);
	win2_y_max = s1.y;
	win2_x_max = s1.x;



	// Move window print window shifts cursor before printing
	mvwprintw(win1, win1_y_max/2 - 1, win1_x_max/2 - 9, "Centre of window 1");	
	mvwprintw(win2, win2_y_max/2 - 1, win2_x_max/2 - 9, "--------------------\n 
                                                         |                  |\n
                                                         |                  |\n
                                                         |                  |\n
                                                         |   @@@            |\n
                                                         |   @        	    |\n
                                                         |   @@@            |\n
                                                         |                  |\n
                                                         |                  |\n
														 --------------------");	//sets up a small box in the second square 
	mvwprintw(win3, win1_y_max/2 - 1, xMax/2 - 9, 		"Centre of window 3");	
	mvwprintw(win2, x				, y			,		"*"					);		//the actual character that moves around the room
	wrefresh(win1);
	wrefresh(win2);
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