#pragma once
#include <iostream>
#include <cstdio>
#include <vector>
#include "State.h"
#include <string>
#include "Cell.h"
//TODO REMOVE
using namespace std;
#define SH_SIZE 11

// CELL STRUCTURE

enum MOVE
{
	DOWN, UP, LEFT, RIGHT
};

/*
class Edge {

public:
	int desx;
	int desy;
	int sorx;
	int sory;
	
	
	Edge& operator=(const Edge& other) {
		desx = other.desx;
		desy = other.desy;
		sorx = other.sorx;
		sory = other.sory;
		
		return *this;
	}


	
};
*/
class Maze2d {
private:
	Cell Level[SH_SIZE][SH_SIZE];
	Cell* _start;
	Cell*_end;
	vector<int> order;
public:
	// contain the possible state of movement in the maze
	vector<State<Cell>> allstate;
public:

	Maze2d(Maze2d & maze);
	Maze2d();
	//constractor get vector of char and recovers to maze 
	Maze2d(const vector<char> vec);
	Maze2d& operator=(const Maze2d& m);
	void Redraw();
	virtual bool checkValid(int NextX, int Nexty);
	void setpossibleState(Cell** poss);
	Cell** getpossibleState();
	void Setdisplay(int x, int y, string str);
	void SetStartPosition(int x, int y);
	bool chekVisitedPoint(int x, int y);
	void Setvisited(int x, int y);
	void SetBreakWall(int x, int y, MOVE wall);
	void SetEndPosition(int x, int y);
	void initMaze();
	void displaySolve(int x, int y);
	//Returns all information about the maze for save it in a file
	vector<char> getData();
	Cell* getStart();
	Cell& getEnd();
	Cell& getCell(int x, int y);
	void setsolve(vector<State<Cell>> vecre);
	vector<State<Cell>>& getAllPossibleMovesVector();
	// return possible moves for user
	string*getAllPossibleMoves();
	void setorder(int x, int y) {
		order.push_back(y*SH_SIZE + x);
	}
	Cell* getCellP(int x, int y);
	int getsizeOfMaze();
	bool operator==(const Maze2d &m) const;
	
	
};
