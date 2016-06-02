#pragma once

template <typename myType>
class multiplex {
public:
	multiplex();
	multiplex(int,int); //when hypercube
	myType getElem(int*);
	myType getElem();
	void changeIndex(int*);
	void cnangeElem(myType);
	void changeElem(int*,myType);
	multiplex& operator [] (int);
	operator myType&();
	multiplex& operator = (myType);
private:
	int _index;
	int nDimentions;
	int nElems;
	int _dim;
	myType* _multiplex;
};