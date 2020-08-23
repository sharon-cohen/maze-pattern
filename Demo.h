#include "MyMaze2dGenerator.h"
#include "MazeSearcable.h"

#include "AstarA.h"
#include "AstarM.h"
#pragma once
template<class T>
class Demo {
public:
	Demo() {}
	void run() {
		MyMaze2dGenerator  gen;
		Maze2d *maz1 = new Maze2d();
		maz1 = gen.generate();
		cout<<endl<<"Time"<<gen.measureAlgorithmTime()<<endl;
		string*result= maz1->getAllPossibleMoves();
		cout << "All the possible moves:"<< *result<<endl;
		
		maz1->Redraw();
		MazeSearchable MazeSerch(*maz1);
		Searcher<T>* _searcher;
		
		_searcher = new BFSAstar<Cell>();
		Solutiont sol1(_searcher->search(MazeSerch));
		
		_searcher = new AstarM<Cell>();
		Solutiont sol2(_searcher->search(MazeSerch));
		
		_searcher = new AstarA<Cell>();
		Solutiont sol3(_searcher->search(MazeSerch));
		cout <<endl <<"The number of nodes in BFS solution" << endl << sol1.sizesol() << endl;
		cout << "The number of nodes in AStar Manhattan solution " << endl << sol2.sizesol() << endl;
		cout << "The number of nodes in AStar Air Line solution " << endl << sol3.sizesol() << endl;
		
	}
};