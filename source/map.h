#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <string>
#include <vector>
#include <ncurses.h>

using namespace std;

class Map{
                
	int rows, cols, pages;
    char ***map;
public:
    void displayMap(WINDOW*, int);
    void createMap();
    char*** getMap();
    Map(int rows, int cols, int pages);
    ~Map();
};

#endif // MAP_H
