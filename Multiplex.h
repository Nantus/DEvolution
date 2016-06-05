#pragma once

class multiplex {
public:
	multiplex();
	multiplex(int,int); //when hypercube
	~multiplex();
	double getElem(int*);
	double getElem();
	void changeIndex(int*);
	void changeElem(double);
	void changeElem(int*,double);
	int getNDimentions();
	int getNElems();
	int getIndex();
	multiplex& operator [](int);
	operator double& ();
	multiplex& operator = (double);
protected:
	void clear();
	int _index;
	int nDimentions;
	int nElems;
	int _dim;
	double* _multiplex;
};