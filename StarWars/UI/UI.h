#pragma once
#include<iostream>
#include<fstream>

class UI {
private:
	static bool fileWasOpened;
	static const int MAX_COMMAND_LENGHT = 1024;
public:

	void startSystem();
	void Help();

};
