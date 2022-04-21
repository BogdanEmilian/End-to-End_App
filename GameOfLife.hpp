#pragma once
#include <string.h>

class GameOfLife
{
public:
	GameOfLife(int);
	void evolvingStage();
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

	//SPLITING FOR LOOPS FOR EACH CASE OF POSITION IN THE MATRIX

	//Top-Left Corner
	{
		if ((_map[1][0] == true) && (_map[0][1] == true) && (_map[1][1] == true))
		{
			_tempMap[0][0] = true;
		}
	}

	//Top-Right Corner
	{
		if ((_map[_n - 2][0] == true) && (_map[_n - 2][1] == true) && (_map[_n - 1][1] == true))
		{
			_tempMap[_n - 1][0] = true;
		}
	}

	//Bottom-Right Corner
	{
		if ((_map[_n - 2][_n - 2] == true) && (_map[_n - 1][_n - 2] == true) && (_map[_n - 2][_n - 1] == true))
		{
			_tempMap[_n - 1][_n - 1] = true;
		}
	}

	//Bottom-Left Corner
	{
		if ((_map[0][_n - 2] == true) && (_map[1][_n - 2] == true) && (_map[1][_n - 1] == true))
		{
			_tempMap[0][_n - 1] = true;
		}
	}

	//Top Side
	for (int x = 1; x < _n - 1; x++)
	{
		_neighbour = 0;

		if (_map[x - 1][0] == true)
		{
			_neighbour++;
		}
		if (_map[x - 1][1] == true)
		{
			_neighbour++;
		}
		if (_map[x][1] == true)
		{
			_neighbour++;
		}
		if (_map[x + 1][1] == true)
		{
			_neighbour++;
		}
		if (_map[x + 1][0] == true)
		{
			_neighbour++;
		}

		if (_neighbour >= 3)
		{
			_tempMap[x][0] = true;
		}
	}

	//Right Side
	for (int y = 1; y < _n - 1; y++)
	{
		_neighbour = 0;

		if (_map[_n - 1][y - 1] == true)
		{
			_neighbour++;
		}
		if (_map[_n - 2][y - 1] == true)
		{
			_neighbour++;
		}
		if (_map[_n - 2][y] == true)
		{
			_neighbour++;
		}
		if (_map[_n - 2][y + 1] == true)
		{
			_neighbour++;
		}
		if (_map[_n - 1][y + 1] == true)
		{
			_neighbour++;
		}

		if (_neighbour >= 3)
		{
			_tempMap[_n - 1][y] = true;
		}
	}

	//Bottom Side
	for (int x = 0; x < _n - 1; x++)
	{
		_neighbour = 0;

		if (_map[x - 1][_n - 1] == true)
		{
			_neighbour++;
		}
		if (_map[x - 1][_n - 2] == true)
		{
			_neighbour++;
		}
		if (_map[x][_n - 2] == true)
		{
			_neighbour++;
		}
		if (_map[x + 1][_n - 2] == true)
		{
			_neighbour++;
		}
		if (_map[x + 1][_n - 1] == true)
		{
			_neighbour++;
		}

		if (_neighbour >= 3)
		{
			_tempMap[x][_n - 1] = true;
		}
	}

	//Left Side
	for (int y = 1; y < _n - 1; y++)
	{
		_neighbour = 0;

		if (_map[0][y - 1] == true)
		{
			_neighbour++;
		}
		if (_map[1][y - 1] == true)
		{
			_neighbour++;
		}
		if (_map[1][y] == true)
		{
			_neighbour++;
		}
		if (_map[1][y + 1] == true)
		{
			_neighbour++;
		}
		if (_map[0][y + 1] == true)
		{
			_neighbour++;
		}

		if (_neighbour >= 3)
		{
			_tempMap[0][y] = true;
		}
	}

	
	//Center of the matrix
	for (int y = 0; y < _n; y++) {
		for (int x = 0; x < _n; x++) {
			
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
				_tempMap[x][y] = true;
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