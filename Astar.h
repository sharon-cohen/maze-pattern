#pragma once
//#include <queue>
//#include<vector>
//#include <map>
#include "MazeSearcable.h"
#include "BFS.h"

//Abstract class search method search is shared by add type of AStar 
template <class T>
class Astar :public BFSAstar<T> {
protected:
	
public:
	Astar() :BFSAstar<T>() {};
	virtual void  setcul(Searchable<T> &s) = 0;
	virtual vector<State<T>> search(Searchable<T>& s) {
		setcul(s);
		this->allvertex = s.getAllvertex();
		//init cost for every vertex according  heuristic func
		for (size_t i = 0; i < this->allvertex.size(); i++) {
			double co = this->_clculator->init(this->allvertex[i]);
			this->allvertex[i].setcost(this->_clculator->init(this->allvertex[i]));
		}
		vector<State<T>> sol;
		vector<State<T>*> possibleMove;
		vector<State<T>> visitedState;
		State<T> start = s.getStartState();
		State<T> end = s.getGoalState();
		State<T> v;
		this->my_queue.push(s.getStartState());
		while (!(v == end) && !this->my_queue.empty()) {
			double cost = 0;
			//pop min vertex
			v = this->my_queue.top();
			//save min vertex cost;
			cost = v.getcost();
			this->my_queue.pop();
			sol.push_back(v);
			// get all Neighbors of Vertex
			possibleMove = s.getAllPossibleMoves(v, this->allvertex);
			for (size_t i = 0; i < possibleMove.size(); i++) {
				//The algorithm checks that  have not visited the vertex
				if (std::find(visitedState.begin(), visitedState.end(), *possibleMove[i]) == visitedState.end()) {
					//push vector contain visitedState
					visitedState.push_back(*possibleMove[i]);
					//push priority_queue
					this->my_queue.push(*possibleMove[i]);
				}
			}
		}
		return sol;
	}
	//testing
	virtual void printQueue(priority_queue< State<T>> q)
	{
		//printing content of queue 
		while (!q.empty()) {
			State<T> v = q.top();
			v.pritst();
			cout << endl;
			cout << v.getcost();
			cout << endl;
			q.pop();
		}
		cout << endl;
	}
};