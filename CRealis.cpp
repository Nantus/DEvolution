#include <stdlib.h>
#include <iostream>
#include <string>
#include "main.h"
#include "Script.h"
#include "DSystem.h"

namespace MAIN_ENV {
	Script script;

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
		if (cmdE == "script run")
			return runScript;
		if (cmdE == "script init")
			return initScript;
		if (cmdE == "script close")
			return closeScript;
		if (cmdE == "switch to admin space")
			return toASpace;
		if (cmdE == "new elemBase" && aSpace)
			return createNewElemBase;
		if (cmdE == "show elemBase" && aSpace)
			return showElemBase;
		if (cmdE == "elemBase addElem" && aSpace)
			return addElemToElemBase;
		if (cmdE == "elemBase delElem" && aSpace)
			return delElemFromElemBase;
		if (cmdE == "elemBase changeElem" && aSpace)
			return changeElemOfElemBase;
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

		case createNewElemBase: base.cbCreateNewElemBase(&tempBase); break;

		case showElemBase: base.cbShowElemBase(tempBase); break;

		case addElemToElemBase: base.cbAddElemToElemBase(tempBase); break;

		case delElemFromElemBase: base.cbDelElemFromElemBase(tempBase); break;

		case changeElemOfElemBase: base.cbChangeElemOfElemBase(tempBase); break;

		case initScript: base.cbInitScript(); break;

		case runScript: base.cbRunScript(); break;

		case closeScript: base.cbCloseScript(); break;

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
		inp_dim = atoi(mainEnvironment::getInput().c_str());
		std::cout << "\nEnter the number of elements in system\n";
		inp_num_of_elems = atoi(mainEnvironment::getInput().c_str());

		ds_toCr = new DSystem::main_ds(inp_name,inp_dim,inp_num_of_elems);
	}

	void cmdBase::cbCreateNewElemBase(DSystem::main_elem_base** eb_toCr) {
		DSystem::sUInt numOfElems;
		std::cout << "\nEnter the number of elements in base(You could change it later).\n";
		numOfElems = atoi(mainEnvironment::getInput().c_str());
		if (*eb_toCr != nullptr)
			delete *eb_toCr;
		*eb_toCr = new DSystem::main_elem_base(numOfElems);
	}

	void cmdBase::cbShowElemBase(DSystem::main_elem_base* eb_toShow) {
		if (eb_toShow != nullptr)
		{
			for (int i(0); i < eb_toShow->get_NumOfElems(); i++)
				std::cout << "\n" << eb_toShow->get_ElemByID(i)->element;
			std::cout << "\n";
		}
		else
			std::cout << "\nThere is no element base to show\n";
	}

	void cmdBase::cbAddElemToElemBase(DSystem::main_elem_base* eb_toAddElem) {
		if (eb_toAddElem != nullptr)
		{
			int inpElem;
			std::cout << "\nThe element will be added to tail.\n";
			std::cout << "Enter the element.";
			inpElem = atoi(mainEnvironment::getInput().c_str());
			eb_toAddElem->add_elem_toTail(inpElem);
		}
		else
			std::cout << "\nThere is no element base to add element\n";
	}

	void cmdBase::cbDelElemFromElemBase(DSystem::main_elem_base* eb_toDelElem) {
		if (eb_toDelElem != nullptr)
		{
			int delElemID;
			std::cout << "Enter the element`s ID.";
			delElemID = atoi(mainEnvironment::getInput().c_str());
			eb_toDelElem->del_elem(delElemID);
		}
		else
			std::cout << "\nThere is no element base to delete element\n";
	}

	void cmdBase::cbChangeElemOfElemBase(DSystem::main_elem_base* eb_toChangeElem) {
		if (eb_toChangeElem != nullptr) 
		{
			int changeElemID;
			int newElem;
			std::cout << "\nEnter the element`s ID.\n";
			changeElemID = atoi(mainEnvironment::getInput().c_str());
			std::cout << "\nEnter the new element.\n";
			newElem = atoi(mainEnvironment::getInput().c_str());
			eb_toChangeElem->get_ElemByID(changeElemID)->element = newElem; 
		}
		else
			std::cout << "\nThere is no element base to change element\n";
	}

	void cmdBase::cbInitScript() {
		script.Create();
		//Register some functions
	}

	void cmdBase::cbRunScript() {
		script.DoFile("Script.lua");
	}

	void cmdBase::cbCloseScript() {
		script.Close();
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