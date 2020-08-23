#pragma once
#include"Search.h"

template<class T>
class CommonSearch  :public Searcher<T> {
protected:
	int m_evaluatedNodes;
	
public:
	CommonSearch() :Searcher<T>(), m_evaluatedNodes(0) {}

	//Abstraction
public:
	
	virtual int getNumberOfNodesEvaluated() { return m_evaluatedNodes; }
	void ClearScreen()
	{
		HANDLE hOut;
		COORD Position;
		hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		Position.X = 0;
		Position.Y = 0;
		SetConsoleCursorPosition(hOut, Position);
	}
	virtual void printQueue(priority_queue< State<T>> q) = 0;
};