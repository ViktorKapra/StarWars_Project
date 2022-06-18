#pragma once
#include "..\Logic\DynamicArray.hpp"
#include "..\Logic\TextContainer.h"
#include "Jedi.h"
class Planet
{
private:
	TextContainer planetName;
	DynamicArray<Jedi> jedis;
public:
	Planet();
	Planet(TextContainer const&);
	Planet(TextContainer const& , DynamicArray<Jedi>const&);
	void addJedi(Jedi const& jedi);
	 DynamicArray<Jedi> const& getJedis()const { return jedis; }
	 TextContainer const& getPlanetName()const { return planetName; }
	 friend std::ostream& operator<<(std::ostream& os, Planet const& planet);
	 friend std::istream& operator>>(std::istream& is, Planet& planet);

};
