

#include <windows.h>
#include <conio.h>
#include <stack>
#include <fstream>
#include <thread>
#include <chrono>
#include "SimpleMaze2dGenerator.h"
#include "MyMaze2dGenerator.h"
#include <chrono>
#include "AStarAirLine.h"
#include "BFS.h"
#include "MazeSearcable.h"
#include "AStarManhattan.h"
#include "MazeCompression.h"
#include<fstream>
#include "CLI.h"
#include <iostream>
#include <sstream>
#include "Model.h"
#include "Observer.h"
#include <experimental/filesystem> 
#include <algorithm>    // std::replace
#include <vector> 
std::string changeFileName(const std::string& currentFileName, const std::string& extension, int number)
{
	std::cout << "Current file name: " << currentFileName << "\n";

	// ....other logics regarding current filename

	const std::string newFileName{ "August - " + std::to_string(number) + extension };
	std::cout << "File name after renaming: " << newFileName << "\n";
	return newFileName; // new file name
}


/********************************
* USED FOR THE SIZE OF THE MAZE *
*   Must be an odd number for   *
*    maze traversal reasons     *
********************************/
using namespace std;
void output(const std::string& type, std::experimental::filesystem::path& p)
{
	std::cout
		<< type << ":\n"
		<< "- native: " << p.string() << "\n"
		<< "- generic: " << p.generic_string() << "\n"
		<< "- preferred-separator" << p.make_preferred() << "\n";
}
int main(){
	
	 std::experimental::filesystem::path myPath("C:/Users/sharo/source/repos/MazePro/maze");
	output("local absolute win path", myPath);
	const std::string extension{ ".cpp" };
	int number{ 0 };
	// iterate through all the files in the directory
	for (const auto& dirEntry : std::experimental::filesystem::directory_iterator(myPath.string()))
	{
		// if the file is meant for changing name!
		if (std::experimental::filesystem::is_regular_file(dirEntry) && dirEntry.path().extension() == extension)
		{
			const std::string currentFileName{ dirEntry.path().filename().string() };
			// following function is meant for the logic to provide the new file names in the directory
			// in your case it cout have been simply: "August - " + std::to_string(number++) + "extension"
			const std::string newFileName{ changeFileName(currentFileName, extension, number++) };
			try
			{
				std::experimental::filesystem::rename(myPath / currentFileName, myPath / newFileName);
			}
			catch (std::experimental::filesystem::filesystem_error const& error)  // catch the errors(if any)!
			{
				std::cout << error.code() << "\n" << error.what() << "\n";
			}
		}

	}
	
	srand((unsigned)time(NULL));
	
	
	Observer *ob = new veiwCLI(cout, cin, "maze1");
	
	cout << endl;
	
	
}




/*#define SIZE 11
using namespace std;
// CELL STRUCTURE
struct Cell
{
	bool visited;
	bool top_wall;
	bool bot_wall;
	bool left_wall;
	bool right_wall;
	char display;
};

// FUNCTION DECLARATIONS
void Initialize(Cell Level[][SIZE]);
void ClearScreen();
void Redraw(Cell Level[][SIZE]);
void GenerateMaze(Cell Level[][SIZE], int &posX, int &posY, int &goalX, int &goalY);

// MAIN
int main() {

	Cell Level[SIZE][SIZE];
	int posX = 0;
	int posY = 0;
	int goalX = 0;
	int goalY = 0;
	bool game_over = false;

	while (!game_over) {
		system("cls");
		Initialize(Level);
		Redraw(Level);
		GenerateMaze(Level, posX, posY, goalX, goalY);
	

		char input;
		cout << "Create a new Maze? (Y)/(N): ";
		cin >> input;

		if ((input != 'n') && (input != 'N') && (input != 'y') && (input != 'Y'))
			cout << "Invalid option" << endl;
		else if ((input == 'n') || (input == 'N')) {
			game_over = true;
			cout << "Good bye!" << endl;
		}
	}

	_getch();
	return 0;
}

// INITIALIZE MAZE
void Initialize(Cell Level[][SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			Level[i][j].display = '*';
			Level[i][j].visited = false;
			Level[i][j].top_wall = true;
			Level[i][j].bot_wall = true;
			Level[i][j].left_wall = true;
			Level[i][j].right_wall = true;
		}
	}
	for (int i = 1; i < SIZE - 1; i++) {
		for (int j = 1; j < SIZE - 1; j++) {
			// Border Cells have fewer accessible walls
			Level[1][j].top_wall = false;
			Level[SIZE - 2][j].bot_wall = false;
			Level[i][1].left_wall = false;
			Level[i][SIZE - 2].right_wall = false;
		}
	}
}

// CLEAR SCREEN
void ClearScreen()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

// REDRAW MAZE
void Redraw(Cell Level[][SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		cout << endl;
		for (int j = 0; j < SIZE; j++)
			cout << " " << Level[i][j].display;
	}
}

// GENERATE MAZE
void GenerateMaze(Cell Level[][SIZE], int &posX, int &posY, int &goalX, int &goalY) {
	                                   // Pick random start cell
	int random = 0;
	int randomX = ((2 * rand()) + 1) % (SIZE - 1);                      // Generate a random odd number between 1 and SIZE
	int randomY = ((2 * rand()) + 1) % (SIZE - 1);                      // Generate a random odd number between 1 and SIZE
	posX = randomX;                                             // Save player's initial X position
	posY = randomY;                                             // Save player's initial Y position
	int visitedCells = 1;
		
	int percent = 0;
	stack<int> back_trackX, back_trackY;                        // Stack is used to trace the reverse path

	Level[randomY][randomX].display = 'S';                      // Set S as the start cell
	Level[randomY][randomX].visited = true;                     // Set start cell as visited;

	while (visitedCells < totalCells)
	{
	
		if (((Level[randomY - 2][randomX].visited == false) && (Level[randomY][randomX].top_wall == true && Level[randomY - 2][randomX].bot_wall == true)) ||
			((Level[randomY + 2][randomX].visited == false) && (Level[randomY][randomX].bot_wall == true && Level[randomY + 2][randomX].top_wall == true)) ||
			((Level[randomY][randomX - 2].visited == false) && (Level[randomY][randomX].left_wall == true && Level[randomY][randomX - 2].right_wall == true)) ||
			((Level[randomY][randomX + 2].visited == false) && (Level[randomY][randomX].right_wall == true && Level[randomY][randomX + 2].left_wall == true)))
		{
			random = (rand() % 4) + 1;      // Pick a random wall 1-4 to knock down
			cout << "rand " << random << endl;
			 // GO UP
			if ((random == 1) && (randomY > 1)) {
				if (Level[randomY - 2][randomX].visited == false) {    // If not visited
					Level[randomY - 1][randomX].display = ' ';    // Delete display
					Level[randomY - 1][randomX].visited = true;   // Mark cell as visited
					Level[randomY][randomX].top_wall = false;   // Knock down wall

					back_trackX.push(randomX);          // Push X for back track
					back_trackY.push(randomY);          // Push Y for back track

					randomY -= 2;                   // Move to next cell
					Level[randomY][randomX].visited = true;     // Mark cell moved to as visited
					Level[randomY][randomX].display = ' ';      // Update path
					Level[randomY][randomX].bot_wall = false;   // Knock down wall
					visitedCells++;                 // Increase visitedCells counter
				}
				else
					continue;
			}

			// GO DOWN
			else if ((random == 2) && (randomY < SIZE - 2)) {
				if (Level[randomY + 2][randomX].visited == false) {    // If not visited
					Level[randomY + 1][randomX].display = ' ';    // Delete display
					Level[randomY + 1][randomX].visited = true;   // Mark cell as visited
					Level[randomY][randomX].bot_wall = false;   // Knock down wall

					back_trackX.push(randomX);          // Push X for back track
					back_trackY.push(randomY);          // Push Y for back track

					randomY += 2;                   // Move to next cell
					Level[randomY][randomX].visited = true;     // Mark cell moved to as visited
					Level[randomY][randomX].display = ' ';      // Update path
					Level[randomY][randomX].top_wall = false;   // Knock down wall
					visitedCells++;                 // Increase visitedCells counter
				}
				else
					continue;
			}

			// GO LEFT
			else if ((random == 3) && (randomX > 1)) {
				if (Level[randomY][randomX - 2].visited == false) {    // If not visited
					Level[randomY][randomX - 1].display = ' ';    // Delete display
					Level[randomY][randomX - 1].visited = true;   // Mark cell as visited
					Level[randomY][randomX].left_wall = false;  // Knock down wall

					back_trackX.push(randomX);          // Push X for back track
					back_trackY.push(randomY);          // Push Y for back track

					randomX -= 2;                   // Move to next cell
					Level[randomY][randomX].visited = true;     // Mark cell moved to as visited
					Level[randomY][randomX].display = ' ';      // Update path
					Level[randomY][randomX].right_wall = false; // Knock down wall
					visitedCells++;                 // Increase visitedCells counter
				}
				else
					continue;
			}

			// GO RIGHT
			else if ((random == 4) && (randomX < SIZE - 2)) {
				if (Level[randomY][randomX + 2].visited == false) {    // If not visited
					Level[randomY][randomX + 1].display = ' ';    // Delete display
					Level[randomY][randomX + 1].visited = true;   // Mark cell as visited
					Level[randomY][randomX].right_wall = false; // Knock down wall

					back_trackX.push(randomX);          // Push X for back track
					back_trackY.push(randomY);          // Push Y for back track

					randomX += 2;                   // Move to next cell
					Level[randomY][randomX].visited = true;     // Mark cell moved to as visited
					Level[randomY][randomX].display = ' ';      // Update path
					Level[randomY][randomX].left_wall = false;  // Knock down wall
					visitedCells++;                 // Increase visitedCells counter
				}
				else
					continue;
			}

			percent = (visitedCells * 100 / totalCells * 100) / 100;        // Progress in percentage
			cout << endl << "   Generating a Random Maze... " << percent << "%" << endl;
		}
		else {
			randomX = back_trackX.top();
			back_trackX.pop();

			randomY = back_trackY.top();
			back_trackY.pop();
		}

		//ClearScreen();
		Redraw(Level);
	}

	goalX = randomX;
	goalY = randomY;
	Level[goalY][goalX].display = 'E';
	system("cls");
	//ClearScreen();
	Redraw(Level);
	cout << endl << "\a\t   Complete!" << endl;
}

// SAVE MAZE

*/