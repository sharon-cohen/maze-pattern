#include "Mycontrollerh.h"
#include "CLI.h"
#include "Model.h"
MyController::MyController(view * view, Model *model) :Controller(view,model)
{
	
	if (typeid(*view) == typeid(veiwCLI)) {
		((veiwCLI*)view)->Setcontroller(this);
	}
	
}
//get order from view and manage them if he need more information frome user for some order 
//call to method user input in the view
// for every order creat his command
Command * MyController::get(string& command)
{
			if (command == "path") {
				//string n = "C:/Users/sharo/source/repos/MazePro/maze";
				string namePath = "Enter the name of the Path:";
				_view->inputuser(namePath);
				m_commands["path"] = new commandPath(_model, namePath);
				return m_commands["path"];
			}
			if (command == "display") {
				
				string nameMaze = "Enter the name of the maze:";
				_view->inputuser(nameMaze);
				m_commands["display"] = new CommandDisplay(_model, _view->searchHistory(nameMaze));
				return m_commands["display"];
			}
			if (command == "save") {
				string nameMaze = "Enter the name of the maze:";
			
				_view->inputuser(nameMaze);
				string namefile = "Enter the name of the file:";
				_view->inputuser(namefile);
				
				m_commands["save"] = new CommandSave(_model, _view->searchHistory(nameMaze), namefile);
				return m_commands["save"];
			}
			if (command == "solve") {
				string nameMaze = "Enter the name of the maze:";
				_view->inputuser(nameMaze);
				string nameAlgoritham = "Enter the name of the algorithm BFS , AStarM, AStarA";
				_view->inputuser(nameAlgoritham);
				
				m_commands["solve"] = new CommandSolve(_model,_view->searchHistory(nameMaze), nameAlgoritham,nameMaze);
				return m_commands["solve"];
			}
			if (command == "display solution") {
				if (typeid(*_view) == typeid(veiwCLI)) {
					((veiwCLI*)_view)->displaySolve();
				}
				return nullptr;
			}
			if (command == "size memory") {
				string nameMaze = "Enter the name of the maze:";
				_view->inputuser(nameMaze);
				m_commands["SizeMemory"] = new CommandSizeMazeMemory(_model,_view->searchHistory(nameMaze));
				return m_commands["SizeMemory"];
			}
			if (command == "load"){
				string namefile = "The name of file: ";
				_view->inputuser(namefile);
				m_commands["load"] = new commandLoad(_model, namefile);
				return m_commands["load"];
			}
			if (command == "generate maze")
			{
				string para = "random";
				string p = "random OR DFS: ";

				_view->inputuser(p);

				
				m_commands["generate maze"] = new createMazecommand(_model, p);
				return m_commands["generate maze"];
			}
			if (command == "size file") {
				string nameMaze = "Enter name of the maze:";
				_view->inputuser(nameMaze);
				m_commands["SizeFile"] = new CommandSizeMazeFile(_model, _view->searchHistory(nameMaze));
				return m_commands["SizeFile"];
			}
			
			if (command == "exit") {
				exit(0);
			}
			else { return nullptr; }
		
	}


