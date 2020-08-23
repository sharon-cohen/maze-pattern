#pragma once
#pragma warning( disable : 4290 )
#include <iomanip>
#include <map>
#include "maze2d.h"
#include <string>
#include <vector>
#include "solution.h"
#include "SimpleMaze2dGenerator.h"

// history maze and solution for any user(view)
class HistoryMaze {
private:
	map<string, shared_ptr<Maze2d>> hismaze;
	map<string, Solutiont> hissol;
public:
	HistoryMaze();
	shared_ptr<Maze2d> getMaze(string name)throw(std::string);
	void setsol(Solutiont sol);
	Solutiont& getsol(string name)throw(std::string);
	// function get pointer type mazeFor a maze that comes from a file
	void setMaze(Maze2d* newmaze, string name)throw(std::string);
	// function get shared_ptr type maze
	void setMaze(shared_ptr<Maze2d> newmaze, string name)throw(std::string);
	//vector<Maze2d*>getallmaze();
};