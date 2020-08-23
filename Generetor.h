#pragma once
#include "Maze2dGenerator.h"
#include <Windows.h>
//abstract maze generator contain all the common methods for create maze
class MazeGenerator :public Maze2dGenerator {
protected:
	int _totalCells; 
	
public:
	MazeGenerator():Maze2dGenerator(){ _totalCells= ((SH_SIZE - 1) / 2)*((SH_SIZE - 1) / 2);}
	virtual  shared_ptr<Maze2d> generate() =0;
	virtual string measureAlgorithmTime() { return _timeAlgo; }
	virtual void ClearDS() = 0;
	// every generator need for start possition
	int GetRandomNum() {int ran= ((2 * rand()) + 1) % (SH_SIZE - 1);
		return ran;}
	void ClearScreen(){
		HANDLE hOut;
		COORD Position;
		hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		Position.X = 0;
		Position.Y = 0;
		SetConsoleCursorPosition(hOut, Position);
	}
	
	
	shared_ptr<Maze2d> getResult() { return _maze; }
};