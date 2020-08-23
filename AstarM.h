
#pragma once
//#include <queue>
//#include<vector>
//#include <map>

#include "Astar.h"
template <class T>
class AstarM :public Astar<T> {
protected:

public:
	AstarM() :Astar<T>() {};
	// call for the Manhattan heuristic class 
	virtual void  setcul(Searchable<T> &s) {
		this->_clculator = s.getcul("AStarMnhetten");
	}

};


