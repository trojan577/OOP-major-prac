#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <string>
#include <vector>

class Map{
                //initialises a vector of vectors with area 15 by 15
    vecter< vector<std::string> > mapLayout(15, vector<std::string>(15));
public:
    void displayMap();
}

#endif