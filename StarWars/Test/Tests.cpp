#include "Tests.h"
#include "..\Data\Jedi.h"
#include"..\Data\RangEnum.h"
#include "..\Data\Planet.h"

void Test::jediReadingWritingTest()
{
	TextContainer name("Anakin");
	TextContainer lightSaber("red");
	Jedi jedi(name, Rang::ASPIRANT, 15, 3.4,lightSaber);
	std::ofstream os;
	os.open("Test1.txt", std::ios::out);
	os << jedi;
	os.close();

	std::ifstream is;
	is.open("Test1.txt", std::ios::in);
	Jedi jed2;
	is >> jed2;
	is.close();
	
	std::cout << jedi<<std::endl;
}

void Test::planetReadingWitingTest()
{
	TextContainer name("Anakin");
	TextContainer lightSaber("red");
	Jedi jedi1(name, Rang::ASPIRANT, 15, 3.4, lightSaber);
	name.setText("Obi one");
	lightSaber.setText("blue");
	Jedi jedi2(name, Rang::BATTLE_MASTER, 15, 3.4, lightSaber);
	name.setText("Earth");
	Planet pl(name);
	pl.addJedi(jedi1);
	pl.addJedi(jedi2);

	std::ofstream os;
	os.open("Test1.txt", std::ios::out);
	os << pl<< pl;
	os.close();

	std::ifstream is;
	is.open("Test1.txt", std::ios::in);
	is >> pl;
	is.close();

	std::cout << pl;
}

void Test::changeRangOfJediTest()
{
	// create test
}