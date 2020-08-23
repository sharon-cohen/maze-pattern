#pragma once
#include "command.h"
#include "maze2d.h"
#include "solution.h"
// solve maze 
class CommandSolve :public Command {
private:
	shared_ptr<Maze2d> _maze;
	string _nameAlgotitham;
	string _nameMaze;
	
public:
	CommandSolve(Model * model, shared_ptr<Maze2d> maze,string nameAlgotitham, string nameMaze) : Command(model), _maze(maze) {
		_nameAlgotitham = nameAlgotitham;
		_nameMaze = nameMaze;
	}
	
	~CommandSolve() {}
	
	virtual Solutiont executeSolve() {
		
		
		return _model->solve(_maze, _nameAlgotitham, _nameMaze);
	}
	
	virtual void ex() {}
};