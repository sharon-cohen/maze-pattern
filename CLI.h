#pragma once
#include <iostream>
#include<fstream>
#include <map>
#include "HistoryMaze.h"
#include <string>
#include <vector>
#include "Observer.h"

using namespace std;
class Controller;
//interface
class view :public Observer {

public:
	view():Observer() {
	
	}
	
	virtual void start() = 0;
	virtual void inputuser(string &par) = 0;
	virtual shared_ptr<Maze2d> searchHistory(string name) = 0;
	
	
};



//Myview
class veiwCLI : public view {


private:
	Controller *_controller;
	istream &_in;
	ostream &_out;
	string _name;
	map<string, Maze2d> map_maze;
	HistoryMaze *MyHistory;
	
public:
	
	veiwCLI(ostream &out, istream &in);
	void displaySolve();
	void Setcontroller(Controller *mycontroller);
	void inputuser(string &par);
	shared_ptr<Maze2d> searchHistory(string name);
    void start();

	~veiwCLI() { delete MyHistory; }
	
};

