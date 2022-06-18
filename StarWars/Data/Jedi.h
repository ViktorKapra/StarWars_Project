#pragma once
#include "..\Logic\TextContainer.h"
#include "RangEnum.h"
#include <iostream>
class Jedi
{
private:
	static const char* DEFAULTNAME;
	static const char* DEFAULT_LIGHTSABER;
	TextContainer name;
	Rang rang;
	unsigned age;
	TextContainer lightsaber;
	double power;
public:
	const TextContainer& getName()const { return name; }
	Rang getRang()const { return rang; }
	const TextContainer& getLightsaber()const { return lightsaber; }
	double getPower() const { return power; }
	unsigned getAge()const { return age; }
	Jedi();
	Jedi(TextContainer _name, Rang _rang, unsigned _age, double _power, TextContainer _lightsaber);
	friend std::ostream& operator<<(std::ostream& os, Jedi const& jedi);
	friend std::istream& operator>>(std::istream& is, Jedi& jedi);
};
