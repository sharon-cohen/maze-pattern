#pragma once
#include "Model.h"
using namespace std;
class view;
//interface for controller
class Controller
{
protected:
	view *_view;
	Model *_model;
public:
	
	Controller( view * view, Model *model) :_view(view),_model(model){}
	
	
	virtual Command * get( string& command) = 0;
};