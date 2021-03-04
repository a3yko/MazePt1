// Name: Adrian Atanasov
// Date: October, 8th 2015

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;
int startX = 0;
int startY = 2;
int step = 0;
int direction = 0;
int previous = 2;
const int arraySize= 12;
void printMaze(char maze[][arraySize], int, int, int); //prints the maze
void mazeTraverse(char maze[][arraySize], int, int, int, int); //puts an X at your current location in the maze
int validMove(char maze[][arraySize], int, int); //validates the direction
bool isSolved(int, int, int); //checks if you are at the exit

int _tmain(int argc, _TCHAR* argv[])
{
	int x_coord = 0;
	int y_coord = 2;

	char maze[arraySize][arraySize] = {													// contains the layout of the predetermined maze
		{ '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
		{ '#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#' },
		{ '.', '.', '#', '.', '#', '.', '#', '#', '#', '#', '.', '#' },
		{ '#', '#', '#', '.', '#', '.', '.', '.', '.', '#', '.', '#' },
		{ '#', '.', '.', '.', '.', '#', '#', '#', '.', '#', '.', '.' },
		{ '#', '#', '#', '#', '.', '#', '.', '#', '.', '#', '.', '#' },
		{ '#', '.', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#' },
		{ '#', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#' },
		{ '#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#' },
		{ '#', '#', '#', '#', '#', '#', '.', '#', '#', '#', '.', '#' },
		{ '#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#' },
		{ '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
	};

		printMaze(maze, arraySize, x_coord, y_coord);								// calls upon print maze in order to output the maze and the current location
		mazeTraverse(maze,arraySize,x_coord,y_coord,direction);						// calls upon maze traverse to move the current location
		system("pause");

	return 0;
}


//Printing the maze
void printMaze(char maze[][arraySize], int arraySize, int x_coord, int y_coord)		// x_coord and y_coord are the current location of the X
{
	for (int y = 0; y < 12; y++)
	{
		cout << endl;
		for (int x = 0; x < 12; x++)
		{
			if (x == x_coord && y == y_coord)										// if the x and y become the current location then an X is printed
				cout << 'X';														
			else																	// else the loop prints the predetermined maze
			cout << maze[x][y];			
		}
		
	}
}

// checks the surround area for a valid move
int validMove(char maze[][arraySize], int x_coord, int y_coord)
{
	enum face : int { right = 1, up = 2, left = 3, down = 4 };

	if (previous == right)											// based on the previous direction, the direction check order changes
	{
		if (maze[x_coord][y_coord + 1] == '.')
			return down;
		if (maze[x_coord + 1][y_coord] == '.')
			return right;
		if (maze[x_coord][y_coord - 1] == '.')
			return up;
		if (maze[x_coord - 1][y_coord] == '.')
			return left;
	
	}
	else if (previous == down)										// only passes true if the previous direction moved was down
	{
		if (maze[x_coord - 1][y_coord] == '.')						// checks left of the current position for the path, if true, returns direction to move 
			return left;
		if (maze[x_coord][y_coord + 1] == '.')						// checks below the current position for the path, if true, returns direction to move 
			return down;
		if (maze[x_coord + 1][y_coord] == '.')						// checks right of the current position for the path, if true, returns direction to move 
			return right;
		if (maze[x_coord][y_coord - 1] == '.')						// checks above of the current position for the path, if true, returns direction to move 
			return up;
	}
	else if (previous == left)
	{
		if (maze[x_coord][y_coord - 1] == '.')
			return up;
		if (maze[x_coord - 1][y_coord] == '.')
			return left;
		if (maze[x_coord][y_coord + 1] == '.')
			return down;
		if (maze[x_coord + 1][y_coord] == '.')
			return right;
	}
	else if (previous == up)
	{
		if (maze[x_coord + 1][y_coord] == '.')
			return right;
		if (maze[x_coord][y_coord - 1] == '.')
			return up;
		if (maze[x_coord - 1][y_coord] == '.')
			return left;
		if (maze[x_coord][y_coord + 1] == '.')
			return down;
	}


}

// Puts the X in the maze
void mazeTraverse(char maze[][arraySize], int arraySize, int x_coord, int y_coord, int direction)
{
	enum face : int { right = 1, up = 2, left = 3, down = 4 };
	if (isSolved(arraySize, x_coord, y_coord) == true)
	{
		cout << " The maze has been solved " << endl;
	}
	else
	{
		system("cls");
		printMaze(maze, arraySize, x_coord, y_coord);
		system("pause");
		if (validMove(maze, x_coord, y_coord) == right)						// if the current direction is right
		{										
			previous = right;
			mazeTraverse(maze, arraySize, x_coord + 1, y_coord, right);		// increase x_coord by 1
		}
		if (validMove(maze, x_coord, y_coord) == up)						// if the current direction is up
		{
			previous = up;
			mazeTraverse(maze, arraySize, x_coord, y_coord - 1, up);		// decrease y_coord by 1
		}
		if (validMove(maze, x_coord, y_coord) == left)						// if the current direction is left
		{
			previous = left;
			mazeTraverse(maze, arraySize, x_coord - 1, y_coord, left);		// decrease the x_coord by 1
		}
		if (validMove(maze, x_coord, y_coord) == down)						// if the current direction is down
		{
			previous = down;	
			mazeTraverse(maze, arraySize, x_coord, y_coord + 1, down);		// increatse the y_coord by 1
		}
	}
}

// checks if the maze has been solved
bool isSolved(int arraySize, int x_coord,  int y_coord)
{
	
	if (step == !0)
	{
		if (x_coord == 0 && y_coord == 2)
			cout << " The maze is unsolvable " << endl;
	}
	else if (x_coord == 4 && y_coord == 11)
		return true;
	else
	{
		step++;
		return false;
	}
}