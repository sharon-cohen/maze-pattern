#include "MyMaze2dGenerator.h"
MyMaze2dGenerator::MyMaze2dGenerator() :MazeGenerator() {}
void MyMaze2dGenerator::ClearDS() {
	while (!back_track.empty()) { back_track.pop(); }
}
shared_ptr<Maze2d> MyMaze2dGenerator::generate() {
	ClearDS();
	//start store the time
	// Right at the beginning of the maze creation so that the result will be accurate
	auto t1 = std::chrono::high_resolution_clock::now();
	_maze->initMaze();
	_maze->SetStartPosition(GetRandomNum(), GetRandomNum());
	Cell *point = new Cell();
	point = _maze->getStart();
	_maze->setorder(point->x, point->y);


	int vistedCell = 1;

	int runloop = 1;
	while (vistedCell < _totalCells)
	{

		if (_maze->checkValid(point->x, point->y))
		{
			if ((point->y > 1) && !_maze->chekVisitedPoint(point->x, point->y - 2)) {    // If not visited
				_maze->Setvisited(point->x, point->y - 1);
				_maze->SetBreakWall(point->x, point->y, UP);  // Knock down wall
				back_track.push(*point);          // Push X for back track
				State<Cell>* newStatebefore = new State<Cell>();
				newStatebefore->setState(*point);
				point = _maze->getCellP(point->x, point->y - 2);                // Move to next cell
				_maze->Setvisited(point->x, point->y);
				_maze->SetBreakWall(point->x, point->y, DOWN);
				_maze->setorder(point->x, point->y);
				State<Cell>*newState = new State<Cell>();
				newState->setState(*point);
				newState->cameFrom(newStatebefore);
				_maze->allstate.push_back(*newState);
				vistedCell++;                 // Increase visitedCells counter

			}

			else {
				if ((point->x < SH_SIZE - 2) && !_maze->chekVisitedPoint(point->x + 2, point->y)) {    // If not visited
					_maze->Setvisited(point->x + 1, point->y);
					_maze->SetBreakWall(point->x, point->y, RIGHT);  // Knock down wall
					back_track.push(*point);          // Push X for back track
					State<Cell>* newStatebefore = new State<Cell>();
					newStatebefore->setState(*point);
					point = _maze->getCellP(point->x + 2, point->y);                 // Move to next cell
					_maze->Setvisited(point->x, point->y);
					_maze->SetBreakWall(point->x, point->y, LEFT);
					_maze->setorder(point->x, point->y);
					State<Cell>*newState = new State<Cell>();
					newState->setState(*point);
					newState->cameFrom(newStatebefore);
					_maze->allstate.push_back(*newState);
					vistedCell++;                 // Increase visitedCells counter
					runloop = 1;
				}

				else
				{
					if ((point->y < SH_SIZE - 2) && !_maze->chekVisitedPoint(point->x, point->y + 2)) {    // If not visited
						_maze->Setvisited(point->x, point->y + 1);
						_maze->SetBreakWall(point->x, point->y, DOWN);  // Knock down wall
						back_track.push(*point);          // Push X for back track
						State<Cell>* newStatebefore = new State<Cell>();
						newStatebefore->setState(*point);
						point = _maze->getCellP(point->x, point->y + 2);                   // Move to next cell
						_maze->Setvisited(point->x, point->y);
						_maze->SetBreakWall(point->x, point->y, UP);
						_maze->setorder(point->x, point->y);
						State<Cell>*newState = new State<Cell>();
						newState->setState(*point);
						newState->cameFrom(newStatebefore);
						_maze->allstate.push_back(*newState);
						vistedCell++;                 // Increase visitedCells counter

					}
					else {

						if ((point->x > 1) && !_maze->chekVisitedPoint(point->x - 2, point->y)) {    // If not visited
							_maze->Setvisited(point->x - 1, point->y);
							State<Cell>* newStatebefore = new State<Cell>();
							newStatebefore->setState(*point);
							point = _maze->getCellP(point->x - 2, point->y);               // Move to next cell
							_maze->Setvisited(point->x, point->y);
							_maze->SetBreakWall(point->x, point->y, RIGHT);
							_maze->setorder(point->x, point->y);
							State<Cell>*newState = new State<Cell>();
							newState->setState(*point);
							newState->cameFrom(newStatebefore);
							_maze->allstate.push_back(*newState);
							vistedCell++;                 // Increase visitedCells counter

						}

					}

				}
			}

		}

		else {
			//State<Cell>* newStatebefore = new State<Cell>();
			//ewStatebefore->setState(*point);
			*point = back_track.top();
			back_track.pop();
			_maze->setorder(point->x, point->y);
			//State<Cell>*newState = new State<Cell>();

			//newState->setState(*point);

			//newState->cameFrom(newStatebefore);
			//_maze->allstate.push_back(newState);


		}

		ClearScreen();
		//
		

	}




	_maze->SetEndPosition(point->x, point->y);
	system("cls");
	_maze->Redraw();
	
	//end store the time
	auto t2 = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
	_timeAlgo = to_string(duration);
	_timeAlgo += " milliseconds";
	cout << endl << "\a\t   Complete!" << endl;


	return _maze;



}