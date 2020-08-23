#pragma once
#include "command.h"
#include "Model.h"
#include <string>

//comand for load maze from file
class commandLoad :public Command {
private:
	string _namefile;
	
public:
	commandLoad(Model * model, string namefile) :Command(model) {

		_namefile = namefile;

	}
	virtual Maze2d* executeLoadMaze() {
		return _model->laodmaze(_namefile);
	}
	virtual void ex() {}

	
};