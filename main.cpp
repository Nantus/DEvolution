#include <iostream>
#include "DSystem.h"
#include "main.h"

using namespace MAIN_ENV;

int main(){
	mainEnvironment mEnv;
	while (1) {
		mEnv.changeState(mainEnvironment::getInput());
	}
	/*
	DSystem::main_elem_base eb(3);
	int inpElem=3;
	eb.add_elem(eb.get_NumOfElems() + 1, &inpElem);
	for (int i(0); i < eb.get_NumOfElems(); i++)
		std::cout << "\n" << eb.get_ElemByID(i)->element;
	std::cout << "\n";
	std::cout << "\n";
	*/
	std::cin.get();
	return 0;
}