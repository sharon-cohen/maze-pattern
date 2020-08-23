
#pragma once
#include "command.h"
#include "maze2d.h"
class CommandComparMemory :public Command {
private:
	vector<Maze2d*> _maze;


public:
	
	
	CommandComparMemory(Model * model, vector<Maze2d*> maze) : Command(model) {
		for (size_t i = 0; i < maze.size(); i++) {
			_maze.push_back(maze[i]);
		}
	}
	virtual vector<size_t> executeSizeFile() {

		return _model->compermemory(_maze);
	}
	virtual void ex() {}

};
