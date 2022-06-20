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
	/// <summary>
	/// The function removes the firtst jedi with given name
	/// </summary>
	/// <param name="jediName"></param>
	void removeJedi(TextContainer const& jediName);
	/// <summary>
	/// The function gives pointer to jedi with given name, if jedi is no found it throws exception
	/// </summary>
	/// <param name="jediName"></param>
	/// <returns></returns>
	Jedi* getJediByName(TextContainer const& jediName);
	 /// <summary>
	 /// The operator compares planet only by their names
	 /// </summary>
	 /// <param name="other"></param>
	 /// <returns></returns>
	 bool operator==(Planet const& other)const;
	 /// <summary>
	 /// Function serialise the planet object in following order: <planetName> <number of jedis> <jedi1> <jedi2> ....
	 /// </summary>
	 /// <param name="os"></param>
	 /// <param name="planet"></param>
	 /// <returns></returns>
	 friend std::ostream& operator<<(std::ostream& os, Planet const& planet);
	 /// <summary>
	 /// Function deserialise the planet object in following order: <planetName> <number of jedis> <jedi1> <jedi2> ....
	 /// </summary>
	 /// <param name="is"></param>
	 /// <param name="planet"></param>
	 /// <returns></returns>
	 friend std::istream& operator>>(std::istream& is, Planet& planet);

};
