#pragma once
#include <queue>
#include <iostream> 
#include "commonsearch.h"
#include<vector>
#include <map>
#include <iomanip>
#include <cstdlib>

template <class T>

class BFSAstar :public CommonSearch<T> {
protected:
	ClculateCost<T>* _clculator;
	vector<State<T>> allvertex;
	priority_queue< State<T>> my_queue;
public:
	BFSAstar() :CommonSearch<T>(){
	}
	
	
	~BFSAstar() {
		delete _clculator;
	}

	virtual void  setcul(Searchable<T>& s) {
		_clculator = s.getcul("BFS");
	}
	virtual vector<State<T>> search(Searchable<T>& s) {
		setcul(s);
		allvertex = s.getAllvertex();
		
		//init the cost for evert vertex
		for (size_t i = 0; i < allvertex.size(); i++) {
			allvertex[i].setcost(_clculator->init(allvertex[i].getState()));
		}
		vector<State<T>> sol;
		vector<State<T>*> possibleMove;
		vector<State<T>> visitedState;
		State<T> start = s.getStartState();
		State<T> end = s.getGoalState();
		State<T> v;
		my_queue.push(s.getStartState());
		//until the priority_queueis empty
		while (!(v==end) && !my_queue.empty()){
			double cost = 0;
			// get min vertex
			v = my_queue.top();
			//get cost min vertex
			cost = v.getcost();
			my_queue.pop();
			sol.push_back(v);
			possibleMove = s.getAllPossibleMoves(v, allvertex);
			for (size_t i = 0; i < possibleMove.size(); i++) {
				if (std::find(visitedState.begin(), visitedState.end(), *possibleMove[i]) == visitedState.end()){
					visitedState.push_back(*possibleMove[i]);
					possibleMove[i]->setcost(_clculator->claculateCost(*possibleMove[i], cost));
					my_queue.push(*possibleMove[i]);
				}
			}
		}
		
		return sol;
	}
	virtual void printQueue(priority_queue< State<T>> q)
	{
		//printing content of queue 
		while (!q.empty()) {
			State<T> v = q.top();
				
			q.pop();
		}
		cout << endl;
	}

};

