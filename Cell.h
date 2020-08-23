#pragma once
#include <iostream>
#include <string>

class Cell {
public:
	bool visited;
	bool top_wall;
	bool bot_wall;
	bool left_wall;
	bool right_wall;
	char display;
	int x;
	int y;
	int ordervisit;
	int orderback;
	Cell();
	bool operator==(const Cell& c1)const;

	int getsize();
	Cell& operator=(const Cell& other);
	
	bool operator!=(const Cell& c1)const;
	std::string getstringCell();
	
	friend std::ostream& operator<<(std::ostream& os, const Cell& dt);
	
};
