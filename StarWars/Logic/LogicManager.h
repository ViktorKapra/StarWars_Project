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
	void addPlanet(Planet const&);
	void addJedi(TextContainer const& planetName, Jedi const&);
	void removeJedi(TextContainer const& planetName, TextContainer const& jediName);
	void changeJediRank(TextContainer const& jediName, double mult, int(*f)(Rang));
	Jedi* findJedi(TextContainer const& jediName);
	void print(TextContainer const& name);
	void getMostJedi(TextContainer const& planetName, bool(*f)(Jedi const&, Jedi const&));
	void getYoungestJedi(TextContainer const& planetName, Rang rang);

	void getMostUsedSaberColor(TextContainer const& planetName, Rang rang);

};
