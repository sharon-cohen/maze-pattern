#pragma once
#include "command.h"
#include "maze2d.h"
// commad for display the maze
class CommandDisplay :public Command {
private:
	shared_ptr<Maze2d> _maze;
public:
	
	CommandDisplay(Model * model, shared_ptr<Maze2d> maze) : Command(model),_maze(maze) {
	}
	
	
	~CommandDisplay() {}
	
	void execute() {
	
		_model->display(_maze);
	}
	virtual void ex() {}
};
