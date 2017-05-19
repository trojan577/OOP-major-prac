#include "map.h"

Map::Map(int rows, int cols, int pages)
{
	this->rows = rows;
	this->cols = cols;
	this->pages = pages;
	// Init the map
	this->map = new char**[pages];
	for(unsigned int i = 0; i < pages; ++i)
	{
		map[i] = new char*[rows];
		for(unsigned int j = 0; j < rows; ++j)
		{
			map[i][j] = new char[cols];
		}
	}
}

void Map::displayMap(WINDOW* win, int pageNum)
{	
	for(unsigned int i = 0; i < rows; ++i)
	{
		for(unsigned int j = 0; j < cols; ++j)
		{
			mvwprintw(win, 1+j, 1+i, "%c", map[pageNum][i][j]);
		}
		
	}
	
}

Map::~Map()
{
	for(unsigned int i = 0; i < pages; ++i)
	{
		for(unsigned int j = 0; j < rows; ++j)
		{
			delete[] map[i][j];
		}
		delete[] map[i];
	}
	delete[] map;
}

void Map::createMap()
{
	for(unsigned int i = 0; i < pages; ++i)	{
		for(unsigned int j = 0; j < rows; ++j)		{
			for(unsigned int k = 0; k < cols; ++k)			{
				if ( (j==0) || (j==rows-1) ) {
					map[i][j][k] = '|';
				}else if( (k==0) || (k==cols-1) ) {
					map[i][j][k] = '_';
				}else{
					map[i][j][k] = ' ';
				}
			}

		}
	}
}

