#include <iostream>
#include "main.h"

using namespace MAIN_ENV;

int main(){
	mainEnvironment mEnv;
	while (1) {
		mEnv.changeState(mainEnvironment::getInput());
	}
	std::cin.get();
	return 0;
}