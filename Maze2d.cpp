#include "maze2d.h"
Maze2d::Maze2d(Maze2d & maze) {
	
	for (int i = 0; i < SH_SIZE; i++) {
		for (int j = 0; j < SH_SIZE; j++) {
			Level[i][j] = maze.Level[i][j];

		}

	}
	_start = new Cell();
	*_start = *maze._start;
	_end = new Cell();
	*_end = *maze._end;
	for (auto & element : maze.allstate) {
		allstate.push_back(element);

	}
}
Maze2d::Maze2d() {}
Maze2d::Maze2d(const vector<char> vec) {
	vector<State<Cell>> temp;
	initMaze();
	size_t p = 0;
	_start = new Cell();
	_end = new Cell();
	
	for (int i = 0; i < SH_SIZE; i++) {
		for (int j = 0; j < SH_SIZE; j++) {

			Level[i][j].display = vec[p];
			if (Level[i][j].display == 'S') {
				_start = &Level[i][j];
			}
			if (Level[i][j].display == 'E') {
				_end = &Level[i][j];
			}
			p++;


		}

	}


	

	p++;
	
	for (int i = 0; i < SH_SIZE; i++) {
		for (int j = 0; j < SH_SIZE; j++) {
			if (i % 2 != 0 && j % 2 != 0) {
				if (Level[i][j].display == ' ' || Level[i][j].display == 'E') {
					
					State<Cell>* newState = new State<Cell>();
					
					if (p<vec.size()) {
						newState->setState(Level[i][j]);

						if (vec[p] == 'U') {
							newState->SetbeforT(Level[i - 2][j]);
							p++;
						}
						
						else {
						
							if (vec[p] == 'D') {
								newState->SetbeforT(Level[i + 2][j]);
								
								p++;
							}
							
							else {
								if (vec[p] == 'L') {
									newState->SetbeforT(Level[i][j - 2]);
									p++;
								}
								
								else {
									if (vec[p] == 'R') {
										newState->SetbeforT(Level[i][j + 2]);
										p++;
									}
								}
								
							}
							
						}
						

						allstate.push_back(*newState);
						
					}
				}

			}
		}
	}
	
	
	
	
}
Maze2d& Maze2d::operator=(const Maze2d& m) {
	
	for (int i = 0; i < SH_SIZE; i++)
	{
		for (int j = 0; j < SH_SIZE; j++) {
			Level[i][j] = m.Level[i][j];
		}
	}
	_start = m._start;
	_end = m._end;
	for (size_t i = 0; i < m.allstate.size(); i++) {
		allstate.push_back(m.allstate[i]);
	}
	return *this;
}
void Maze2d::Redraw() {
	for (int i = 0; i < SH_SIZE; i++) {
		cout << endl;
		
		for (int j = 0; j < SH_SIZE; j++) {
			cout << Level[i][j].display<<" ";
			
		}
	}
}
//Checks if one of the neighbors of a particular position is visitable
bool Maze2d::checkValid(int NextX, int Nexty) {
	if (((Level[Nexty - 2][NextX].visited == false) && (Level[Nexty][NextX].top_wall == true && Level[Nexty - 2][NextX].bot_wall == true)) ||
		((Level[Nexty + 2][NextX].visited == false) && (Level[Nexty][NextX].bot_wall == true && Level[Nexty + 2][NextX].top_wall == true)) ||
		((Level[Nexty][NextX - 2].visited == false) && (Level[Nexty][NextX].left_wall == true && Level[Nexty][NextX - 2].right_wall == true)) ||
		((Level[Nexty][NextX + 2].visited == false) && (Level[Nexty][NextX].right_wall == true && Level[Nexty][NextX + 2].left_wall == true)))
	{
		return true;
	}
	else {
		return false;
	}
}
void Maze2d::setpossibleState(Cell** poss) {
	for (int i = 0; i < SH_SIZE; i++) {
		for (int j = 0; j < SH_SIZE; j++) {
			Level[i][j] = poss[i][j];
		}
	}

}
Cell** Maze2d::getpossibleState() {
	Cell** a = new Cell*[SH_SIZE];
	for (int i = 0; i < SH_SIZE; ++i)
		a[i] = new Cell[SH_SIZE];

	for (int i = 0; i < SH_SIZE; i++)
	{
		for (int j = 0; j < SH_SIZE; j++)
		{
			a[i][j] = Level[i][j];
		}
	}
	return a;

}
void Maze2d::Setdisplay(int x, int y, string str) {
	if (str == "start") {
		Level[y][x].display = 'S';
	}
	else {
		Level[y][x].display = 'E';
		Level[y][x].visited = true;
	}
}
void Maze2d::SetStartPosition(int x, int y) {
	
	Level[y][x].display = 'S';                      // Set S as the start cell
	//The starting point is initialized to be visited 
	Level[y][x].visited = true;
	_start = &Level[y][x];
	Level[y][x].ordervisit = 1;
}
bool Maze2d::chekVisitedPoint(int x, int y) {
	if (Level[y][x].visited == true)
		return true;
	else
		return false;
}
void Maze2d::Setvisited(int x, int y) { Level[y][x].visited = true;  Level[y][x].display = ' '; }
//Break some Wall At the border with his neighbors
void Maze2d::SetBreakWall(int x, int y, MOVE wall) {
	if (wall == UP)
		Level[y][x].top_wall = false;
	if (wall == DOWN)
		Level[y][x].bot_wall = false;
	if (wall == LEFT)
		Level[y][x].left_wall = false;
	if (wall == RIGHT)
		Level[y][x].right_wall = false;
}
void Maze2d::SetEndPosition(int x, int y) {
	Level[y][x].display = 'E';                      // Set S as the start cell
	_end = &Level[y][x];

}
void Maze2d::initMaze() {
	for (int i = 0; i < SH_SIZE; i++) {
		for (int j = 0; j < SH_SIZE; j++) {
			Level[i][j].x = j;
			Level[i][j].y = i;
			Level[i][j].display = '*';
			Level[i][j].visited = false;
			Level[i][j].top_wall = true;
			Level[i][j].bot_wall = true;
			Level[i][j].left_wall = true;
			Level[i][j].right_wall = true;
			

		}
	}
	//init The boundaries of the maze
	for (int i = 1; i < SH_SIZE - 1; i++) {
		for (int j = 1; j < SH_SIZE - 1; j++) {
			// Border Cells have fewer accessible walls
			Level[1][j].top_wall = false;
			Level[SH_SIZE - 2][j].bot_wall = false;
			Level[i][1].left_wall = false;
			Level[i][SH_SIZE - 2].right_wall = false;
		}
	}
	_start = new Cell();
	_end = new Cell();

}
//set display to be part for the sulotion
void Maze2d::displaySolve(int x, int y) {
	Level[y][x].display = '^';

}
vector<char> Maze2d::getData() {
	vector<char> ma;
	vector<char> comefrom;
	
	comefrom.push_back('P');
	for (int i = 0; i < SH_SIZE; i++) {
		for (int j = 0; j < SH_SIZE; j++) {
			ma.push_back(Level[i][j].display);

		}

	}
	//set Direction of the construction of the maze on the vector
	// Necessary information for the maze
	for (int i = 0; i < SH_SIZE; i++) {
		for (int j = 0; j < SH_SIZE; j++) {
			if (i % 2 != 0 && j % 2 != 0 && Level[i][j].display!='S') {
				if (Level[i][j].display == ' ' || Level[i][j].display == 'E') {
					int flag = 0;
					for ( size_t p = 0; p < allstate.size(); p++) {
					//cout << allstate[p].getState().x << "," << allstate[p].getState().y << ":"<< Level[i][j].x<<","<<Level[i][j].y<<" ";
						if (allstate[p].getState().x ==j && allstate[p].getState().y == i) {
							Cell before = allstate[p].getTbefore();
							flag = 1;
							if (before.x + 2 == j) {
								comefrom.push_back('L');
							}
							if (before.x - 2 == j) {
								comefrom.push_back('R');
							}
							if (before.y - 2 == i) {
								comefrom.push_back('D');
							}
							if (before.y + 2 == i) {
								comefrom.push_back('U');
							}
						
						}
						
						
					}
					
				
				}


			}
		
		}
		
	}
	
	
	for (size_t i = 0; i < comefrom.size(); i++) {
	
		ma.push_back(comefrom[i]);
	}
	
	return ma;
}
Cell* Maze2d::getStart() { return _start; }
Cell& Maze2d::getEnd() { return *_end; }
Cell& Maze2d::getCell(int x, int y) {
	return Level[y][x];
}
// for display the solution of the maze
void Maze2d::setsolve(vector<State<Cell>> vecre) {
	for (auto & element : vecre) {
		if (Level[element.getState().y][element.getState().x].display != 'E'&& Level[element.getState().y][element.getState().x].display != 'S')
			Level[element.getState().y][element.getState().x].display = '^';

	}
	Redraw();
}
vector<State<Cell>>& Maze2d::getAllPossibleMovesVector() {
	return allstate;
}
string* Maze2d::getAllPossibleMoves(){
	size_t num= allstate.size();
	
	string str = "";
	for (size_t i =0; i < allstate.size(); i++) {
		str =str+ " "+ allstate[i].getstringstate();

	}
	
	string* moves = new string(str);
	
	return  moves;
}
Cell* Maze2d::getCellP(int x, int y) {
	return &Level[y][x];
}
int Maze2d::getsizeOfMaze() {
	int size = 0;
	size = SH_SIZE * SH_SIZE* (14);
	for (auto & element : allstate) {
		size = size + element.calculateSize();
	}
	return size;

}
bool Maze2d::operator==(const Maze2d &m) const {

	for (int i = 0; i < SH_SIZE; i++) {
		for (int j = 0; j < SH_SIZE; j++) {
	
			if (Level[i][j] != m.Level[i][j] ||Level[i][j].display != m.Level[i][j].display) {
				
				
			return false;
			}

		}
	}
	return true;
}
