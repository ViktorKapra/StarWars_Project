#pragma once
#include<fstream>

class TextContainer
{
private:
	char* text;
	int lenght;
public:
	TextContainer();
	TextContainer(const char* text);
	TextContainer& operator=(const TextContainer& textCon);
	bool operator==(const TextContainer& textCon2);
	void setText(const char* _text);
	friend std::istream& operator>>(std::istream& is,TextContainer container);
	TextContainer(const TextContainer& textCon);
	~TextContainer();
	char const* getText()const { return text; }
	int getLenghtOfText()const;
	TextContainer operator+(const TextContainer& textCon);
	void convertIntToTextContainer(int integer);
};