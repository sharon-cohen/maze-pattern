

#include <windows.h>
#include <conio.h>
#include <stack>
#include <fstream>
#include <thread>
#include <chrono>
#include "SimpleMaze2dGenerator.h"
#include "MyMaze2dGenerator.h"
#include <chrono>
#include "maze2d.h"
#include "MazeSearcable.h"
#include "AstarM.h"
#include "MazeCompression.h"
#include<fstream>
#include "CLI.h"
#include <iostream>
#include <sstream>
#include "Model.h"
#include "Observer.h"
#include <experimental/filesystem> 
#include <algorithm>    
#include <vector> 
#include <dirent.h>
#include "solution.h"
#include <sys/types.h>
#include "Model.h"
#include "Mycontrollerh.h"
#include "Demo.h"

using namespace std;


//#include "Cell.h"
//#include "State.h"
//#include "comp.h"
//#include <map>
//using namespace std;

/*
template <class T>
class ClculateCost {
public:
	ClculateCost() {};
	//virtual void printtry() { cout <<1; }

	//TODO
	virtual double init(State<T> s) = 0;
	virtual double claculateCost(State<T> s, double cost) = 0;
	//virtual double init(State<T> s) { return 1; }
	//virtual double claculateCost(State<T> s, double cost) { return 1; }
};
template <class P>
class claculatoreMaze :public ClculateCost<P> {
public:
	claculatoreMaze() :ClculateCost<P>() {}
	virtual double init(State<P> s) {
		return s.getcost();
	}
	//virtual void printtry() { cout << 2; }
	virtual double claculateCost(State<P> s, double cost) {
		double Mycost = s.getcost();
		return Mycost + cost;
	}
};
template <class W>
class ClculateCostAstarForMaze :public claculatoreMaze<W> {

protected:
	
	W _end;
public:

	ClculateCostAstarForMaze(W end) : claculatoreMaze<W>(), _end(end) {
		_end = end;
	}
};
template <class Q>
class ClculateCostAstarForMazeManhetten :public ClculateCostAstarForMaze<Q> {

public:
	ClculateCostAstarForMazeManhetten(const Q& end) : ClculateCostAstarForMaze<Q>(end) {}
	//virtual void printtry() { cout << 3; }
	virtual double init(State<Q> s) {


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
*/
int main(){
	
	srand((unsigned)time(0));
	//State<Cell> mos;
	//Cell d;
	//map<string, ClculateCost<Cell>*> m_cul;
	//ClculateCostAstarForMazeManhetten<Cell> mosh(d);
	//ClculateCostAstarForMazeManhetten<Cell> mosh(d);
	//State<Cell> mos;
	//Cell d;
	
	try {
		veiwCLI *ob = new veiwCLI(cout, cin);
		MyModel<Cell> * myModel = new MyModel<Cell>(ob);
		MyController *mycontroller = new MyController(ob, myModel);
		ob->start();
	}
	catch (const string mass) {
		cout << mass << endl;
	}
	
	
}




