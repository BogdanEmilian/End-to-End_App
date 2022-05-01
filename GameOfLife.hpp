#pragma once
#include <string.h>

class GameOfLife
{
public:
	GameOfLife(int);			//initialization
	void evolvingStage();		//a step in the evolution
	void setValue(int, int);
	void setGlider(int, int);
	bool** getMap();
	void setBlock(int, int);
	void setGliderGun(int, int);

private:
	bool** _map;
	int _n;

};

GameOfLife::GameOfLife(int size)
{
	bool** _tempMap;
	_n = size;
	_map = new bool* [_n];
	_tempMap = new bool* [_n];

	for (int i = 0; i < _n; ++i) {
		_map[i] = new bool[_n];
		_tempMap[i] = new bool[_n];
	}

}

void GameOfLife::evolvingStage() 
{
	bool** _tempMap;	//a temp map where the changes take place, before copying to the base map
	unsigned int _neighbour;

	memcpy(_tempMap, _map, sizeof(_map));

	//Center of the matrix scanning
	for (int y = 1; y < _n - 1; y++)
	{
		for (int x = 1; x < _n - 1; x++)
		{
			_neighbour = 0;

			if (_map[x - 1][y - 1] == true)
				{
					_neighbour++;
				}
			if (_map[x][y - 1] == true)
				{
					_neighbour++;
				}
			if (_map[x + 1][y - 1] == true)
				{
					_neighbour++;
				}
			if (_map[x - 1][y] == true)
				{
					_neighbour++;
				}
			if (_map[x + 1][y] == true)
				{
					_neighbour++;
				}
			if (_map[x - 1][y + 1] == true)
				{
					_neighbour++;
				}
			if (_map[x][y + 1] == true)
				{
					_neighbour++;
				}
			if (_map[x + 1][y + 1] == true)
				{
					_neighbour++;
				}

			if (_neighbour >= 3)
			{
				_tempMap[x][y] = true;	//alive cell
			}
			else
			{
				_tempMap[x][y] = false;	//dead cell
			}
		}
	}

}

void GameOfLife::setValue(int i,int j)
{
	int neighbour = 0;

	if ((_map[i - 1][j - 1] == true) && (i - 1 >= 0) && (j - 1 >= 0)) 
		neighbour++;
	
	if ((_map[i][j-1] == true) && (j - 1 >= 0)) 
		neighbour++;

	if ((_map[i+1][j-1] == true) && (i + 1 < _n) && (j - 1 >= 0)) 
		neighbour++;

	if ((_map[i-1][j] == true) && (i - 1 >= 0)) 
		neighbour++;
	
	if ((_map[i+1][j] == true) && (i + 1 < _n)) 
		neighbour++;
	
	if ((_map[i-1][j+1] == true) && (i - 1 >= 0) && (j + 1 < _n)) 
		neighbour++;
	
	if ((_map[i+1][j+1] == true) && (i + 1 < _n) && (j + 1 < _n)) 
		neighbour++;
	
	if ((_map[i][j+1] == true) && (j + 1 < _n)) 
		neighbour++;

}

void GameOfLife::setGlider(int x, int y)
{
	setValue(x + 1, y);
	setValue(x + 2, y + 1);
	setValue(x, y + 2);
	setValue(x + 1, y + 2);
	setValue(x + 2, y + 2);
}

void GameOfLife::setBlock(int x, int y) 
{
	setValue(x, y);
	setValue(x, y+1);
	setValue(x+1, y);
	setValue(x+1, y+1);

}

void GameOfLife::setGliderGun(int x, int y)
{
	//https://en.wikipedia.org/wiki/Gun_(cellular_automaton)
}