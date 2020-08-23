#include "Cell.h"

Cell::Cell() {}
//Checks if it is the same position on the matrix
bool Cell::operator==(const Cell& c1)const {
	if (this->x == c1.x && this->y == c1.y) { return true; }
	else
		return false;
}
int Cell::getsize() { return sizeof(*this); }
Cell& Cell::operator=(const Cell& other) {
	x = other.x;
	y = other.y;
	visited = other.visited;
	bot_wall = other.bot_wall;
	top_wall = other.top_wall;
	left_wall = other.left_wall;
	right_wall = other.right_wall;
	display = other.display;
	return *this;
}
//Cell& operator*() { return *this; }
bool Cell::operator!=(const Cell& c1)const {
	if (this->x == c1.x && this->y == c1.y) { return false; }
	else
		return true;
}
std::string Cell::getstringCell() {
	std::string s = "{";
	s = s + std::to_string(x);
	s = s + ",";
	s = s + std::to_string(y);
	s = s + "}";
	return s;
}
std::ostream& operator<<(std::ostream& os, const Cell& dt)
{
	os << dt.x << '/' << dt.y << "y " << std::endl;
	return os;
}