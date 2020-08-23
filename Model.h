
#pragma once
#pragma warning( disable : 4290 )
#include <string>
#include "MyMaze2dGenerator.h"
#include "MazeCompression.h"
#include "Observable.h"
#include <chrono>
#include <thread>
#include <dirent.h>
#include <sys/types.h>
#include "SimpleMaze2dGenerator.h"
#include "solution.h"
#include "MazeSearcable.h"
#include "AstarM.h"
#include "HashMap.h"
#include "AstarA.h"
#include <memory>
class Controller;

//interface
class Model {
public:
	
	Model() {}
	virtual vector<string>path(const char * path) throw(std::string) = 0;
	virtual shared_ptr<Maze2d> generate(string type) throw(std::string) = 0;
	virtual void  display(shared_ptr<Maze2d> maze) = 0;
	virtual void savemaze(shared_ptr<Maze2d> maze,string namefile) = 0;
	virtual Maze2d* laodmaze(string nameMaze) = 0;
	virtual Solutiont solve(shared_ptr<Maze2d> maze, string nameAlgoritham, string nameMaze) throw(std::string) = 0;
	virtual int calculatSizeMemory(shared_ptr<Maze2d> maze) = 0;
	virtual size_t calculatSizeFile(shared_ptr<Maze2d> maze) = 0;
	virtual vector<size_t> compermemory(vector<Maze2d*>maze) = 0;
};

