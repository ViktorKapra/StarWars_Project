#include "UI.h"
#include "..\Logic\TextContainer.h"
#include "CommandEnums.h"
#include "..\Logic\LogicManager.h"
#include <iomanip>

bool UI::fileWasOpened = false;

void UI::startSystem()
{
	std::cout << "Welcome to Jedi Sysytem" << std::endl;
	bool exitCommand = false;

	while (!exitCommand)
	{

		std::cout << "Enter command: ";
		LogicManager lm;
		TextContainer command;
		std::cin >> command;

		if (strcmp(command.getText(), "Open") == 0)
		{
			TextContainer fileName;
			char data[MAX_COMMAND_LENGHT];
			std::cin >> fileName;
			fileName.setText(data);
			lm.openFile(fileName);
			fileWasOpened = true;
		}
		else if (strcmp(command.getText(), "Save") == 0)
		{
			if (fileWasOpened)
			{
				lm.save();
				
			}
			else
			{
				std::cout << "No file was opened to save!" << std::endl;
			}
		}
		else if (strcmp(command.getText(), "SaveAs") == 0)
		{
			if (fileWasOpened)
			{
				TextContainer fileName;
				char data[MAX_COMMAND_LENGHT];
				std::cin >> fileName;
				fileName.setText(data);
				lm.saveAs(fileName);
			}
			else
			{
				std::cout << "There is no open file!";
			}
		}
		else if (strcmp(command.getText(), "Help") == 0)
		{
			this->Help();
		}
		else if (strcmp(command.getText(), "Close") == 0)
		{
			if (fileWasOpened)
			{
				lm.Close();
				fileWasOpened = false;
			}
		}

		else if (strcmp(command.getText(), "add_planet") == 0)
		{

		}
		else if (strcmp(command.getText(), "create_jedi") == 0)
		{

		}
		else if (strcmp(command.getText(), "removeJedi") == 0)
		{

		}
		else if (strcmp(command.getText(), "promote_jedi") == 0)
		{

		}
		else if (strcmp(command.getText(), "demote_jedi") == 0)
		{

		}
		else if (strcmp(command.getText(), "get_strongest_jedi") == 0)
		{

		}
		else if (strcmp(command.getText(), "get_youngest_jedi") == 0)
		{

		}
		else if (strcmp(command.getText(), "get_most_used_saber_color") == 0)
		{

		}
		else if (strcmp(command.getText(), "print") == 0)
		{

		}
		else if (strcmp(command.getText(), "Exit") == 0)
		{
			exitCommand = true;
		}
		else
		{
			//To do <planet_name> <planet_name>
			std::cerr << "Command you wrote is not recognized or "
				<< "file for modification was opened" << std::endl;
		}


	}
}

void UI::Help()
{

	std::cout << "The following commands are supported :" << std::endl;

	std::cout << "  open <file>" << std::setw(30) << " opens <file>" << std::endl;

	std::cout << "  close" << std::setw(30) << "closes currently opened file" << std::endl;
	std::cout << "  save" << std::setw(30) << " saves the currently open file" << std::endl;
	std::cout << "  saveas <file>" << std::setw(40) << "saves the currently open file in <file>" << std::endl;
	std::cout << "  help" << std::setw(30) << " prints this information" << std::endl;
	std::cout << "  exit" << std::setw(30) << " exists the program" << std::endl;

	std::cout << "  add_planet <planet_name> " << std::setw(20) << " add new planet" << std::endl;
	std::cout << "  create_jedi <planet_name> < jedi_name > <jedi_rank> <jedi_age> <saber_color> < jedi_strength> "
		<< std::setw(20) << " create jedi " << std::endl;
	std::cout << "  removeJedi <jedi_name> < planet_name >" << std::setw(20) << " removes jedi from planet" << std::endl;
	std::cout << "  promote_jedi <jedi_name> < multiplier > "
		<< std::setw(30) << " rank up jedi and multiply his strenght" << std::endl;
	std::cout << "  demote_jedi <jedi_name> < multiplier > " << std::setw(30)
		<< "	rank down jedi and multiply his strenght" << std::endl;
	std::cout << "  get_strongest_jedi <planet_name> " << std::setw(40) << " gets the strongest jedi from planet" << std::endl;
	std::cout << "  get_youngest_jedi <planet_name> <jedi_rank> " << std::setw(40) << "gets youngest jedi from planet" << std::endl;
	std::cout << "  get_most_used_saber_color <planet_name> <jedi_rank>" << std::setw(50)
		<< "  gets most used saber color feom planet through jedi with rank " << std::endl;
	std::cout << "  get_most_used_saber_color <planet_name> " << std::setw(40)
		<< " gets most used saber color from planet that is used by Grand_Master" << std::endl;
	std::cout << "  print <planet_name>" << std::setw(20) << " all jedi from planet" << std::endl;
	std::cout << "  print <jedi_name>" << std::setw(20) << "gets infromation about jedi" << std::endl;
	std::cout << "  <planet_name> + < planet_name >" << std::setw(30) << " gets information of jedis of two planets" << std::endl;



}
