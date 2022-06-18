#include "Planet.h"

Planet::Planet()
{ }
Planet::Planet(TextContainer const& _planetName, DynamicArray<Jedi>const& _jedis)
{
	planetName.setText(_planetName.getText());
	jedis = _jedis;
}

std::ostream& operator<<(std::ostream& os, Planet const& planet)
{
	
	os << planet.getPlanetName() << std::endl;
	DynamicArray<Jedi> _jedis = planet.getJedis();
	int numberOfJedis = _jedis.getSize();
	for (int i = 0; i < numberOfJedis; i++)
	{
		os << _jedis[i] << std::endl;
	}
	return os;
}
std::istream& operator>>(std::istream& is, Planet& planet)
{
	char neRow;
	TextContainer reader;
	char newLine[10];
	is >> reader;
	is.getline(newLine, 10);
	int numberOfJedis = 0;
	is >> numberOfJedis;
	for (int i = 0; i < numberOfJedis; i++)
	{
		Jedi jedi;
		is >> jedi;
		planet.jedis.Add(jedi);
	}
	
	return is;
}

void Planet::addJedi(Jedi const& jedi) {
	jedis.Add(jedi);
}
Planet::Planet(TextContainer const& _planetName)
{
	planetName.setText(_planetName.getText());
}
