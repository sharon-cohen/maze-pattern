#pragma once
#include "Generetor.h"
#include <stack>
#include <conio.h>
#include <stdlib.h> 
#include <time.h>  
#include <thread>
#include <chrono>
#include <random>
#include <algorithm> 
// DFS generate maze class implementaion
class MyMaze2dGenerator :public MazeGenerator {
private:
	stack <Cell> back_track;
	
public:
	MyMaze2dGenerator();
	virtual void ClearDS();
	virtual  shared_ptr<Maze2d> generate();
};