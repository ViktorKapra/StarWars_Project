#pragma once
#include "DynamicArray.hpp"
#include "TextContainer.h"
#include"..\Data\Planet.h"
#include <fstream>

class LogicManager
{
private:
	TextContainer fileName;
	DynamicArray<Planet> planets;
	void readPlanets(std::ifstream& is);
	void writePlanets(std::ofstream& os);
	void saveFileWithName(TextContainer const& _fileName);
public:
	void openFile(TextContainer const&);
	void save();
	void saveAs(TextContainer const& _fileName);
};
