#include "Jedi.h"
#include "..\Logic\TextContainer.h"

const char* Jedi::DEFAULTNAME = "Anonymous";
const char* Jedi::DEFAULT_LIGHTSABER = "Lightless";

Jedi::Jedi()
{
	age = 0;
	name = TextContainer(DEFAULTNAME);
	power = 0.0;
	lightsaber = TextContainer(DEFAULT_LIGHTSABER);
}
Jedi::Jedi( TextContainer _name, Rang _rang, unsigned _age, double _power, TextContainer _lightsaber)
{
	name = _name;
	rang = _rang;
	age = _age;
	lightsaber = _lightsaber;
	power = _power;
}
/*
std::ostream& operator<<(std::ostream& os, Jedi const& jedi) {
	// TO DO ...
	return os;
}
std::istream& operator>>(std::istream& is, Jedi const& jedi) {
	// TO Do
	return is;
}
*/
