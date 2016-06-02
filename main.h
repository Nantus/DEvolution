#pragma once
#include <stdlib.h>
#include <string>
#include "DSystem.h"

//States of environment(necessary to execute the commands):
#define indefState	         0
#define createNewSys         1
#define delDSys              2
#define showDSys	         3
#define toASpace             4 
#define createNewElemBase    5
#define exitMEnv	         6 
#define showElemBase	     7
#define addElemToElemBase    8     
#define delElemFromElemBase  9
#define changeElemOfElemBase 10

namespace MAIN_ENV 
{
	//Main command base class. Includes methods that actually are executale code of comands.
	class cmdBase {
	public:
		void cbChangeToDefault();
		void cbCreateNewSys(void*);
		void cbDelDSys(void*);
		void cbShowDSys(void*);
		void cbToASpace(bool*);
		void cbCreateNewElemBase(DSystem::main_elem_base**);
		void cbShowElemBase(DSystem::main_elem_base*);
		void cbAddElemToElemBase(DSystem::main_elem_base*);
		void cbDelElemFromElemBase(DSystem::main_elem_base*);
		void cbChangeElemOfElemBase(DSystem::main_elem_base*);
		void cbExitMainEnv();
		void cbUnknownCmd();
	};

	//Main environment class. 
	class mainEnvironment {
	public:
		static std::string getInput(); // Getting the input information from std::cin.
		void showState();
		void changeState(std::string); // Main method of class. Updating state with string argument.
	private:	
		bool aSpace; // Gives rights of superuser when true.
		void updateEnv(); // Calls methods from cmdBase according to parameter mainEnvironment::state.
		int convertStateToInt(); // Converting the text from mainEnvironment::cmdE to integer(returns one of defined states).
		std::string cmdE; // String contains command entered by user.
		short unsigned state; // Shows what command was executed last.
		cmdBase base; // Base of commands
		void* tempMemo; 
		DSystem::main_elem_base* tempBase;
	};
}