#pragma once
#include "Model.h"
//abstract class for command
class Command
{
protected:
	Model* _model;
public:
	Command(Model* model) {
		_model = model;
	}
	
	~Command(){
		delete _model;}
	virtual void ex() = 0;
};
