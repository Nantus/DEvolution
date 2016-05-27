#pragma once
#include <stdlib.h>
#include <string>

#define indefState   0
#define createNewSys 1
#define delDSys      2
#define showDSys	 3
#define toASpace     4
#define exitMEnv	 5

namespace MAIN_ENV 
{
	class cmdBase {
	public:
		void cbChangeToDefault();
		void cbCreateNewSys(void*);
		void cbDelDSys(void*);
		void cbShowDSys(void*);
		void cbToASpace(bool*);
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
	};
}