#include "command.h"
#include "Model.h"
#include <string>

// commad for get all the local file and folder in some path
class commandPath :public Command {
private:
	string _path;

public:
	commandPath(Model * model, string path) :Command(model) {

		_path = path;

	}
	virtual vector<string> executeFileNamr() {
		const char *cstr = _path.c_str();
		return _model->path(cstr);
	}


	virtual void ex() {}
};