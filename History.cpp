#pragma warning( disable : 4290 )
#include <memory>
#include "HistoryMaze.h"
#include "MyMaze2dGenerator.h"
HistoryMaze::HistoryMaze() {
	//<Maze2d> maz;
	//SimpleMaze2dGenerator my;
	//maz = my.generate();
	//setMaze(maz, "maze1");

}
shared_ptr<Maze2d> HistoryMaze::getMaze(string name) throw(std::string) {
	auto it = hismaze.find(name);
	if (it == hismaze.end()) {
		string e = "This maze is not found";
		throw e;
	}
	else {
		
		return it->second;
	}
}

void HistoryMaze::setsol(Solutiont sol) {


	hissol[sol.getname()] = sol;

}
Solutiont& HistoryMaze::getsol(string name) throw(std::string) {

	auto it = hissol.find(name);
	if (it == hissol.end()) {
		string e = "The solve for "+ name+" maze was not found";
		throw e;
	}
	else {
		return it->second;
	}

}

void HistoryMaze::setMaze(Maze2d* newmaze, string name)throw(std::string) {
	
	//Checks before whether there is the same maze
	for (auto it = hismaze.begin(); it != hismaze.end(); ++it) {
		if (*it->second == *newmaze) {
			string mass = "This maze is not saved. It already exists under the name: " + it->first;
			return throw mass;
		}
	}
			hismaze[name] = std::make_shared<Maze2d>(*newmaze);
}
void HistoryMaze::setMaze(shared_ptr<Maze2d> newmaze, string name)throw(std::string) {
	
	for (auto it = hismaze.begin(); it != hismaze.end(); ++it) {
		if (*it->second == *newmaze) {
			string mass = "This maze is not saved. It already exists under the name: " + it->first;
			return throw mass;
		}
	}
	hismaze[name] = std::make_shared<Maze2d>(*newmaze);
	
}
