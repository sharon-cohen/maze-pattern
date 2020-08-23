#pragma once
#include <map>
#include "maze2d.h"
#include "solution.h"

//The solutions the program has previously calculated
class HashMap {
private:
	map<shared_ptr<Maze2d>,Solutiont> _HashMap;
public:
	HashMap();
	~HashMap() {}
	void setMazeSolution(shared_ptr<Maze2d>, Solutiont sol);
	bool checkexsistMazeSol(shared_ptr<Maze2d> maze);
	Solutiont getsol(shared_ptr<Maze2d> maze);
	
};