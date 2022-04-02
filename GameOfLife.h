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



private:
	bool** map;
	bool** tempMap;
	int n;

};

GameOfLife::GameOfLife(int size)
{
	n = size;
	map = new bool* [n];
	tempMap = new bool* [n];

	for (int i = 0; i < n; ++i) {
		map[i] = new bool[n];
		tempMap[i] = new bool[n];
	}

}

void GameOfLife::evolvingStage() 
{
	memcpy(tempMap, map, sizeof(map));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; i++) {
			setValue(i,j);
		}
	}
}

void GameOfLife::setValue(int i,int j)
{
	int neighbour = 0;

	if ((map[i - 1][j - 1] == true) && (i - 1 >= 0) && (j - 1 >= 0)) 
		neighbour++;
	
	if ((map[i][j-1] == true) && (j - 1 >= 0)) 
		neighbour++;

	if ((map[i+1][j-1] == true) && (i + 1 < n) && (j - 1 >= 0)) 
		neighbour++;

	if ((map[i-1][j] == true) && (i - 1 >= 0)) 
		neighbour++;
	
	if ((map[i+1][j] == true) && (i + 1 < n)) 
		neighbour++;
	
	if ((map[i-1][j+1] == true) && (i - 1 >= 0) && (j + 1 < n)) 
		neighbour++;
	
	if ((map[i+1][j+1] == true) && (i + 1 < n) && (j + 1 < n)) 
		neighbour++;
	
	if ((map[i][j+1] == true) && (j + 1 <n)) 
		neighbour++;

}

void GameOfLife::setGlider(int i, int j)
{

}