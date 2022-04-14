#pragma once
#include <string.h>
//conver to .hpp
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
	bool** _map;	//maybe bool -> int
	int _n;

};
//More comments

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
	bool** _tempMap;

	memcpy(_tempMap, _map, sizeof(_map));
	for (int i = 0; i < _n; i++) {
		for (int j = 0; j < _n; i++) {
			setValue(i,j);
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

	if ((_map[i+1][j-1] == true) && (i + 1 < n) && (j - 1 >= 0)) 
		neighbour++;

	if ((_map[i-1][j] == true) && (i - 1 >= 0)) 
		neighbour++;
	
	if ((_map[i+1][j] == true) && (i + 1 < n)) 
		neighbour++;
	
	if ((_map[i-1][j+1] == true) && (i - 1 >= 0) && (j + 1 < n)) 
		neighbour++;
	
	if ((_map[i+1][j+1] == true) && (i + 1 < n) && (j + 1 < n)) 
		neighbour++;
	
	if ((_map[i][j+1] == true) && (j + 1 <n)) 
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