# CMakeList.txt : CMake project for StarWars, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("StarWars")

# Add source to this project's executable.
add_executable (StarWars "StarWars.cpp" "StarWars.h" "Data/Jedi.h" "Data/RangEnum.h" "Data/Jedi.cpp" 
						"UI/UI.h"  "UI/UI.cpp" 
						"Logic/TextContainer.h" "Logic/TextContainer.cpp" "Logic/DynamicArray.hpp"  "Logic/LogicManager.h" "Logic/LogicManager.cpp"  "Data/Planet.h" "Data/Planet.cpp" "Test/Tests.h" "Test/Tests.cpp")

# TODO: Add tests and install targets if needed.
