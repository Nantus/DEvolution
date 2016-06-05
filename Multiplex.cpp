#include "Multiplex.h"
#include "MyMath.h"

multiplex::multiplex(): _index(1), nDimentions(0), nElems(0), _dim(0) {

}

multiplex::multiplex(int argNDimentions, int argNElems) : nDimentions(argNDimentions), nElems(argNElems), _index(1), _dim(0) {
	int count = 1;
	for (int i(0); i < nDimentions; i++)
		count *= nElems;

	_multiplex = new double[count];
	clear();
}

multiplex::~multiplex() {
	delete []_multiplex;
}

double multiplex::getElem(int* argIndex) {
	changeIndex(argIndex);
	return _multiplex[_index];
}

double multiplex::getElem() {
	return _multiplex[_index];
}

void multiplex::changeIndex(int* argIndex) {
	_index = 1;
	for (int i(0); i < nDimentions; i++)
		_index += (argIndex[i] - 1)*myMath::power(nElems, nDimentions - i - 1);
	_index -= nDimentions;
}

void multiplex::changeElem(double argElem) {
	_multiplex[_index] = argElem;
}

void multiplex::changeElem(int* argIndex, double argElem) {
	changeIndex(argIndex);
	_multiplex[_index] = argElem;
}

multiplex& multiplex::operator [](int index) {
	_index += (index-1)*myMath::power(nElems,nDimentions-_dim-1);
	_dim++;
	return *this;
}

multiplex::operator double& () {
	int n = _index-nDimentions;
	_index = 0;
	_dim = 0;

	return _multiplex[n];
}
multiplex& multiplex::operator = (double argNValue) {
	int n = _index-nDimentions;
	_index = 0;
	_dim = 0;

	_multiplex[n] = argNValue;
	return *this;
}

void multiplex::clear() {
	for (int i(0); i < myMath::power(nElems, nDimentions); i++)
		_multiplex[i] = 0.000;
}

int multiplex::getNDimentions() {
	return nDimentions;
}

int multiplex::getNElems() {
	return nElems;
}

int multiplex::getIndex() {
	return _index;
}