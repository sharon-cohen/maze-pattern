#pragma once
#include "Search.h"
#include "Model.h"
// implementaion my model coult get every type of state maze
template <class T>
class MyModel :public Model, public Observable {


private:
	HashMap* _hashmap;
	Maze2dGenerator *_generate;
	MazeCompression *_comp;
	Searcher<T>* _searcher;

public:
	
	MyModel(Observer* observer) :Model(), Observable(observer) {
		_hashmap = new HashMap();
	};
	virtual vector<string>path(const char * path)throw(std::string) {
		vector<string> vec;
		struct dirent *entry;
		DIR *dir = opendir(path);

		if (dir == NULL) {
			string error = "This dirctory was not found ";
			throw error;
		}
		while ((entry = readdir(dir)) != NULL) {
			vec.push_back(entry->d_name);


		}
		closedir(dir);
		notify("All the files are ready: ");
		std::this_thread::sleep_for(std::chrono::seconds(1));
		return vec;
	}
	virtual shared_ptr<Maze2d> generate(string type)throw(std::string) {
		if (type == "DFS") {
			_generate = new MyMaze2dGenerator();

		}
		else {
			if(type == "random")
			_generate = new SimpleMaze2dGenerator();
			else {
				string error = "The algorithm " + type + " for create maze was not found";
				throw error;
			}
		}
		notify("Maze will be ready in 5 seconds");
		std::this_thread::sleep_for(std::chrono::seconds(5));
		

		return _generate->generate();

	}
	virtual void  display(shared_ptr<Maze2d> maze) {
		notify("Maze will be display in 2 seconds");
		std::this_thread::sleep_for(std::chrono::seconds(2));
		
		maze->Redraw();
	
	}
	virtual void savemaze(shared_ptr<Maze2d>  maze, string namefile) {
		maze->Redraw();
		vector<char> data = maze->getData();
		_comp = new MazeCompression(data, namefile);

		std::this_thread::sleep_for(std::chrono::seconds(1));
		string mass = "The maze saved in " + namefile;
		mass += " file";
		std::this_thread::sleep_for(std::chrono::seconds(2));
		notify(mass);
	}
	virtual Maze2d* laodmaze(string nameMaze) {
		MazeCompression* readmaze = new MazeCompression();
		Maze2d *maze = new Maze2d(readmaze->read(nameMaze));
		cout << "The maze is loaded: " << endl;
		maze->Redraw();
		return maze;
	}
	virtual size_t calculatSizeFile(shared_ptr<Maze2d> maze) {
		
		
		vector<char> data = maze->getData();
		MazeCompression* readmaze = new MazeCompression(data);
		return  readmaze->SizeCompression();
	}
	virtual Solutiont solve(shared_ptr<Maze2d> maze, string nameAlgoritham, string nameMaze)throw(std::string) {
		//Checking if this maze already has a solution
		if (_hashmap->checkexsistMazeSol(maze)) {
			//notice for the user
			notify("Maze was found in HashMap");
			std::this_thread::sleep_for(std::chrono::seconds(1));
			Solutiont sol = _hashmap->getsol(maze);
			return sol;
		}
		else {
			// make the maze to be Searchable
			MazeSearchable MazeSerch(*maze);
			string mass = "The result of the solution in";
			mass = mass + nameMaze;
			if (nameAlgoritham == "BFS") {
				
				_searcher = new BFSAstar<T>();
			
				Solutiont sol(_searcher->search(MazeSerch));
				sol.setname(nameMaze);
				notify(mass);
				_hashmap->setMazeSolution(maze, sol);
				return sol;
			}
			if (nameAlgoritham == "AStarM") {
				
				_searcher = new AstarM<T>();
				Solutiont sol(_searcher->search(MazeSerch));
				sol.setname(nameMaze);
				notify(mass);
				_hashmap->setMazeSolution(maze, sol);
				return sol;

			}
			if (nameAlgoritham == "AStarA") {
				
				_searcher = new AstarA<T>();
				Solutiont sol(_searcher->search(MazeSerch));
				sol.setname(nameMaze);
				notify(mass);
				_hashmap->setMazeSolution(maze, sol);
				return sol;
			}
			else {
				string error = "The algorithm " + nameAlgoritham + "was not found";
				throw error;
				
			}
		}
	}
	virtual int calculatSizeMemory(shared_ptr<Maze2d> maze) {
	
		notify("The calculation will be completed in one second");
		std::this_thread::sleep_for(std::chrono::seconds(1));
		return maze->getsizeOfMaze();
	}
	virtual vector<size_t> compermemory(vector<Maze2d*> maze) {
		
		vector<size_t> res;
		for (size_t i = 0; i < maze.size(); i++) {
			res.push_back(maze[i]->getsizeOfMaze());
			vector<char> data = maze[i]->getData();
			MazeCompression* readmaze = new MazeCompression(data);
			res.push_back(readmaze->SizeCompression());
		}
		return res;
	}
};