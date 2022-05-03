#include "GameOfLife.hpp"

using namespace std;


int main()
{
	int n = 6;
	GameOfLife game(n);			//problem with undeclared identifier
	
	game.setValue(1, 1, true);
	game.setValue(1, 2, true);
	game.setValue(2, 1, true);

	cout << "Initial map:\n";

	game.printMap();
	game.evolvingStage();

	cout << "Final map:\n";

	game.printMap();

	return 0;
}