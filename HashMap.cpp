#include "HashMap.h"
#include "maze2d.h"
#include <tuple>
HashMap::HashMap() {}
void HashMap::setMazeSolution(shared_ptr<Maze2d> maze, Solutiont sol) {
	_HashMap[maze] = sol;
}
bool HashMap::checkexsistMazeSol(shared_ptr<Maze2d> maze) {
	
	map<shared_ptr<Maze2d>, Solutiont>::iterator it;
	if (_HashMap.empty()) {
		return false;
	}
	
	for (it = _HashMap.begin(); it != _HashMap.end(); it++)
	{
		
		if (*it->first == *maze) {
			return true;
		
		}
	}
	return false;

}
Solutiont HashMap::getsol(shared_ptr<Maze2d> maze) {
	
	return _HashMap[maze];
}

