#include "UI.h"
#include "..\Logic\TextContainer.h"
#include "CommandEnums.h"



void UI::startSystem() {
	std::cout << "Welcome to Jedi Sysytem"<<std::endl;
	std::cout << "Enter function: ";
	TextContainer command;
	std::cin >> command;
	if (strcmp(command.getText(), "Open"))
	{

	}
	else if (strcmp(command.getText(), "Save"))
	{

	}
	else if (strcmp(command.getText(), "SaveAs"))
	{

	}
	else if (strcmp(command.getText(), "Help"))
	{

	}
	else if (strcmp(command.getText(), "Close"))
	{

	}
	else if (strcmp(command.getText(), "Exit"))
	{

	}
	else
	{
		std::cerr << "Command you wrote is not recognized or "
			<< "file for modification was opened" << std::endl;
	}

}
