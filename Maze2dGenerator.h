#pragma once
#include <iostream>
#include <string>
#include <chrono>
#include "maze2d.h"
#include <memory>
using namespace std;
	
//interface
class Maze2dGenerator {
	protected:
	    shared_ptr<Maze2d> _maze;
		string _timeAlgo;

	public:

		Maze2dGenerator() :_maze(new Maze2d()) {
		}
	
		~Maze2dGenerator() { }
		virtual shared_ptr<Maze2d> generate() = 0;
		virtual string measureAlgorithmTime() = 0;

	};