#pragma once
using namespace std;
// get notice from Observable class
class Observable;
class Observer
{
public:
	
	virtual void update(string mass) {
		cout << endl << mass << endl;

	}
protected:
	
};
