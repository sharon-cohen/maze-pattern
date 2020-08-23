#pragma once
#include "command.h"
#include "Model.h"
#include <string>

// command save maze in file
class CommandSave :public Command {
private:
	string _fileName;
	
	shared_ptr<Maze2d> _maze;
public:
	CommandSave(Model * model, shared_ptr<Maze2d> maze,string fileName) :Command(model),_maze(maze) {

		_fileName = fileName;

	}
	//~CommandSave()
	//{
		//delete _maze;
	//}
	void execute() {
		_model->savemaze(_maze, _fileName);

	}
	virtual void ex() {}
};