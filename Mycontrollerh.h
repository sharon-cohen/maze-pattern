#pragma once
#include <map>
#include <string>
#include <functional>	
#include "maze2d.h"
#include "commandDisplayh.h"
#include "commandCreate.h"
#include "Controller.h"
#include "MyModel.h"
#include "HistoryMaze.h"
#include "CommandSave.h"
#include "commandpath.h"
#include "commandSolve.h"
#include "commandSizeMemory.h"
#include "commandLoad.h"
#include "CommandSizeFile.h"

class Observer;
class MyController : public Controller
{
private:
	string chois;
	
public:
	MyController(view * view, Model *model);
	

public:
	
	~MyController() { }
	Command * get(string& command);
	
private:
	map<string, Command*> m_commands;
	
};	