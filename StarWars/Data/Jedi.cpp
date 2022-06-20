#include "Jedi.h"
#include "..\Logic\TextContainer.h"

const char* Jedi::DEFAULTNAME = "Anonymous";
const char* Jedi::DEFAULT_LIGHTSABER = "Lightless";

Jedi::Jedi()
{
	age = 0;
	name = TextContainer(DEFAULTNAME);
	power = 0.0;
	rang = YOUNGLING;
	lightsaber = TextContainer(DEFAULT_LIGHTSABER);
}
Jedi::Jedi(TextContainer _name, Rang _rang, unsigned _age, double _power, TextContainer _lightsaber)
{
	name = _name;
	rang = _rang;
	age = _age;
	lightsaber = _lightsaber;
	power = _power;
}

std::ostream& operator<<(std::ostream& os, Jedi const& jedi) {
	os << jedi.getName() << " " << jedi.getRang() << " " << jedi.getAge() << " " << jedi.getLightsaber() << " " << jedi.getPower();
	return os;
}
std::istream& operator>>(std::istream& is, Jedi& jedi) {
	TextContainer name;
	TextContainer lightsaber;
	int  rang;
	unsigned age;
	double power;
	is >> name >> rang >> age >> lightsaber >> power;
	jedi = Jedi(name, (Rang)rang, age, power, lightsaber);

	return is;
}

void Jedi::changePower(double addition)
{
	this->power*= addition;
}
void Jedi::changeRang(int(*incrementor)(Rang))
{
	int newRang = incrementor(this->getRang());
	if (newRang < Rang::GRAND_MASTER)
	{
		if (newRang > Rang::YOUNGLING)
		{
			this->rang = (Rang)newRang;
		}
	}
}
