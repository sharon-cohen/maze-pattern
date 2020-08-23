#pragma once
#include "searchable.h"
#include <math.h> 
#include <map>

// A class that makes a maze class searchable
class MazeSearchable:public Searchable<Cell>
{
private:
	claculatoreMaze<Cell>* culMaze;
	Maze2d _maze;
	map<string, ClculateCost<Cell>*> m_cul;
public:
	
	MazeSearchable(Maze2d& maze);
	
	~MazeSearchable() { delete culMaze; }
	virtual State<Cell> getStartState() {return State<Cell>(*_maze.getStart());}
	virtual State<Cell> getGoalState() {  return State<Cell> (_maze.getEnd());}
	virtual State<Cell> getState(int x, int y) { State<Cell> s(_maze.getCell(x, y)); return s; }
	virtual vector<State<Cell>*> getAllPossibleMoves(State<Cell> sta, vector<State<Cell>> &list);
	//return to search classes the type calculator class for her
	virtual ClculateCost<Cell>* getcul(string command);

};
