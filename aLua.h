#pragma once

#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
#include <iterator>
#include <sstream>
#include <WinINet.h>
#include <algorithm>
#include <random>
#include <typeinfo>
#include <tchar.h>


using std::cout;
using std::endl;
using std::cin;

#define rbxaddy(x)(x - 0x400000 + ((DWORD)GetModuleHandle(0)))
#define LUA_MULTRET	(-1)



typedef void* (__cdecl			*lua_GetField)(int lua_State, int idx, const char *k);
typedef int(__cdecl				*lua_PCall)(int lua_State, int nargs, int nresults, int errfunc);
typedef void(__cdecl			*lua_PushString)(int lua_State, const char *s);
typedef const char *(__cdecl	*lua_ToLString)(int lua_State, int idx, size_t *len);
typedef void* (__cdecl			*lua_PushValue)(int lua_State, int idx);
typedef int(__cdecl				*lua_GetTop)(int lua_State);
typedef void(__cdecl			*lua_SetTop)(int lua_State, int n);
typedef void(__cdecl			*lua_SetField)(int lua_State, int idx, const char *k);
typedef void* (__cdecl			*lua_PushCClosure)(int lua_State, int fn(), int n);
typedef void* (__cdecl			*lua_Remove)(int lua_State, int idx);
typedef void* (__cdecl			*lua_PushNumber)(int lua_State, double Number);
typedef int(__cdecl				*lua_Type)(int lua_State, int idx);
typedef bool(__cdecl			*lua_pushboolean)(int lua_State, int a1);
typedef bool(__cdecl			*lua_toboolean)(int lua_State, int idx);
typedef int(__cdecl				*lua_pushnil)(int lua_State);
typedef int(__cdecl				*lua_next)(int lua_State, int idx);
typedef void * (*lua_Alloc) (void *ud, void *ptr, size_t osize, size_t nsize);
typedef void * (*lua_newstate)(lua_Alloc f, void *ud);
typedef void * (*lua_close)(int lua_State, int idx);




class CLua {
public:
	
	DWORD State;
	void Init();
	lua_toboolean toboolean = (lua_toboolean)rbxaddy(0x5002C0);
	lua_pushnil pushnil = (lua_pushnil)rbxaddy(0x5002C0); 
	lua_pushboolean pushboolean = (lua_pushboolean)rbxaddy(0x5002C0); 
	lua_GetTop gettop = (lua_GetTop)rbxaddy(0x00516EA0); //updt
	lua_GetField getfield = (lua_GetField)rbxaddy(0x004FE3E0);
	lua_PCall pcall = (lua_PCall)rbxaddy(0x004FF0C0);
	lua_PushString pushstring = (lua_PushString)rbxaddy(0x004FF620);
	lua_ToLString tolstring = (lua_ToLString)rbxaddy(0x00500900); // updt [4]
	lua_PushValue pushvalue = (lua_PushValue)rbxaddy(0x004FF6E0);
	lua_PushNumber pushnumber = (lua_PushNumber)rbxaddy(0x004FF5A0);
	lua_SetField setfield = (lua_SetField)rbxaddy(0x004FFF30);
	lua_Type type = (lua_Type)rbxaddy(0x00500780); //uppdt
	lua_SetTop settop = (lua_SetTop)rbxaddy(0x005002C0);
	lua_next next = (lua_next)0x517250;
	lua_newstate luanewstate;



	void getglobal(int ls, const char* k)
	{
		getfield(ls, -10002, k);
	}
	bool isnil(int luaState, int n) {
		return (type(luaState, (n)) == 0);
	};
	void pop(int luaState, int n) {
		return settop(luaState, -(n)-1);
	};
	const char* tostring(int luaState, int idx) {
		return tolstring(luaState, idx, NULL);
	};


};

extern CLua lua;

#define luaL_dostring(L, s) \
	(luaL_loadstring(L, s) || lua_pcall(L, 0, LUA_MULTRET, 0))