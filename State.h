#pragma once
#include <string>
#include <memory>

using namespace std;

//generic state 
template <typename T>
class State
{
protected:
	T				m_state;
	double			m_cost;
	State<T>*	   m_cameFrom;
public:
	State(T state) :  m_cost(0), m_cameFrom(nullptr) {
		m_cameFrom = new State<T>();
		m_state = state;
		m_cost = 1;
	}
	State() :  m_cost(0), m_cameFrom(nullptr) {
		m_cost = 1;
	}
	void setState(T &state) {
		m_state = state;
		
	}
	State(T state, State<T> cameFrom) : m_state(state), m_cost(0), m_cameFrom(&cameFrom) {}
	//set m_cameFrom
	virtual void cameFrom(State<T>* cameFrom) { 
		m_cameFrom = cameFrom; 
	}
	bool operator==(const State<T> &s) const{
		if (m_state == s.m_state) 
			return true;
		else
			return false;
	}
	// get the m_state of m_cameFrom
	T getTbefore() {
		return m_cameFrom->m_state;
	}
	void SetbeforT(T& t) {
		m_cameFrom = new State<T>(t);
	
	}
	//Compares between T of cureent state and cameFrom state
	bool operator!=(State<T> s) { 
		
		State<T> temp = m_cameFrom->getState();
		
		if (temp.m_state ==
			s.m_state) {

			return false;

		}
		else
			return true;
	}
	T& getState() { return m_state; }
	State<T>& operator=(const State<T> other) {
		m_state = other.m_state;
		m_cost = other.m_cost;
		m_cameFrom = other.m_cameFrom;
		return *this;
	}
	//testing
	void pritb() {
		std::cout << *m_cameFrom->getState();
	}
	virtual double getcost() { return m_cost; }
	//testing
	virtual void printcost() { std::cout << ' ' << m_cost << endl; }
	virtual void setcost(double cost) { m_cost = cost+ m_cost;
	
	}
	bool operator<( const State<T>& t2)const 
	{
		if (m_cost > t2.m_cost) return true;
		return false;
	}
	//testing 
	void pritst() {
		std::cout << m_state.x << m_state.y << endl;
	}
	int calculateSize() {return  m_state.getsize() + 4 + sizeof(double);

	}
	string getstringstate() {
		return m_state.getstringCell();
	}
};




