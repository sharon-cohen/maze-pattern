#pragma once
#pragma warning( disable : 4290 )
#include <iostream>
#include "maze2d.h"
#include <vector>
#include<fstream>
#include <string>
#include<cctype>
//Compression maze
class MazeCompression {
private:
	vector<int>com;	
	vector<char> vecMaze;
	vector<char> re;
	int startx;
	int starty;
	int endx;
	int endy;
	size_t _size;
public:
	MazeCompression(const vector<char> &vec);
	MazeCompression();
	//Checks if the file name is correct and contain in the end ".bin"
	bool checkValidNameFile(string namefile);
	//method Compression maze information Recognizes repetitive characters
	MazeCompression(const vector<char> &vec, string namefile);
	void compress();
	//save maze in binary file
	void save(string namefile) throw(string);
	// get information about maze from binary file
	vector<char> read(string namefile)throw(string);
	size_t SizeCompression();
};