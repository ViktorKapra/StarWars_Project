#include "LogicManager.h"
#include <utility>

void LogicManager::readPlanets(std::ifstream& is)
{
	int numberOfPlanets = 0;
	is >> numberOfPlanets;
	for (int i = 0; i < numberOfPlanets; i++)
	{
		Planet pl;
		is >> pl;
		planets.Add(pl);
	}
}
void LogicManager::writePlanets(std::ofstream& os)
{
	unsigned planetsCount = planets.getSize();
	os << planetsCount << std::endl;
	for (int i = 0; i < planetsCount; i++)
	{
		os << planets[i];
	}
}
void LogicManager::saveFileWithName(TextContainer const& _fileName)
{
	std::ofstream ofs;
	ofs.open(_fileName.getText(), std::ios::out);
	writePlanets(ofs);
	std::cout << "Successfully saved " << _fileName.getText() << std::endl;
}

void LogicManager::openFile(TextContainer const& _fileName)
{
	if (planets.getSize() > 0)
	{
		planets.Clear();
	}
	fileName = _fileName;
	std::ifstream is;
	is.open(_fileName.getText(), std::ios::in);
	readPlanets(is);
}

void LogicManager::save()
{
	saveFileWithName(fileName);

}

void LogicManager::saveAs(TextContainer const& _fileName)
{
	saveFileWithName(_fileName);
}
//void LogicManager::close()
//{
//	
//}

void LogicManager::addPlanet(Planet const& planet)
{
	if (planets.getIndexOfElement(planet) < 0)
	{
		planets.Add(planet);
	}
	else
	{
		std::cout << "Planet with this name already exists!";
	}
}

void LogicManager::addJedi(TextContainer const& planetName, Jedi const& jedi)
{
	Planet locationPlanet(planetName);
	int indexOfSearchedPlanet = planets.getIndexOfElement(locationPlanet);
	if (indexOfSearchedPlanet >= 0)
	{
		planets[indexOfSearchedPlanet].addJedi(jedi);
	}
	else
	{
		std::cout << "PLanet with name " << planetName << "does not exist" << std::endl;
	}
}
void LogicManager::removeJedi(TextContainer const& planetName, TextContainer const& jediName)
{
	Planet locationPlanet(planetName);
	int indexOfSearchedPlanet = planets.getIndexOfElement(locationPlanet);
	if (indexOfSearchedPlanet >= 0)
	{
		try {
			planets[indexOfSearchedPlanet].removeJedi(jediName);
		}
		catch (std::invalid_argument e)
		{
			std::cout << e.what();
		}
	}
	else
	{
		std::cout << "PLanet with name " << planetName << "does not exist" << std::endl;
	}
}

void LogicManager::changeJediRank(TextContainer const& jediName, double mult, int(*f)(Rang))
{
	try {
		Jedi* jed = findJedi(jediName);
		jed->changeRang(f);
		jed->changePower(mult);
	}
	catch (std::invalid_argument e)
	{
		std::cout << e.what() << std::endl;
	}
}
Jedi* LogicManager::findJedi(TextContainer const& jediName)
{
	int planetCount = planets.getSize();
	bool found = false;
	int i = 0;
	Jedi* jed = nullptr;
	while (!found && i < planetCount)
	{
		try {
			jed = planets[i].getJediByName(jediName);
			found = true;
		}
		catch (std::invalid_argument)
		{
			i++;
		}
	}
	if (jed)
	{
		return jed;
	}
	else
	{
		throw std::invalid_argument("No jedi was found!");
	}

}
void LogicManager::print(TextContainer const& name)
{
	int planetIndex = planets.getIndexOfElement(Planet(name));
	if (planetIndex >= 0)
	{
		DynamicArray<Jedi> jedisOfPlanet = planets[planetIndex].getJedis();
		jedisOfPlanet.sort([](Jedi const& j1, Jedi const& j2)->bool 
			{return j1.getRang() <= j2.getRang();});
		std::cout << planets[planetIndex].getPlanetName()<<std::endl;
		for (int i = 0; i < jedisOfPlanet.getSize(); i++)
		{
			std::cout << jedisOfPlanet[i] << std::endl;
		}
	}
	else
	{
		try
		{
			Jedi jed = *(findJedi(name));
			std::cout << jed << std::endl;
		}
		catch (std::invalid_argument e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}
void LogicManager::getMostJedi(TextContainer const& planetName, bool (*f)(Jedi const&, Jedi const&))
{

	int planetIndex = planets.getIndexOfElement(Planet(planetName));
	if (planetIndex >= 0)
	{
		try
		{
			std::cout << planets[planetIndex].getJedis().getTheMost(f) << std::endl;
		}
		catch (std::logic_error)
		{
			std::cout << "In this planet there is no jedis in this planet!" << std::endl;
		}
	}
	else
	{
		std::cout << "There is no planet with this name!";
	}
}
void LogicManager::getYoungestJedi(TextContainer const& planetName, Rang rang)
{
	Planet planet(planetName);
	int planetIndex = planets.getIndexOfElement(planet);
	if (planetIndex >= 0)
	{
		DynamicArray<Jedi> sortedJedis = planets[planetIndex].getJedis();
		sortedJedis.sort([](Jedi const& j1, Jedi const& j2)-> bool { return j1.getAge() >= j2.getAge(); });
		int sortedJedisCount = sortedJedis.getSize();
		for (int i = 0; i < sortedJedisCount; i++)
		{
			if (sortedJedis[i].getRang() == rang)
			{
				std::cout << sortedJedis[i] << std::endl;
				return;
			}
		}
	}
}

void LogicManager::getMostUsedSaberColor(TextContainer const& planetName,Rang rang)
{
	int planetIndex = planets.getIndexOfElement(Planet(planetName));
	if (planetIndex >= 0)
	{
		DynamicArray<Jedi> jedisOfPlanet = planets[planetIndex].getJedis();
		int jedisCounter = jedisOfPlanet.getSize();
		if (jedisCounter > 0)
		{
			DynamicArray< std::pair<TextContainer, int>> saberAndCounters;
			saberAndCounters.Add(std::pair<TextContainer, int >(Jedi::DEFAULT_LIGHTSABER, 1)); //adding initial lightSaber
			for (int i = 0; i < jedisCounter; i++)
			{
				int y = 0;
				bool found = false;
				while (!found && y < saberAndCounters.getSize())
				{
					if (jedisOfPlanet[i].getRang() == rang && jedisOfPlanet[i].getLightsaber() == saberAndCounters[y].first )
					{
						saberAndCounters[y].second += 1;
						found = true;
					}
					else y++;
				}
				if (found == false && jedisOfPlanet[i].getRang() == rang)
				{
					saberAndCounters.Add(std::pair<TextContainer, int >(jedisOfPlanet[i].getLightsaber(), 1));
				}
			}
			std::cout << saberAndCounters.getTheMost([](std::pair<TextContainer, int >const& p1, std::pair<TextContainer, int >const& p2)-> 
				bool{return p1.second <= p2.second; }).first<<std::endl;
		}

	}
	else
	{
		std::cout << "There is no planet with this name!";
	}
}


