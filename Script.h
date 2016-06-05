#pragma once
#pragma comment(lib,"lua5.3.lib")
extern "C" {
	#include <lua.h>
	#include <lualib.h>
	#include <lauxlib.h>
}

class Script {
public:
	void Create();
	void Close();
	int DoFile(char* ScriptFileName);
	void Array();
	void RegisterArray(char* arrayName);
	int GetArgumentCount();

	template<class T>
	T GetArgument(int index);

	template<class T>
	void RegisterConstant(T value, char* constantName);

	template<class T>
	void RegisterConstantArray(T value, int index);

	template<class T>
	void Return(T value);
private:
	lua_State* lua_state;
};


