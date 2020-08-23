#pragma once
#include "command.h"
#include "maze2d.h"

// Calculate the place that the maze occupies in file after compression
class CommandSizeMazeFile :public Command {
private:
	shared_ptr<Maze2d> _maze;


public:
	CommandSizeMazeFile(Model * model, shared_ptr<Maze2d> maze) : Command(model), _maze(maze) {}

	
	~CommandSizeMazeFile() {}

	virtual size_t executeSizeFile() {

		return _model->calculatSizeFile(_maze);
	}
	virtual void ex() {}

};
