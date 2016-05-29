#pragma once
#include <stdlib.h>
#include <string>
#include "DSystem.h"

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

	class mainEnvironment {
	public:
		static std::string getInput();
		void showState();
		void changeState(std::string);
	private:	
		bool aSpace;
		void updateEnv();
		int convertStateToInt();
		std::string cmdE;
		short unsigned state;
		cmdBase base;
		void* tempMemo;
		DSystem::main_elem_base* tempBase;
	};
}