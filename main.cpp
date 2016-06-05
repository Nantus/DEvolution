#include <iostream>
#include <stdio.h>
#include "DSystem.h"
#include "main.h"

using namespace MAIN_ENV;

int main(){
	mainEnvironment mEnv;
	while (1) {
		mEnv.changeState(mainEnvironment::getInput()); // Main infinite cicle. Funcltion waiting for command from std::cin.
	}
	std::cin.get();
	return 0;
}