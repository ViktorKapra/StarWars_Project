#pragma once
#include<iostream>
#include<fstream>

class UI {
private:
	/// <summary>
	/// The field remember whether the file was opened during the program running 
	/// </summary>
	static bool fileWasOpened;
	static const int MAX_COMMAND_LENGHT = 1024;
public:
	/// <summary>
	/// Function receives commands from the console and invokes fuctions from the LogicManager class
	/// The functions ends when receive command "Exit" 
	/// </summary>
	void startSystem();
	/// <summary>
	/// Display on console every function with parameters and explanation which the app support.
	/// </summary>
	void Help();

};
