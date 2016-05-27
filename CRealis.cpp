#include <stdlib.h>
#include <iostream>
#include <string>
#include "main.h"
#include "DSystem.h"

namespace MAIN_ENV {
	std::string mainEnvironment::getInput() {
		std::cout << "\n\nUSER[0000]:";
		std::string inp_obj;
		std::getline(std::cin,inp_obj);
		return inp_obj;
	}

	int mainEnvironment::convertStateToInt() {
		if (cmdE == "new dsystem")
			return createNewSys;
		if (cmdE == "del dsystem")
			return delDSys;
		if (cmdE == "show dsystem")
			return showDSys;
		if (cmdE == "switch to admin space")
			return toASpace;
		if (cmdE == "exit")
			return exitMEnv;
		
		return indefState;
	}
	
	void mainEnvironment::updateEnv() {
		switch (state) {
		case createNewSys: base.cbChangeToDefault(); base.cbCreateNewSys(tempMemo); break;

		case delDSys: base.cbChangeToDefault(); base.cbDelDSys(tempMemo); break;

		case showDSys: base.cbShowDSys(tempMemo); break;

		case toASpace: base.cbToASpace(&aSpace); break;
		
		case exitMEnv: base.cbExitMainEnv(); break;

		case indefState: base.cbUnknownCmd(); break;
		}
	}

	void mainEnvironment::changeState(std::string cmd_arg) {
		cmdE = cmd_arg;
		state=convertStateToInt();
		updateEnv();
	}

	void cmdBase::cbToASpace(bool* argAState) {
		*argAState = true;
	}

	void cmdBase::cbUnknownCmd() {
		std::cout << "\nUnknown command!\n";
	}

	void cmdBase::cbCreateNewSys(void* ds_toCr) {
		std::string    inp_name;         //name of system
		DSystem::sUInt inp_dim;          //number of dimentionts in phase space 
		DSystem::sUInt inp_num_of_elems; //number of elements in system
		std::cout << "\nEnter the name of new system.\n";
		inp_name = mainEnvironment::getInput();
		std::cout << "\nEnter the number of dimentions in phase space of system.\n";
		std::cout << "\n\nUSER[0000]:";
		std::cin >> inp_dim;
		std::cout << "\nEnter the number of elements in system\n";
		std::cout << "\n\nUSER[0000]:"; 
		std::cin >> inp_num_of_elems;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		ds_toCr = new DSystem::main_ds(inp_name,inp_dim,inp_num_of_elems);
	}

	void cmdBase::cbChangeToDefault() {
		std::cout << "\nI`m changing state to default!\n";
	}

	void cmdBase::cbDelDSys(void* ds_toDel) {
		std::cout << "\nI`m deleting a Difficult System!\n";
	}

	void cmdBase::cbShowDSys(void*) {
		std::cout << "\nI`m showing a Difficult System!\n";
	}

	void cmdBase::cbExitMainEnv() {
		exit(0);
	}
}