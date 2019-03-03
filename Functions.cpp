//#include "stdafx.h"
#include "aLua.h"
#include "Functions.h"
#include <iostream>

using namespace std;

auto Returncheck()
{
	int rccheck_function = rbxaddy(0x5046B0); 
	int flag1 = rbxaddy(0x14773B0); 
	int flag2 = rbxaddy(0x15982EC); 

	int flag1_val = *(int*)(flag1); 
	int flag2_val = *(int*)(flag2); 

								
	DWORD nOldProtect;
	BYTE OldJump = *(BYTE*)(rccheck_function);
	VirtualProtect((LPVOID)(rccheck_function), 1, PAGE_EXECUTE_READWRITE, &nOldProtect);

	
	*(BYTE*)(rccheck_function) = 0xC3;

	return [&]() {
		
		*(int*)flag1 = flag1_val;
		*(int*)flag2 = flag2_val;
		*(BYTE*)(rccheck_function) = OldJump;
		VirtualProtect((PVOID)(rccheck_function), 1, nOldProtect, &nOldProtect);
	};
}
void Walkspeed(int State, const char *User, int Speed) {
	auto rt_unhook = Returncheck();
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Players");

	lua.getfield(State, -1, "FindFirstChild");
	lua.pushvalue(State, -2);
	lua.pushstring(State, User);
	lua.pcall(State, 2, 1, 0);
	lua.getfield(State, -1, "Character");
	lua.getfield(State, -1, "FindFirstChild");
	lua.pushvalue(State, -2);
	lua.pushstring(State, "Humanoid");
	lua.pcall(State, 2, 1, 0);
	lua.pushnumber(State, Speed);
	lua.setfield(State, -2, "WalkSpeed");
	rt_unhook();
}

void Forcefield(int State, const char *User) {
	auto rt_unhook = Returncheck();
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Players");
	lua.getfield(State, -1, User);

	lua.getfield(State, -1, "Character");

	lua.getglobal(State, "Instance");

	lua.getfield(State, -1, "new");
	lua.pushstring(State, "ForceField");
	lua.pushvalue(State, -4);
	lua.pcall(State, 2, 1, 0);
	rt_unhook();

}

void Kill(int State, const char *User) {
	auto rt_unhook = Returncheck();
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Players");
	lua.getfield(State, -1, User);

	lua.getfield(State, -1, "Character");


	lua.getfield(State, -1, "BreakJoints");
	lua.pushvalue(State, -2);
	lua.pcall(State, 1, 0, 0);
	rt_unhook();

}

void Loopkill(int State, const char *User) {
	auto rt_unhook = Returncheck();
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Players");
	lua.getfield(State, -1, User);

	lua.getfield(State, -1, "Character");


	lua.getfield(State, -1, "BreakJoints");
	lua.pushvalue(State, -2);
	lua.pcall(State, 1, 0, 0);
	rt_unhook();

}

void Skybox(int State) {
	auto rt_unhook = Returncheck();
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Lighting");

	lua.getglobal(State, "Instance");

	lua.getfield(State, -1, "new");
	lua.pushstring(State, "Sky");
	lua.pushvalue(State, -4);
	lua.pcall(State, 2, 1, 0);

	rt_unhook();
}

void RemoveSkybox(int State) {
	auto rt_unhook = Returncheck();
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Lighting");

	lua.getfield(State, -1, "Sky");
	lua.getfield(State, -1, "Destroy");
	lua.pushvalue(State, -2);
	lua.pcall(State, 1, 0, 0);
	rt_unhook();
}

void Mesh(int State, const char *User) {
	auto rt_unhook = Returncheck();
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Players");
	lua.getfield(State, -1, User);

	lua.getfield(State, -1, "Character");
	lua.getfield(State, -1, "Torso");
	lua.getglobal(State, "Instance");

	lua.getfield(State, -1, "new");
	lua.pushstring(State, "SpecialMesh");
	lua.pushvalue(State, -4);
	lua.pcall(State, 2, 1, 0);

	lua.pop(State, 2);


	lua.pop(State, 4);
	rt_unhook();
}

void Particle(int State, const char *User) {
	auto rt_unhook = Returncheck();
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Players");
	lua.getfield(State, -1, User);

	lua.getfield(State, -1, "Character");
	lua.getfield(State, -1, "Head");
	lua.getglobal(State, "Instance");

	lua.getfield(State, -1, "new");
	lua.pushstring(State, "ParticleEmitter");
	lua.pushvalue(State, -4);
	lua.pcall(State, 2, 1, 0);

	lua.pop(State, 2);


	lua.pop(State, 4);
	rt_unhook();
}

void BlockHead(int State, const char *User) {
	auto rt_unhook = Returncheck();
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Players");
	lua.getfield(State, -1, User);

	lua.getfield(State, -1, "Character");
	lua.getfield(State, -1, "Head");
	lua.getfield(State, -1, "Mesh");
	lua.getfield(State, -1, "Destroy");
	lua.pushvalue(State, -2);
	lua.pcall(State, 1, 0, 0);
	rt_unhook();
}



void Sparkles(int State, const char *User) {
	auto rt_unhook = Returncheck();
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Players");
	lua.getfield(State, -1, User);

	lua.getfield(State, -1, "Character");
	lua.getfield(State, -1, "Head");
	lua.getglobal(State, "Instance");

	lua.getfield(State, -1, "new");
	lua.pushstring(State, "Sparkles");
	lua.pushvalue(State, -4);
	lua.pcall(State, 2, 1, 0);

	lua.pop(State, 2);


	lua.pop(State, 4);
	rt_unhook();
}

void Kick(int State, const char *User) {
	auto rt_unhook = Returncheck();
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Lighting");

	lua.getfield(State, -1, "Sky");
	lua.getfield(State, -1, "Destroy");
	lua.pushvalue(State, -2);
	lua.pcall(State, 1, 0, 0);
	rt_unhook();
}


void UnFF(int State, const char *user) {
	
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Players");
	lua.getfield(State, -1, user);

	lua.getfield(State, -1, "Character");


	lua.getfield(State, -1, "FindFirstChild");
	lua.pushvalue(State, -2);
	lua.pushstring(State, "ForceField");
	lua.pcall(State, 2, 1, 0);

	lua.pushnil(State);
	lua.setfield(State, -2, "Parent");

	
	lua.pop(State, 1);


	lua.pop(State, 4);
	


}

void Fire(int State, const char *user) {
	auto rt_unhook = Returncheck();
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Players");
	lua.getfield(State, -1, user);

	lua.getfield(State, -1, "Character");
	lua.getfield(State, -1, "Head");
	lua.getglobal(State, "Instance");

	lua.getfield(State, -1, "new");
	lua.pushstring(State, "Fire");
	lua.pushvalue(State, -4);
	lua.pcall(State, 2, 1, 0);

	lua.pop(State, 2);


	lua.pop(State, 4);
	rt_unhook();

}

void Bonfire(int State, const char *user) {
	auto rt_unhook = Returncheck();
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Players");
	lua.getfield(State, -1, user);

	lua.getfield(State, -1, "Character");
	lua.getfield(State, -1, "Head");
	lua.getglobal(State, "Instance");

	lua.getfield(State, -1, "new");
	lua.pushstring(State, "Fire");
	lua.pushvalue(State, -4);
	lua.pcall(State, 2, 1, 0);

	lua.pop(State, 2);


	lua.pop(State, 4);

	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Players");
	lua.getfield(State, -1, user);
	lua.getfield(State, -1, "Character");
	lua.getfield(State, -1, "Head");
	lua.getfield(State, -1, "Fire");
	lua.pushnumber(State, 90);
	lua.setfield(State, -2, "Size");
	rt_unhook();
}

void Smoke(int State, const char *user) {
	auto rt_unhook = Returncheck();
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Players");
	lua.getfield(State, -1, user);

	lua.getfield(State, -1, "Character");
	lua.getfield(State, -1, "Head");
	lua.getglobal(State, "Instance");

	lua.getfield(State, -1, "new");
	lua.pushstring(State, "Smoke");
	lua.pushvalue(State, -4);
	lua.pcall(State, 2, 1, 0);

	lua.pop(State, 2);


	lua.pop(State, 4);
	rt_unhook();

}

void God(int State, const char *User) {
	auto rt_unhook = Returncheck();

	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Players");
	lua.getfield(State, -1, User);

	lua.getfield(State, -1, "Character");


	lua.getfield(State, -1, "FindFirstChild");
	lua.pushvalue(State, -2);
	lua.pushstring(State, "Humanoid");
	lua.pcall(State, 2, 1, 0);


	lua.getglobal(State, "math");

	lua.getfield(State, -1, "huge");
	lua.setfield(State, -3, "MaxHealth");

	lua.pop(State, 1);

	lua.getfield(State, -1, "MaxHealth");
	lua.setfield(State, -2, "Health");
	rt_unhook();

}

void TimeSet(int State, double time) {
	auto rt_unhook = Returncheck();
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Lighting");

	lua.pushnumber(State, time);
	lua.setfield(State, -2, "TimeOfDay");
	rt_unhook();
}

void NoHead(int State, const char *user) {
	auto rt_unhook = Returncheck();
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Players");

	lua.getfield(State, -1, "FindFirstChild");
	lua.pushvalue(State, -2);
	lua.pushstring(State, user);
	lua.pcall(State, 2, 1, 0);
	lua.getfield(State, -1, "Character");
	lua.getfield(State, -1, "Head");
	lua.pushnumber(State, 1);

	lua.setfield(State, -2, "Transparency");

	rt_unhook();
}

void NoRleg(int State, const char *user) {
	auto rt_unhook = Returncheck();
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Players");

	lua.getfield(State, -1, "FindFirstChild");
	lua.pushvalue(State, -2);
	lua.pushstring(State, user);
	lua.pcall(State, 2, 1, 0);
	lua.getfield(State, -1, "Character");
	lua.getfield(State, -1, "Right Leg");
	lua.pushnumber(State, 1);

	lua.setfield(State, -2, "Transparency");
	rt_unhook();
}
void NoLleg(int State, const char *user) {
	auto rt_unhook = Returncheck();
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Players");

	lua.getfield(State, -1, "FindFirstChild");
	lua.pushvalue(State, -2);
	lua.pushstring(State, user);
	lua.pcall(State, 2, 1, 0);
	lua.getfield(State, -1, "Character");
	lua.getfield(State, -1, "Left Leg");
	lua.pushnumber(State, 1);

	lua.setfield(State, -2, "Transparency");
	rt_unhook();
}
void NoRarm(int State, const char *user) {
	auto rt_unhook = Returncheck();
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Players");

	lua.getfield(State, -1, "FindFirstChild");
	lua.pushvalue(State, -2);
	lua.pushstring(State, user);
	lua.pcall(State, 2, 1, 0);
	lua.getfield(State, -1, "Character");
	lua.getfield(State, -1, "Right Arm");
	lua.pushnumber(State, 1);

	lua.setfield(State, -2, "Transparency");
	rt_unhook();
}
void NoLarm(int State, const char *user) {
	auto rt_unhook = Returncheck();
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Players");

	lua.getfield(State, -1, "FindFirstChild");
	lua.pushvalue(State, -2);
	lua.pushstring(State, user);
	lua.pcall(State, 2, 1, 0);
	lua.getfield(State, -1, "Character");
	lua.getfield(State, -1, "Left Arm");
	lua.pushnumber(State, 1);

	lua.setfield(State, -2, "Transparency");
	rt_unhook();
}


void NoTorso(int State, const char *user) {
	auto rt_unhook = Returncheck();
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Players");

	lua.getfield(State, -1, "FindFirstChild");
	lua.pushvalue(State, -2);
	lua.pushstring(State, user);
	lua.pcall(State, 2, 1, 0);
	lua.getfield(State, -1, "Character");
	lua.getfield(State, -1, "Torso");
	lua.pushnumber(State, 1);

	lua.setfield(State, -2, "Transparency");
	rt_unhook();
}

void JumpPower(int State, const char *User, int JumpPower) {
	auto rt_unhook = Returncheck();
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Players");

	lua.getfield(State, -1, "FindFirstChild");
	lua.pushvalue(State, -2);
	lua.pushstring(State, User);
	lua.pcall(State, 2, 1, 0);
	lua.getfield(State, -1, "Character");
	lua.getfield(State, -1, "FindFirstChild");
	lua.pushvalue(State, -2);
	lua.pushstring(State, "Humanoid");
	lua.pcall(State, 2, 1, 0);
	lua.pushnumber(State, JumpPower);
	lua.setfield(State, -2, "JumpPower");
	rt_unhook();
}


void Btools(int State, const char *User) {
	auto rt_unhook = Returncheck();
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Players");
	lua.getfield(State, -1, User);

	lua.getfield(State, -1, "Backpack");

	lua.getglobal(State, "Instance");

	lua.getfield(State, -1, "new");
	lua.pushstring(State, "HopperBin");
	lua.pushvalue(State, -4);
	lua.pcall(State, 2, 1, 0);

	lua.pop(State, 2);


	lua.pop(State, 4);
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Players");
	lua.getfield(State, -1, User);

	lua.getfield(State, -1, "Backpack");
	lua.getfield(State, -1, "HopperBin");
	lua.pushstring(State, "HopperBinOriginal");
	lua.setfield(State, -2, "Name");
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Players");
	lua.getfield(State, -1, User);

	lua.getfield(State, -1, "Backpack");
	lua.getfield(State, -1, "HopperBinOriginal");
	lua.pushstring(State, "Clone");
	lua.setfield(State, -2, "BinType");



	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Players");
	lua.getfield(State, -1, User);

	lua.getfield(State, -1, "Backpack");

	lua.getglobal(State, "Instance");

	lua.getfield(State, -1, "new");
	lua.pushstring(State, "HopperBin");
	lua.pushvalue(State, -4);
	lua.pcall(State, 2, 1, 0);

	lua.pop(State, 2);


	lua.pop(State, 4);

	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Players");
	lua.getfield(State, -1, User);

	lua.getfield(State, -1, "Backpack");

	lua.getfield(State, -1, "HopperBin");
	lua.pushstring(State, "HopperBin2");
	lua.setfield(State, -2, "Name");

	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Players");
	lua.getfield(State, -1, User);

	lua.getfield(State, -1, "Backpack");
	lua.getfield(State, -1, "HopperBin2");

	lua.pushstring(State, "Grab");
	lua.setfield(State, -2, "BinType");

	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Players");
	lua.getfield(State, -1, User);

	lua.getfield(State, -1, "Backpack");

	lua.getglobal(State, "Instance");

	lua.getfield(State, -1, "new");
	lua.pushstring(State, "HopperBin");
	lua.pushvalue(State, -4);
	lua.pcall(State, 2, 1, 0);

	lua.pop(State, 2);


	lua.pop(State, 4);

	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Players");
	lua.getfield(State, -1, User);

	lua.getfield(State, -1, "Backpack");

	lua.getfield(State, -1, "HopperBin");
	lua.pushstring(State, "HopperBin3");
	lua.setfield(State, -2, "Name");

	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Players");
	lua.getfield(State, -1, User);

	lua.getfield(State, -1, "Backpack");
	lua.getfield(State, -1, "HopperBin3");
	lua.pushstring(State, "Hammer");
	lua.setfield(State, -2, "BinType");
	rt_unhook();
}

void Music(int State, const char *id, string str) {



}

void Music1(int State, const char *id, string str) {
	auto rt_unhook = Returncheck();
	int soundVolume = 1;
	int soundPitch = 1;
	string Sound = "rbxassetid://" + str;
	const char *b = Sound.c_str();


	lua.getglobal(State, "Instance");

	lua.getglobal(State, "game");

	lua.getfield(State, -1, "GetService");
	lua.pushvalue(State, -2);
	lua.pushstring(State, "Workspace");
	lua.pcall(State, 2, 1, 0);
	

	lua.getfield(State, -1, "FindFirstChild");
	lua.pushvalue(State, -2);
	lua.pushstring(State, "MHolder");
	lua.pcall(State, 2, 1, 0);


	lua.pop(State, 1); 

	lua.getfield(State, -3, "new");
	lua.pushstring(State, "Model");
	lua.pushvalue(State, -3);
	lua.pcall(State, 2, 1, 0);

	lua.pushstring(State, "MHolder");
	lua.setfield(State, -2, "Name");

	//

	//
	lua.getfield(State, -4, "new");
	lua.pushstring(State, "Sound");
	lua.pushvalue(State, -3);
	lua.pcall(State, 2, 1, 0);

	lua.pushnumber(State, soundVolume);
	lua.setfield(State, -2, "Volume");

	lua.pushnumber(State, soundPitch);
	lua.setfield(State, -2, "Pitch");

	lua.pushstring(State, b);
	lua.setfield(State, -2, "SoundId");

	lua.getfield(State, -1, "Play");
	lua.pushvalue(State, -2);
	lua.pcall(State, 1, 0, 0);

	rt_unhook();



}

void GuestChat(int State) {
	auto rt_unhook = Returncheck();

	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Chat");
	lua.getfield(State, -1, "ClientChatModules");

	lua.getfield(State, -1, "CommandModules");

	lua.getfield(State, -1, "SwallowGuestChat");
	lua.getfield(State, -1, "Destroy");
	lua.pushvalue(State, -2);
	lua.pcall(State, 1, 0, 0);
	rt_unhook();
}



void TP(int State, const char *user1, const char *user2) {

	auto rt_unhook = Returncheck();


    

	lua.pop(State, 2);

	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Players");

	lua.getfield(State, -1, "FindFirstChild");
	lua.pushvalue(State, -2);
	lua.pushstring(State, user2);
	lua.pcall(State, 2, 1, 0);
	lua.getfield(State, -1, "Character");
	lua.getfield(State, -1, "FindFirstChild");
	lua.pushvalue(State, -2);
	lua.pushstring(State, "Torso");
	lua.pcall(State, 2, 1, 0);
	lua.getfield(State, -1, "CFrame");

	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Players");

	lua.getfield(State, -1, "FindFirstChild");
	lua.pushvalue(State, -2);
	lua.pushstring(State, user1);
	lua.pcall(State, 2, 1, 0);
	lua.getfield(State, -1, "Character");
	lua.getfield(State, -1, "FindFirstChild");
	lua.pushvalue(State, -2);
	lua.pushstring(State, "HumanoidRootPart");
	lua.pcall(State, 2, 1, 0);
	lua.pushvalue(State, -6);
	lua.setfield(State, -2, "CFrame");

	lua.pop(State, 1);

	lua.pop(State, 1);

	lua.pop(State, 4);


	lua.pop(State, 1);

	lua.pop(State, 1);

	lua.pop(State, 3);
	rt_unhook();
}

void Fling(int State, const char *user) {
	auto rt_unhook = Returncheck();
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Players");

	lua.getfield(State, -1, "FindFirstChild");
	lua.pushvalue(State, -2);
	lua.pushstring(State, user);
	lua.pcall(State, 2, 1, 0);
	lua.getfield(State, -1, "Character");
	lua.getfield(State, -1, "FindFirstChild");
	lua.pushvalue(State, -2);
	lua.pushstring(State, "Humanoid");
	lua.pcall(State, 2, 1, 0);
	lua.pushnumber(State, 9001);
	lua.setfield(State, -2, "JumpPower");
	Sleep(400);
	lua.pushnumber(State, 1);
	lua.setfield(State, -2, "Jump");
	rt_unhook();
}

void Freeze(int State, const char *user) {

	auto rt_unhook = Returncheck();

	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Players");

	lua.getfield(State, -1, "FindFirstChild");
	lua.pushvalue(State, -2);
	lua.pushstring(State, user);
	lua.pcall(State, 2, 1, 0);
	lua.getfield(State, -1, "Character");
	lua.getfield(State, -1, "FindFirstChild");
	lua.pushvalue(State, -2);
	lua.pushstring(State, "Humanoid");
	lua.pcall(State, 2, 1, 0);
	lua.pushnumber(State, 0);
	lua.setfield(State, -2, "WalkSpeed");

	rt_unhook();
}

void Thaw(int State, const char *user) {
	auto rt_unhook = Returncheck();
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Players");

	lua.getfield(State, -1, "FindFirstChild");
	lua.pushvalue(State, -2);
	lua.pushstring(State, user);
	lua.pcall(State, 2, 1, 0);
	lua.getfield(State, -1, "Character");
	lua.getfield(State, -1, "FindFirstChild");
	lua.pushvalue(State, -2);
	lua.pushstring(State, "Humanoid");
	lua.pcall(State, 2, 1, 0);
	lua.pushnumber(State, 16);
	lua.setfield(State, -2, "WalkSpeed");
	rt_unhook();
}

void Sit(int State, const char *user) {
	auto rt_unhook = Returncheck();
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Players");

	lua.getfield(State, -1, "FindFirstChild");
	lua.pushvalue(State, -2);
	lua.pushstring(State, user);
	lua.pcall(State, 2, 1, 0);
	lua.getfield(State, -1, "Character");
	lua.getfield(State, -1, "FindFirstChild");
	lua.pushvalue(State, -2);
	lua.pushstring(State, "Humanoid");
	lua.pcall(State, 2, 1, 0);
	lua.pushnumber(State, 1);
	lua.setfield(State, -2, "Sit");
	rt_unhook();
}

void SetMaxHealth(int State, const char *user, int Health) {
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Players");
	lua.getfield(State, -1, "FindFirstChild");
	lua.pushvalue(State, -2);
	lua.pushstring(State, user);
	lua.pcall(State, 2, 1, 0);
	lua.getfield(State, -1, "Character");
	lua.getfield(State, -1, "FindFirstChild");
	lua.pushvalue(State, -2);
	lua.pushstring(State, "Humanoid");
	lua.pcall(State, 2, 1, 0);
	lua.pushnumber(State, Health);
	lua.setfield(State, -2, "MaxHealth");
}

void SetHealth(int State, const char *user, int Health) {
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Players");

	lua.getfield(State, -1, "FindFirstChild");
	lua.pushvalue(State, -2);
	lua.pushstring(State, user);
	lua.pcall(State, 2, 1, 0);
	lua.getfield(State, -1, "Character");
	lua.getfield(State, -1, "FindFirstChild");
	lua.pushvalue(State, -2);
	lua.pushstring(State, "Humanoid");
	lua.pcall(State, 2, 1, 0);
	lua.pushnumber(State, Health);
	lua.setfield(State, -2, "Health");
}

void Demigod(int State, const char *user) {
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Players");
	lua.getfield(State, -1, "FindFirstChild");
	lua.pushvalue(State, -2);
	lua.pushstring(State, user);
	lua.pcall(State, 2, 1, 0);
	lua.getfield(State, -1, "Character");
	lua.getfield(State, -1, "FindFirstChild");
	lua.pushvalue(State, -2);
	lua.pushstring(State, "Humanoid");
	lua.pcall(State, 2, 1, 0);
	lua.pushnumber(State, 2147483647);
	lua.setfield(State, -2, "MaxHealth");
	lua.pushnumber(State, 2147483647);
	lua.setfield(State, -2, "Health");
}

bool getFiltering(int State) {
	auto rt_unhook = Returncheck();
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Workspace");
	lua.getfield(State, -1, "FilteringEnabled");
	bool isFiltered = lua.toboolean(State, -1);
	rt_unhook();
	if (isFiltered) {
		cout << "Filtering enabled!" << endl;
	}
	else {
		cout << "Filtering is not enabled." << endl;
	}
	return false;
	
}

void Fog(int State) {
	auto rt_unhook = Returncheck();
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Lighting");

	lua.pushnumber(State, 0);
	lua.setfield(State, -2, "FogEnd");
	rt_unhook();
}

void DestroyFog(int State) {
	auto rt_unhook = Returncheck();
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Lighting");

	lua.pushnumber(State, 100000);
	lua.setfield(State, -2, "FogEnd");
	rt_unhook();
}

void SetBrightness(int State, double brightness) {
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Lighting");

	lua.pushnumber(State, brightness);
	lua.setfield(State, -2, "Brightness");
}

void ClearTerrain(int State) {
	auto rt_unhook = Returncheck();
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Workspace");
	lua.getfield(State, -1, "Terrain");
	lua.getfield(State, -1, "Clear");
	lua.pushvalue(State, -2);
	lua.pcall(State, 1, 0, 0);
	rt_unhook();
}

void Stat(int State, const char *user, const char *stat, int value) {
	auto rt_unhook = Returncheck();
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Players");
	lua.getfield(State, -1, user);
	lua.getfield(State, -1, "leaderstats");
	lua.getfield(State, -1, stat);
	lua.pushnumber(State, value);
	lua.setfield(State, -2, "Value");
	rt_unhook();
}

void StatCreate(int State, const char *user) {
	auto rt_unhook = Returncheck();
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Players");
	lua.getfield(State, -1, user);

	lua.getfield(State, -1, "leaderstats");

	lua.getglobal(State, "Instance");

	lua.getfield(State, -1, "new");
	lua.pushstring(State, "IntValue");
	lua.pushvalue(State, -4);
	lua.pcall(State, 2, 1, 0);

	lua.pop(State, 2);


	lua.pop(State, 4);

	rt_unhook();

}

void Message(int State, const char *message) {
	auto rt_unhook = Returncheck();
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Workspace");
	lua.getglobal(State, "Instance");

	lua.getfield(State, -1, "new");
	lua.pushstring(State, "Message");
	lua.pushvalue(State, -4);
	lua.pcall(State, 2, 1, 0);

	lua.pop(State, 2);


	lua.pop(State, 4);


	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Workspace");
	lua.getfield(State, -1, "Message");
	lua.pushstring(State, message);
	lua.setfield(State, -2, "Text");
	rt_unhook();
}

void RenameStat(int State, const char *user, const char *stat, const char *name) {
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Players");
	lua.getfield(State, -1, user);
	lua.getfield(State, -1, "leaderstats");
	lua.getfield(State, -1, stat);
	lua.pushstring(State, name);
	lua.setfield(State, -2, "Name");
}

void Char(int State, const char *user, int id) {
	auto rt_unhook = Returncheck();
	string playr = "http://www.roblox.com/asset/CharacterFetch.ashx?userId=" + id;
	const char * b = playr.c_str();
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Players");
	lua.getfield(State, -1, user);
	lua.pushstring(State, b);
	lua.setfield(State, -2, "CharacterAppearance");
	rt_unhook();
}


void PrivateMessage(int State, const char *user, const char *message) {
	auto rt_unhook = Returncheck();
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Players");
	lua.getfield(State, -1, user);
	lua.getfield(State, -1, "PlayerGui");
	lua.getglobal(State, "Instance");

	lua.getfield(State, -1, "new");
	lua.pushstring(State, "Message");
	lua.pushvalue(State, -4);
	lua.pcall(State, 2, 1, 0);

	lua.pop(State, 2);


	lua.pop(State, 4);


	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Players");
	lua.getfield(State, -1, user);
	lua.getfield(State, -1, "PlayerGui");
	lua.getfield(State, -1, "Message");
	lua.pushstring(State, message);
	lua.setfield(State, -2, "Text");

	Sleep(4000);
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Players");
	lua.getfield(State, -1, user);
	lua.getfield(State, -1, "PlayerGui");
	lua.getfield(State, -1, "Message");
	lua.getfield(State, -1, "Destroy");
	lua.pushvalue(State, -2);
	lua.pcall(State, 1, 0, 0);
	rt_unhook();
}

void RemoveMessage(int State) {
	Sleep(5000);
	auto rt_unhook = Returncheck();
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Workspace");
	lua.getfield(State, -1, "Message");
	lua.getfield(State, -1, "Destroy");
	lua.pushvalue(State, -2);
	lua.pcall(State, 1, 0, 0);
	rt_unhook();
}

int StopMusic(int State) {
	auto rt_unhook = Returncheck();
	lua.getglobal(State, "game");

	lua.getfield(State, -1, "GetService");
	lua.pushvalue(State, -2);
	lua.pushstring(State, "Workspace");
	lua.pcall(State, 2, 1, 0);
	//

	lua.getfield(State, -1, "FindFirstChild");
	lua.pushvalue(State, -2);
	lua.pushstring(State, "MHolder");
	lua.pcall(State, 2, 1, 0);

	if (!lua.isnil(State, -1)) {
		lua.getfield(State, -1, "GetChildren");
		lua.pushvalue(State, -2);
		lua.pcall(State, 1, 1, 0);

		lua.pushnil(State);

		while (lua.next(State, -2)) {
			lua.getfield(State, -1, "ClassName");
			std::string classtype = lua.tostring(State, -1);
			lua.pop(State, 1);

			if (classtype == "Sound") {
				lua.getfield(State, -1, "Stop");
				lua.pushvalue(State, -2);
				lua.pcall(State, 1, 0, 0);


				// Fuck ROBLOX's sound engine

				//lua.getfield(State,-1,"Destroy");
				//lua.pushvalue(State,-2);
				//lua.pcall(State,1,0,0);
			}

			lua.pop(State, 1);
		}
	}

	return 0;
	rt_unhook();
	
}

void RemoveTools(int State, const char *user, const char *tool) {
	auto rt_unhook = Returncheck();
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Players");
	lua.getfield(State, -1, user);
	lua.getfield(State, -1, "Backpack");
	lua.getfield(State, -1, tool);
	lua.getfield(State, -1, "Destroy");
	lua.pushvalue(State, -2);
	lua.pcall(State, 1, 0, 0);
	rt_unhook();
}

void GlobalShadows(int State) {
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Lighting");
	lua.pushstring(State, false);
	lua.setfield(State, -2, "GlobalShadows");
}
void Print(int State, const char *msg) {
	auto rt_unhook = Returncheck();
	lua.getglobal(State, "print");
	lua.pushstring(State, msg);
	lua.pcall(State, 1, 0, 0);
	rt_unhook();
}

void EnableShadows(int State) {
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Lighting");
	lua.pushnumber(State, 1);
	lua.setfield(State, -2, "GlobalShadows");
}



void DisableTurns(int State, const char *user) {
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Workspace");
	lua.getfield(State, -1, user);
	lua.getfield(State, -1, "Humanoid");
	lua.pushnumber(State, 1);
	lua.setfield(State, -2, "AutoRotate");
}

void EnableTurns(int State, const char *user) {
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Workspace");
	lua.getfield(State, -1, user);
	lua.getfield(State, -1, "Humanoid");
	lua.pushnumber(State, 1);
	lua.setfield(State, -2, "AutoRotate");
}


void QuickSand(int State, const char *user) {
	auto rt_unhook = Returncheck();
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Workspace");
	lua.getfield(State, -1, user);
	lua.getfield(State, -1, "Humanoid");
	lua.pushnumber(State, 1);
	lua.setfield(State, -2, "PlatformStand");

	Sleep(8000);

	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Workspace");
	lua.getfield(State, -1, user);
	lua.getfield(State, -1, "Humanoid");
	lua.pushstring(State, false);
	lua.setfield(State, -2, "PlatformStand");
	rt_unhook();

}

void DisableAnimations(int State, const char *user) {
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Workspace");
	lua.getfield(State, -1, user);
	lua.getfield(State, -1, "Animate");
	lua.pushnumber(State, 1);
	lua.setfield(State, -2, "Disabled");
}

void NoclipLA(int State, const char *user) {
	auto rt_unhook = Returncheck();
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Players");

	lua.getfield(State, -1, "FindFirstChild");
	lua.pushvalue(State, -2);
	lua.pushstring(State, user);
	lua.pcall(State, 2, 1, 0);
	lua.getfield(State, -1, "Character");
	lua.getfield(State, -1, "Left Leg");
	lua.pushnumber(State, 1);

	lua.setfield(State, -2, "CanCollide");
	rt_unhook();
}
void NoclipRA(int State, const char *user) {
	auto rt_unhook = Returncheck();
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Players");

	lua.getfield(State, -1, "FindFirstChild");
	lua.pushvalue(State, -2);
	lua.pushstring(State, user);
	lua.pcall(State, 2, 1, 0);
	lua.getfield(State, -1, "Character");
	lua.getfield(State, -1, "Left Leg");
	lua.pushnumber(State, 1);

	lua.setfield(State, -2, "CanCollide");
	rt_unhook();
}
void NoclipLL(int State, const char *user) {
	auto rt_unhook = Returncheck();
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Players");

	lua.getfield(State, -1, "FindFirstChild");
	lua.pushvalue(State, -2);
	lua.pushstring(State, user);
	lua.pcall(State, 2, 1, 0);
	lua.getfield(State, -1, "Character");
	lua.getfield(State, -1, "Left Leg");
	lua.pushnumber(State, 1);

	lua.setfield(State, -2, "CanCollide");
	rt_unhook();
}
void NoclipRL(int State, const char *user) {
	auto rt_unhook = Returncheck();
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Players");

	lua.getfield(State, -1, "FindFirstChild");
	lua.pushvalue(State, -2);
	lua.pushstring(State, user);
	lua.pcall(State, 2, 1, 0);
	lua.getfield(State, -1, "Character");
	lua.getfield(State, -1, "Left Leg");
	lua.pushnumber(State, 1);

	lua.setfield(State, -2, "CanCollide");
	rt_unhook();
}

void EnableAnimations(int State, const char *user) {
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Workspace");
	lua.getfield(State, -1, user);
	lua.getfield(State, -1, "Animate");
	lua.pushstring(State, false);
	lua.setfield(State, -2, "Disabled");
}

void Noob(int State, const char *user) {
	auto rt_unhook = Returncheck();
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Players");
	lua.getfield(State, -1, user);
	lua.pushstring(State, false);
	lua.setfield(State, -2, "CanLoadCharacterAppearance");
	rt_unhook();

}

void Regular(int State, const char *user) {
	auto rt_unhook = Returncheck();
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Players");
	lua.getfield(State, -1, user);
	lua.pushnumber(State, 1);
	lua.setfield(State, -2, "CanLoadCharacterAppearance");
	rt_unhook();
}

void QuickSand1(int State, const char *user) {
	auto rt_unhook = Returncheck();
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Workspace");
	lua.getfield(State, -1, user);
	lua.getfield(State, -1, "Humanoid");
	lua.pushnumber(State, 1);
	lua.setfield(State, -2, "PlatformStand");
	rt_unhook();
}

void RagdollEnd(int State, const char *user) {
	auto rt_unhook = Returncheck();
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Workspace");
	lua.getfield(State, -1, user);
	lua.getfield(State, -1, "Humanoid");
	lua.pushstring(State, false);
	lua.setfield(State, -2, "PlatformStand");
	rt_unhook();

}

void Warn(int State, const char *msg) {
	auto rt_unhook = Returncheck();
	lua.getglobal(State, "warn");
	lua.pushstring(State, msg);
	lua.pcall(State, 1, 0, 0);
	rt_unhook();
}

void RemoveSparkles(int State, const char *user) {
	auto rt_unhook = Returncheck();
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Players");
	lua.getfield(State, -1, user);

	lua.getfield(State, -1, "Character");
	lua.getfield(State, -1, "Head");
	lua.getfield(State, -1, "Sparkles");
	lua.getfield(State, -1, "Destroy");
	lua.pushvalue(State, -2);
	lua.pcall(State, 1, 0, 0);
	rt_unhook();
}

void Ragdoll1(int State, const char *user) {
	auto rt_unhook = Returncheck();
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Players");
	lua.getfield(State, -1, user);

	lua.getfield(State, -1, "Character");
	lua.getfield(State, -1, "Humanoid");
	lua.getfield(State, -1, "Destroy");
	lua.pushvalue(State, -2);
	lua.pcall(State, 1, 0, 0);
	rt_unhook();
}
void RemoveRagdoll1(int State, const char *user) {
	auto rt_unhook = Returncheck();
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Players");
	lua.getfield(State, -1, user);

	lua.getfield(State, -1, "Character");
	lua.getglobal(State, "Instance");
	lua.getfield(State, -1, "new");
	lua.pushstring(State, "Humanoid");
	lua.pushvalue(State, -4);
	lua.pcall(State, 2, 1, 0);
	rt_unhook();
}
void RemoveFire(int State, const char *user) {
	auto rt_unhook = Returncheck();
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Players");
	lua.getfield(State, -1, user);

	lua.getfield(State, -1, "Character");
	lua.getfield(State, -1, "Head");
	lua.getfield(State, -1, "Fire");
	lua.getfield(State, -1, "Destroy");
	lua.pushvalue(State, -2);
	lua.pcall(State, 1, 0, 0);
	rt_unhook();
}

void Invisible(int State, const char *user) {
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Players");
	lua.getfield(State, -1, user);

	lua.getfield(State, -1, "Character");
	lua.getfield(State, -1, "Torso");
	lua.getfield(State, -1, "Transparency");
	lua.pushnumber(State, -1);
}
void RemoveFF(int State, const char *user) {
	auto rt_unhook = Returncheck();
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Players");
	lua.getfield(State, -1, user);

	lua.getfield(State, -1, "Character");
	lua.getfield(State, -1, "ForceField");
	lua.getfield(State, -1, "Destroy");
	lua.pushvalue(State, -2);
	lua.pcall(State, 1, 0, 0);
	rt_unhook();

}

void Check(int State) {
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Players");
	lua.getfield(State, -1, "OffsetV");
	lua.getfield(State, -1, "UserId");
}

void CrashPlayer(int State, const char *user) {
	auto rt_unhook = Returncheck();
	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Players");
	lua.getfield(State, -1, user);
	lua.getfield(State, -1, "Backpack");
	lua.getglobal(State, "Instance");

	lua.getfield(State, -1, "new");
	lua.pushstring(State, "HopperBin");
	lua.pushvalue(State, -4);
	lua.pcall(State, 2, 1, 0);

	lua.getglobal(State, "game");
	lua.getfield(State, -1, "Players");
	lua.getfield(State, -1, user);
	lua.getfield(State, -1, "Backpack");
	lua.getfield(State, -1, "HooperBin");
	lua.getfield(State, -1, "Destroy");
	lua.pushvalue(State, -2);
	lua.pcall(State, 1, 0, 0);
	rt_unhook();
}

