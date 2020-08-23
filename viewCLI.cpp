
#include "CLI.h"
#include "Mycontrollerh.h"

veiwCLI::veiwCLI(ostream &out, istream &in) :view(), _in(in), _out(out) {

	
	MyHistory = new HistoryMaze();
	
	
}
void veiwCLI::Setcontroller(Controller *mycontroller) {
	
	_controller = mycontroller;

}
void veiwCLI::inputuser(string &par) {
	string answer = "";
	cout << par << endl;
	getline(cin, par);
}
shared_ptr<Maze2d> veiwCLI::searchHistory(string name) {
	
	return MyHistory->getMaze(name);
}
//Receives each iteration An instruction from the user checks whether it is correct and send to cintroller
// until user press exit
void veiwCLI::start() {
	
	string order = " ";
	int choose = 0;
	string command = "";
	while (command.compare("exit") != 0)
	{
		try {
		string chice = "c";
		string nameofmaze = "";
		cout << endl <<"Enter your order: ";
		getline(cin, command);
		
		Command * com = _controller->get(command);

		if (com != nullptr) {
			if (typeid(*com) == typeid(createMazecommand)) {
				cout << "Enter the name of the maze: " << endl;
				getline(cin, nameofmaze);
				//save maze in the history
				MyHistory->setMaze(((createMazecommand*)com)->executeNewMaze(), nameofmaze);
			}
			if (typeid(*com) == typeid(commandPath)) {

				vector<string> v(((commandPath*)com)->executeFileNamr());
				for (auto i = v.begin(); i != v.end(); ++i)
					std::cout << *i << endl;
			}
			if (typeid(*com) == typeid(CommandSolve)) {
				//save the solution in the history
				MyHistory->setsol(((CommandSolve*)com)->executeSolve());
			}
			if (typeid(*com) == typeid(CommandSizeMazeMemory)) {
				cout << "The size of the memory is: " << ((CommandSizeMazeMemory*)com)->executeSizeMemory() << endl;
			}
			if (typeid(*com) == typeid(commandLoad)) {
				string name = "imput maze name is load: ";
				inputuser(name);
				
				MyHistory->setMaze(((commandLoad*)com)->executeLoadMaze(), name);
			}
			if (typeid(*com) == typeid(CommandSizeMazeFile)) {
				cout << "The size of the maze in the file is : " << ((CommandSizeMazeFile*)com)->executeSizeFile() << endl;
			}
			if (typeid(*com) == typeid(CommandDisplay)) {

				((CommandDisplay*)com)->execute();


			}
			if (typeid(*com) == typeid(CommandSave)) {
				((CommandSave*)com)->execute();
			}

		}
		else {
			if (command != "display solution")
				cout <<"Unsupported Command!" << endl;
			else { continue; }
		}


	  }
	
		catch (string mass) {
			cout << endl;
			cout << mass << endl;
		}
	}


}
void veiwCLI::displaySolve() {
	string name = " Enter the name of the maze: ";
	inputuser(name);
	Solutiont sol = MyHistory->getsol(name);
	MyHistory->getMaze(name)->setsolve(sol.getsolve());

}
