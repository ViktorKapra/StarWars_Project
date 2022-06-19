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

	os << planet.getPlanetName() << " " << planet.getJedis().getSize() << std::endl;
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
	TextContainer planetName;
	is >> planetName;
	planet.planetName = planetName;
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
bool Planet::operator==(Planet const& other)const
{
	return this->getPlanetName() == other.getPlanetName();
}
void Planet::removeJedi(TextContainer const& jediName)
{
	int removingIndex = -1;
	int jedisCount = jedis.getSize();
	for (int i = 0; i < jedisCount; i++)
	{
		if (jedis[i].getName() == jediName)
		{
			jedis.removeAt(i);
			removingIndex = i;
		}
	}
	if (removingIndex == -1)
		throw std::invalid_argument("No jedi with this name was found!");
}
Jedi* Planet::getJediByName(TextContainer const& jediName)
{
	int jedisCount = jedis.getSize();
	for (int i = 0; i < jedisCount; i++)
	{
		if (jedis[i].getName() == jediName)
		{
			return &jedis[i];
		}
	}
	throw std::invalid_argument("No jedi with this name was found!");
}