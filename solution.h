#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <vector>
#include "State.h"
using namespace std;
//for the result of search 
class Solutiont 
{
private:
	string nameMaze;
	vector<State<Cell>> m_solution;
public:
	Solutiont() {
		nameMaze = "";
	}
	void setname(const string& name) {
		nameMaze = name;
	}
	string  getname() { return nameMaze; }
	Solutiont(vector<State<Cell>> solution){
		
		for (auto & element : solution) {
			m_solution.push_back(element);

		}
	
}
	Solutiont& operator=(const Solutiont& other) {
		nameMaze = other.nameMaze;
		for (auto & element : other.m_solution) {
			m_solution.push_back(element);

		}
		return *this;
	}
	bool operator==( Solutiont& s)const{
		if (m_solution.size() != s.m_solution.size()) {
			return false;
		}
		else {
			if (s.m_solution == m_solution) {
				return true;
			}
			else { return false; }
		}
	}
	virtual vector<State<Cell>>& getsolve() { return m_solution; }
	//Necessary for the use solution map
	bool operator > (const Solutiont m) const {
		return 1 > 0;
	}
	size_t sizesol() {
		return m_solution.size();
	}

};
#endif