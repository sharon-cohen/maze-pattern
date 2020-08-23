#pragma once
//#include <queue>
//#include<vector>
//#include <map>

#include "Astar.h"
template <class T>
class AstarA :public Astar<T> {
protected:
	
public:
	AstarA() :Astar<T>() {};
	// call for the airline heuristic class 
	virtual void  setcul(Searchable<T> &s) {
		this->_clculator = s.getcul("AStarAirLine");
	}
	
};