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
	/// <summary>
	/// Function get information about the planets and their jedis from file stream
	/// </summary>
	/// <param name="is"></param>
	void readPlanets(std::ifstream& is);
	/// <summary>
	/// Function write information about the planets and their jedis in file stream
	/// </summary>
	/// <param name="os"></param>
	void writePlanets(std::ofstream& os);
	/// <summary>
	/// Function write app information( planets and their jedis) in file with given name
	/// </summary>
	/// <param name="_fileName"></param>
	void saveFileWithName(TextContainer const& _fileName);
public:
	/// <summary>
	/// Function read app information( planets and their jedis) from file with given name
	/// Filename is recorded in fileName field of LogicManager clas
	/// </summary>
	/// <param name=""></param>
	void openFile(TextContainer const&);
	/// <summary>
	/// Funtion saves app information in last opened file
	/// </summary>
	void save();
	/// <summary>
	/// Funtion saves app information in  file with fileName
	/// </summary>
	/// <param name="_fileName"></param>
	void saveAs(TextContainer const& _fileName);
	void addPlanet(Planet const&);
	/// <summary>
	/// Function adds jedi to a planet with given name
	/// If planet not exists occurs message
	/// </summary>
	/// <param name="planetName"></param>
	/// <param name=""></param>
	void addJedi(TextContainer const& planetName, Jedi const&);
	/// <summary>
	/// Function removes jedi from planet with given name
	/// If planet not exists occurs message
	/// </summary>
	/// <param name="planetName"></param>
	/// <param name="jediName"></param>
	void removeJedi(TextContainer const& planetName, TextContainer const& jediName);
	/// <summary>
	/// Function changes jedi rank and power with given condition
	/// </summary>
	/// <param name="jediName"></param>
	/// <param name="mult"></param>
	/// <param name="f"></param>
	void changeJediRank(TextContainer const& jediName, double mult, int(*f)(Rang));
	/// <summary>
	/// Function finds fisrt jedi with given name and returns pointer to it
	/// If jedi was not found function throws invalid_argument exception
	/// </summary>
	/// <param name="jediName"></param>
	/// <returns></returns>
	Jedi* findJedi(TextContainer const& jediName);
	/// <summary>
	/// Function finds planet or jedi and print its data
	/// First function check planet with given name, if planet is not found it finds jedi with given name 
	/// </summary>
	/// <param name="name"></param>
	void print(TextContainer const& name);
	/// <summary>
	/// Function print jedi who is higher in given condition in a planet with given name
	/// If planet does not exists or have 0 jedi message occurs
	/// </summary>
	/// <param name="planetName"></param>
	/// <param name="f"></param>
	void getMostJedi(TextContainer const& planetName, bool(*f)(Jedi const&, Jedi const&));
	/// <summary>
	/// Function print youngest jedi with given rank
	/// </summary>
	/// <param name="planetName"></param>
	/// <param name="rang"></param>
	void getYoungestJedi(TextContainer const& planetName, Rang rang);
	/// <summary>
	/// Function prints the color of most used saber 
	/// </summary>
	/// <param name="planetName"></param>
	/// <param name="rang"></param>
	void getMostUsedSaberColor(TextContainer const& planetName, Rang rang);

};
