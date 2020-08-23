#pragma once
#include "command.h"
#include "maze2d.h"
//command for calculate the place that the maze occupies in memory
class CommandSizeMazeMemory :public Command {
private:
	shared_ptr<Maze2d> _maze;
	

public:
	CommandSizeMazeMemory(Model * model, shared_ptr<Maze2d> maze) : Command(model), _maze(maze) {}
		
	
	~CommandSizeMazeMemory() {}
	
	virtual int executeSizeMemory() {

		return _model->calculatSizeMemory(_maze);
	}
	virtual void ex() {}

};