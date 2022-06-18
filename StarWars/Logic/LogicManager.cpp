#include "LogicManager.h"


void LogicManager::readPlanets(std::ifstream& is)
{
	int numberOfPlanets = 0;
	is >> numberOfPlanets;
	for (int i = 0; i < numberOfPlanets; i++)
	{
		is >> planets[i];
	}
}
void LogicManager::writePlanets(std::ofstream& os)
{
	unsigned planetsCount = planets.getSize();
	os << planetsCount << std::endl;
	for (int i = 0; i < planetsCount; i++)
	{
		os << planets[i];
	}
}
void LogicManager::saveFileWithName(TextContainer const& _fileName)
{
	std::ofstream ofs;
	ofs.open(_fileName.getText(), std::ios::out);
	writePlanets(ofs);
	std::cout << "Successfully saved " << _fileName.getText() << std::endl;
}

void LogicManager::openFile(TextContainer const& fileName)
{
	if (planets.getSize() > 0)
	{
		planets.Clear();
	}
	std::ifstream is;
	is.open(fileName.getText(), std::ios::in);
	readPlanets(is);
}

void LogicManager::save()
{
	saveFileWithName(fileName);

}

void LogicManager::saveAs(TextContainer const& _fileName)
{
	saveFileWithName(_fileName);
}


