

#pragma once
#include "Generetor.h"
#include <stack>
#include <conio.h>
#include <stdlib.h> 
#include <time.h>  
#include <thread>
#include <chrono>
#include <random>

// implementaion of random maze generator
class SimpleMaze2dGenerator :public MazeGenerator {
private:
	vector<Cell> vecPoint;
	

public:
	SimpleMaze2dGenerator();
	//Clears the data structure it uses to create more mazees later
	virtual void ClearDS();
	//Calculate the next step
	virtual  MOVE nexMove();
	virtual  shared_ptr<Maze2d> generate();
};
