#pragma warning( disable : 4290 )
#include "MazeCompression.h"
MazeCompression::MazeCompression(const vector<char> &vec) {
	vecMaze = vec;
	compress();
}
MazeCompression::MazeCompression() {
	startx = -1;
	starty = -1;
	endx = -1;
	endy = -1;
}
MazeCompression::MazeCompression(const vector<char> &vec, string namefile) {
	
	startx = -1;
	starty = -1;
	endx = -1;
	endy = -1;
	vecMaze = vec;
	compress();
	save(namefile);
}
void MazeCompression::compress() {
	for (size_t i = 0; i < vecMaze.size(); i++) {
		if (vecMaze[i] == 'S') {
			starty = i / SH_SIZE;
			startx = i % SH_SIZE;
		}
		if (vecMaze[i] == 'E') {
			endy = i / SH_SIZE;
			endx = i % SH_SIZE;
		}

	}

	com.push_back(-1);

	int countwall = 0;
	int countpath = 0;
	size_t i = 0;
	//Checks repetitive characters and compresses them
	for (; i < vecMaze.size() && vecMaze[i] != 'P'; i++) {
		if (vecMaze[i] == '*') {
			countwall++;
			if (countpath != 0) {

				com.push_back(countpath);
				countpath = 0;
			}
		}

		if (vecMaze[i] == ' ' || vecMaze[i] == 'E' || vecMaze[i] == 'S' || vecMaze[i] == '^') {

			countpath++;
			if (countwall != 0) {

				com.push_back(countwall);
				countwall = 0;
			}
		}



	}

	if (countwall != 0) {
		com.push_back(countwall);
	}
	_size = com.size();
	for (size_t j = i; j < vecMaze.size(); j++) {
		com.push_back(vecMaze[j]);
	}


}
bool MazeCompression::checkValidNameFile(string namefile) {
	string str1 = ".bin";
	size_t found = namefile.find(str1);
	if (found != string::npos) {
		if (found != namefile.size() - 4) {
			return false;
		}
		else return true;
	}
	else	
		return false;
}
void MazeCompression::save(string namefile)throw(string) {

	if (checkValidNameFile(namefile)) {
		ofstream out(namefile, ios::binary | ios::trunc);
		out.write((const char*)(&startx), sizeof(startx));
		out.write((const char*)(&starty), sizeof(starty));
		out.write((const char*)(&endx), sizeof(endx));
		out.write((const char*)(&endy), sizeof(endy));
		size_t i = 0;
		while (i < com.size())
		{
			out.write((const char*)(&com[i]), sizeof(com[i]));
			i++;
		}
	
	}
	else
	{
		string error = "Invalid file name. The file should be of bin type for example name.bin";
		throw error;
	}

}
vector<char> MazeCompression::read(string namefile)throw (string) {

	if (checkValidNameFile(namefile)) {
		ifstream in(namefile, std::ios::binary);
		if (in.is_open()) {
			in.read((char*)&startx, sizeof(startx));
			in.read((char*)&starty, sizeof(starty));
			in.read((char*)&endx, sizeof(endx));
			in.read((char*)&endy, sizeof(endy));

			std::vector<int> numbers((SH_SIZE*SH_SIZE)+ (SH_SIZE*SH_SIZE/4));
			in.read((char*)&numbers[0], numbers.size() * sizeof(numbers[0]));

			com.clear();
			com = numbers;
			int flag = 0;
			for (size_t i = 1; i < com.size() && com[i] != 0; i++) {

				if (com[i]==80)
				{
					re.push_back('P');
					flag = 1;

				}
				
				if (flag == 0) {
					if (i % 2 != 0) {
						for (int j = 0; j < com[i]; j++) {
							re.push_back('*');
						}
					}
					else {
						for (int P = 0; P < com[i]; P++) {
							re.push_back(' ');
						}

					}
				}
				else {
					if(com[i]==85)
					re.push_back('U');
					if (com[i] == 68)
					re.push_back('D');
					if (com[i] == 76)
						re.push_back('L');
					if (com[i] ==82)
						re.push_back('R');
					
				}
			
			}

			int start = starty * SH_SIZE + startx;
			re[start] = 'S';
			int end = endy * SH_SIZE + endx;
			re[end] = 'E';

			return re;
		}
		else
		{
			string error = "This file was not found in this directory ";
			throw error;
		}
	}
	else {
		string error = "Invalid file name. The file should be of bin type for example: name.bin ";
		throw error;
	}
}
size_t MazeCompression::SizeCompression() {
	return com.size();
}