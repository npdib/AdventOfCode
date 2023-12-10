// Day10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <stdbool.h>

typedef struct
{
	uint16_t x;
	uint16_t y;
} CoOrd;

typedef enum
{
	Above,
	Below,
	Left,
	Right
} Direction;

typedef struct move_t
{
	CoOrd pos;
	Direction movDir;
	uint32_t pipe_length = 0;
} Move;

typedef std::vector<std::string> Map;

bool isConnected(char pipe, Direction direction)
{
	switch (pipe)
	{
	case '|':
		if (direction == Above or direction == Below)
			return true;
		break;
	case '-':
		if (direction == Left or direction == Right)
			return true;
		break;
	case 'L':
		if (direction == Left or direction == Below)
			return true;
		break;
	case 'J':
		if (direction == Right or direction == Below)
			return true;
		break;
	case '7':
		if (direction == Right or direction == Above)
			return true;
		break;
	case 'F':
		if (direction == Left or direction == Above)
			return true;
		break;
	}
	return false;
}

std::vector<Direction> getConnections(CoOrd point, Map maze)
{
	std::vector<Direction> connectedSides;

	if (point.y > 0 and isConnected(maze[point.y - 1][point.x], Above))
	{
		connectedSides.push_back(Above);
	}
	if (point.y < maze.size() and isConnected(maze[point.y + 1][point.x], Below))
	{
		connectedSides.push_back(Below);
	}
	if (point.x > 0 and isConnected(maze[point.y][point.x - 1], Left))
	{
		connectedSides.push_back(Left);
	}
	if (point.x < maze[0].length() and isConnected(maze[point.y][point.x + 1], Right))
	{
		connectedSides.push_back(Right);
	}

	return connectedSides;
}

Direction getNewDirection(char point, Direction currentDir)
{
	switch (point)
	{
	case '|':
		break;
	case '-':
		break;
	case 'L':
		if (currentDir == Left)
			return Above;
		return Right;
		break;
	case 'J':
		if (currentDir == Right)
			return Above;
		return Left;
		break;
	case '7':
		if (currentDir == Right)
			return Below;
		return Left;
		break;
	case 'F':
		if (currentDir == Left)
			return Below;
		return Right;
		break;
	}
	return currentDir;
}

void getNextMove(Map maze, Move& currentMove)
{
	switch (currentMove.movDir)
	{
	case Right:
		currentMove.pos.x++;
		break;
	case Left:
		currentMove.pos.x--;
		break;
	case Above:
		currentMove.pos.y--;
		break;
	case Below:
		currentMove.pos.y++;
		break;
	}

	if (maze[currentMove.pos.y][currentMove.pos.x] == 'S')
		return;

	currentMove.movDir = getNewDirection(maze[currentMove.pos.y][currentMove.pos.x], currentMove.movDir);

	currentMove.pipe_length++;
}

int main()
{
	Map Maze;
	CoOrd Animal;

	std::string line;
	std::ifstream input("input.txt");

	uint16_t line_num = 0;

	while (std::getline(input, line)) // scan through input, find the S and create a local copy of the maze
	{
		for (int i = 0; i < line.length(); i++)
		{
			if (line[i] == 'S') // if the character is an S, its the animal
			{
				Animal.y = line_num; // set the row and col num of the animal
				Animal.x = i;
			}
		}

		Maze.push_back(line); // add the line to the maze vector
		line_num++; // increase the current line count
	}

	std::vector<Direction> AnimalConnections = getConnections(Animal, Maze); // get the sides the animal is connected to

	Move currentMove;
	currentMove.movDir = AnimalConnections[0];
	currentMove.pos = Animal;

	std::vector<CoOrd> Loop;

	do
	{
		getNextMove(Maze, currentMove);
		Loop.push_back(currentMove.pos);
	} while (currentMove.pos.x != Animal.x or currentMove.pos.y != Animal.y);

	uint16_t up = 0;
	uint32_t contained = 0;

	for (int j = 0; j < Maze.size(); j++)
	{
		for (int i = 0; i < Maze[0].length(); i++)
		{
			bool contains = false;
			for (auto l : Loop)
			{
				if (l.x == i and l.y == j)
				{
					contains = true;
					break;
				}
			}

			if (!contains)
			{
				if (up % 2 == 1)
				{
					contained++;
					printf("o");
				}
				else
				{
					printf(".");
				}
			}
			else
			{
				switch (Maze[j][i])
				{
				case '|':
					up++;
					break;
				case 'L':
					up++;
					break;
				case 'J':
					up++;
					break;
				}

				printf("%c", Maze[j][i]);
			}
		}
		printf("\n");
		up = 0;
	}

	printf("\n");
	printf("total pipe length of part 1 is:\t%u\n", currentMove.pipe_length);
	printf("total contained pieces is:\t%u", contained);

	//printf("%c\t%d\t%d\n", Maze[Animal[0]][Animal[1]], Animal[0], Animal[1]);
}