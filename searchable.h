#pragma once

#include <vector>
#include "State.h"
#include "comp.h"

//abstract can get different kinds of state 
template<class T>
class Searchable
{
protected:
	vector<State<T>> allvertex;
public:
	virtual State<T> getStartState() = 0;
	virtual State<T> getGoalState() = 0;
	virtual State<T> getState(int x, int y) = 0;
	virtual std::vector<State<T>> getAllvertex() { return allvertex; };
	virtual vector<State<Cell>*> getAllPossibleMoves(State<Cell> sta, vector<State<Cell>> &list) = 0;
	virtual  ClculateCost<T>* getcul(string command) = 0;

};