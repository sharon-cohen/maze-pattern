#include "MazeSearcable.h"
MazeSearchable::MazeSearchable(Maze2d& maze) :Searchable() {

	_maze = maze;

	m_cul["BFS"] = new claculatoreMaze<Cell>();
	m_cul["AStarMnhetten"] = new ClculateCostAstarForMazeManhetten<Cell>(_maze.getEnd());
	m_cul["AStarAirLine"] = new ClculateCostAstarForMazeAirline<Cell>(_maze.getEnd());

	for (size_t i = 0; i < _maze.allstate.size(); i++) {

		allvertex.push_back(_maze.allstate[i]);

	}

}
 vector<State<Cell>*> MazeSearchable::getAllPossibleMoves(State<Cell> sta, vector<State<Cell>> &list) {

	vector<State<Cell>*> myposibble;
	for (size_t i = 0; i < list.size(); i++) {

		if (!(list[i] != sta)) {

			myposibble.push_back(&list[i]);
		}
	}

	return myposibble;

}
 
 ClculateCost<Cell>* MazeSearchable::getcul(string command) {
	 //serch on the map the type of the ClculateCost
	auto it = m_cul.find(command);

	if (it == m_cul.end())
		return nullptr;

	return it->second;
}

