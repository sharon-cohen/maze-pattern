#pragma once
#include "command.h"
#include "Model.h"
#include <string>

//create maze command
class createMazecommand :public Command {
private:
	//contain method for maze generator
	string _type;

public:
	createMazecommand(Model * model, string type) :Command(model) {

		_type = type;

	}
	virtual shared_ptr<Maze2d>executeNewMaze() {
		return _model->generate(_type);
	}


	virtual void ex() {


	}
};