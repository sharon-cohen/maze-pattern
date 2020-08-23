#include "SimpleMaze2dGenerator.h"

SimpleMaze2dGenerator::SimpleMaze2dGenerator() :MazeGenerator() {

}


 void SimpleMaze2dGenerator::ClearDS() {
	vecPoint.clear();
}
  MOVE SimpleMaze2dGenerator::nexMove() {
	int random = rand() % 4 + 1;

	if (random == 1) {
		return DOWN;
	}
	if (random == 2) {
		return UP;
	}
	if (random == 3) {
		return LEFT;
	}
	else {
		return RIGHT;
	}
}
  shared_ptr<Maze2d> SimpleMaze2dGenerator::generate() {
	auto t1 = std::chrono::high_resolution_clock::now();
	ClearDS();
	_maze->initMaze();
	_maze->SetStartPosition(GetRandomNum(), GetRandomNum());
	vecPoint.push_back(*_maze->getStart());
	int vistedCell = 1;
	MOVE nextMove;
	Cell* randomPoint;
	randomPoint = _maze->getStart();

	while (vistedCell < _totalCells)
	{
		if (_maze->checkValid(randomPoint->x, randomPoint->y))
		{

			nextMove = nexMove();     // Pick a random wall 1-4 to knock down

			if (nextMove == UP && (randomPoint->y > 1)) {
				if (!_maze->chekVisitedPoint(randomPoint->x, randomPoint->y - 2)) {    // If not visited


					State<Cell>* newStatebefore = new State<Cell>();
					newStatebefore->setState(*randomPoint);
					_maze->Setvisited(randomPoint->x, randomPoint->y - 1);
					_maze->SetBreakWall(randomPoint->x, randomPoint->y, UP);  // Knock down wall
					Cell newMove = _maze->getCell(randomPoint->x, randomPoint->y - 2);

					vecPoint.push_back(newMove);
					randomPoint = _maze->getCellP(randomPoint->x, randomPoint->y - 2);                 // Move to next cell
					_maze->Setvisited(randomPoint->x, randomPoint->y);
					_maze->SetBreakWall(randomPoint->x, randomPoint->y, DOWN);
					State<Cell>*newState = new State<Cell>();

					newState->setState(*randomPoint);

					newState->cameFrom(newStatebefore);
					_maze->allstate.push_back(*newState);
					vistedCell++;                 // Increase visitedCells counter
				}
				else
					continue;
			}

			// GO DOWN
			else if (nextMove == DOWN && (randomPoint->y < SH_SIZE - 2)) {
				if (!_maze->chekVisitedPoint(randomPoint->x, randomPoint->y + 2)) {    // If not visited
					State<Cell>* newStatebefore = new State<Cell>();
					newStatebefore->setState(*randomPoint);
					_maze->Setvisited(randomPoint->x, randomPoint->y + 1);
					_maze->SetBreakWall(randomPoint->x, randomPoint->y, DOWN);  // Knock down wall
					Cell newMove = _maze->getCell(randomPoint->x, randomPoint->y + 2);

					vecPoint.push_back(newMove);
					randomPoint = _maze->getCellP(randomPoint->x, randomPoint->y + 2);             // Move to next cell
					_maze->Setvisited(randomPoint->x, randomPoint->y);
					_maze->SetBreakWall(randomPoint->x, randomPoint->y, UP);
					State<Cell>*newState = new State<Cell>();

					newState->setState(*randomPoint);

					newState->cameFrom(newStatebefore);
					_maze->allstate.push_back(*newState);
					vistedCell++;                 // Increase visitedCells counter
				}
				else
					continue;
			}

			// GO LEFT
			else if (nextMove == LEFT && (randomPoint->x > 1)) {
				if (!_maze->chekVisitedPoint(randomPoint->x - 2, randomPoint->y)) {    // If not visited
					State<Cell>* newStatebefore = new State<Cell>();
					newStatebefore->setState(*randomPoint);
					_maze->Setvisited(randomPoint->x - 1, randomPoint->y);
					_maze->SetBreakWall(randomPoint->x, randomPoint->y, LEFT);  // Knock down wall
					Cell newMove = _maze->getCell(randomPoint->x - 2, randomPoint->y);

					vecPoint.push_back(newMove);
					randomPoint = _maze->getCellP(randomPoint->x - 2, randomPoint->y);                 // Move to next cell
					_maze->Setvisited(randomPoint->x, randomPoint->y);
					_maze->SetBreakWall(randomPoint->x, randomPoint->y, RIGHT);
					State<Cell>*newState = new State<Cell>();

					newState->setState(*randomPoint);

					newState->cameFrom(newStatebefore);
					_maze->allstate.push_back(*newState);
					vistedCell++;                 // Increase visitedCells counter
				}
				else
					continue;
			}



			// GO RIGHT
			else if (nextMove == RIGHT && (randomPoint->x < SH_SIZE - 2)) {
				if (!_maze->chekVisitedPoint(randomPoint->x + 2, randomPoint->y)) {    // If not visited
					State<Cell>* newStatebefore = new State<Cell>();
					newStatebefore->setState(*randomPoint);
					_maze->Setvisited(randomPoint->x + 1, randomPoint->y);
					_maze->SetBreakWall(randomPoint->x, randomPoint->y, RIGHT);  // Knock down wall

					Cell newMove = _maze->getCell(randomPoint->x + 2, randomPoint->y);

					vecPoint.push_back(newMove);
					randomPoint = _maze->getCellP(randomPoint->x + 2, randomPoint->y);                // Move to next cell
					_maze->Setvisited(randomPoint->x, randomPoint->y);
					_maze->SetBreakWall(randomPoint->x, randomPoint->y, LEFT);
					State<Cell>*newState = new State<Cell>();

					newState->setState(*randomPoint);

					newState->cameFrom(newStatebefore);
					_maze->allstate.push_back(*newState);
					vistedCell++;                 // Increase visitedCells counter
				}
				else
					continue;
			}


		}


		else {

			for (size_t i = 0; i < vecPoint.size(); i++) {
				if (vecPoint.at(i).x == randomPoint->x && vecPoint.at(i).y == randomPoint->y) {
					vecPoint.erase(vecPoint.begin() + i);
				}
			}
			random_shuffle(vecPoint.begin(), vecPoint.end());
			randomPoint = &vecPoint.at(vecPoint.size() - 1);

		}

		ClearScreen();
		_maze->Redraw();

	}




	_maze->SetEndPosition(randomPoint->x, randomPoint->y);

	system("cls");
	_maze->Redraw();
	//_maze->Redraw();
	auto t2 = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
	_timeAlgo = to_string(duration);
	_timeAlgo += " milliseconds";
	

	return _maze;
}

