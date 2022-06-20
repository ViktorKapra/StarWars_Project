#pragma once
#include "..\Logic\TextContainer.h"
#include "RangEnum.h"
#include <iostream>
class Jedi
{
private:

	TextContainer name;
	Rang rang;
	unsigned age;
	TextContainer lightsaber;
	double power;
public:
	static const char* DEFAULTNAME;
	static const char* DEFAULT_LIGHTSABER;
	const TextContainer& getName()const { return name; }
	Rang getRang()const { return rang; }
	/// <summary>
	///  Function changes the rang of the current jedi. It have keeps the rule that rank cannot be 
	/// higher than Grand_Master and lower than Youngling
	/// </summary>
	/// <param name="incrementor"></param>
	void changeRang(int (*incrementor)(Rang));
	const TextContainer& getLightsaber()const { return lightsaber; }
	/// <summary>
	/// Function adds to power the value of mult
	/// </summary>
	/// <param name="adddition"></param>
	void changePower(double addition);
	double getPower() const { return power; }
	unsigned getAge()const { return age; }
	Jedi();
	Jedi(TextContainer _name, Rang _rang, unsigned _age, double _power, TextContainer _lightsaber);
	/// <summary>
	/// Function serialise the jedi object in following order: name rang age lightsaber power
	/// </summary>
	/// <param name="os"></param>
	/// <param name="jedi"></param>
	/// <returns></returns>
	friend std::ostream& operator<<(std::ostream& os, Jedi const& jedi);
	/// <summary>
	/// Function deserialise the jedi object in following order: <name> <rang> <age> <lightsaber> <power>
	/// </summary>
	/// <param name="is"></param>
	/// <param name="jedi"></param>
	/// <returns></returns>
	friend std::istream& operator>>(std::istream& is, Jedi& jedi);
};
