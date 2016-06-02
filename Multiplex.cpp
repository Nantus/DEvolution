
#include "Multiplex.h"

template <typename myType>
multiplex<myType>::multiplex(): index(0),nDimentions(0),nElems(0),_dim(0) {
}

template <typename myType>
multiplex<myType>::multiplex(int argNDimentions, int argNElems): nDimentions(argNDimentions),nElems(argNElems),_index(0),_dim(0) {
	int count = 1;
	for (int i(0); i < nDimentions; i++)
		count *= nElems;

	_multiplex = new myType[count];
}

template <typename myType>
multiplex<myType>& multiplex<myType>::operator [](int index) {
	_dim++;

	int count = 1;
	for (int i(0); i < nDimentions - _dim; i++)
		count *= nElems;

	_index += index*count; 

	return *this;
}

template <typename myType>
multiplex<myType>::operator myType& () {
	int n = _index;
	_index = 0;
	_dim = 0;

	return _multiplex[n];
}

template <typename myType>
multiplex<myType>& multiplex<myType>::operator = (myType argNValue) {
	int n = _index;
	_index = 0;
	_dim = 0;

	_multiplex[n] = argNValue;
	return *this;
}

template <typename myType>
myType multiplex<myType>::getElem(int* argIndex) {
/*	int index=0;
	for (int i(0); i < nDimentions; i++)
		index += (argIndex[i] - 1)*(nElems-i);*/
}