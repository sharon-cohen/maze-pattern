
#include "State.h"
#include "maze2d.h"
template <typename T>
//All calculation classes of heuristic functions

//abstract 
class ClculateCost {
public:
	ClculateCost() {};
	
	virtual double init(State<T> s) = 0;
	virtual double claculateCost(State<T> s, double cost) = 0;
	
};
//TODO
//for BFS
template <typename T>
class claculatoreMaze :public ClculateCost<T> {
public:
	claculatoreMaze() :ClculateCost<T>() {}
	virtual double init(State<T> s) {
		return s.getcost();
	}
	//virtual void printtry() { cout << 2; }
	virtual double claculateCost(State<T> s, double cost) {
		double Mycost = s.getcost();
		return Mycost + cost;
	}
};
//ABSTRACT calculation classes for every Astar function most to have
template <typename T>
class ClculateCostAstarForMaze :public claculatoreMaze<T> {

protected:
	T _end;
public:

	ClculateCostAstarForMaze(T end) : claculatoreMaze<T>(),_end(end) {
		_end = end;
	}
};
template <typename T>

//Manhetten
class ClculateCostAstarForMazeManhetten :public ClculateCostAstarForMaze<T> {
public:
	ClculateCostAstarForMazeManhetten(T end) : ClculateCostAstarForMaze<T>(end) {}
	
	virtual double init(State<T> s) {
		double disx = this->_end.x - s.getState().x;
		if (disx < 0) {
			disx = -disx;
		}
		double disy = this->_end.y - s.getState().y;
		if (disy < 0) {
			disy = -disy;
		}
		return disx + disy;
	}
};

//AirLine
template <typename T>
class ClculateCostAstarForMazeAirline :public ClculateCostAstarForMaze<T> {
public:
	ClculateCostAstarForMazeAirline(T end) : ClculateCostAstarForMaze<T>(end) {}
	virtual double init(State<T> s) {
		double step = 0;
		double disx = this->_end.x - s.getState().x;
		if (disx < 0) {
			disx = -disx;
		}
		double disy = this->_end.y - s.getState().y;
		if (disy < 0) {
			disy = -disy;
		}
		step = disy * disy + disx * disx;
		step = sqrt(step);
		return step;
	}


};
