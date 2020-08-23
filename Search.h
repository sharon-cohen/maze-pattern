#pragma once
#include <Windows.h>
#include <queue>
#include "searchable.h"
#include "solution.h"
// interface 
template<class T>
class Searcher
{
public:

	Searcher() {}
	virtual vector<State<T>> search(Searchable<T>& s) = 0;
	virtual int getNumberOfNodesEvaluated() = 0;

};





