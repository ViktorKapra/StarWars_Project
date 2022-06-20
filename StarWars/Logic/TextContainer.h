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
	TextContainer(const TextContainer& textCon);
	~TextContainer();
	/// <summary>
	/// Function checks that text of two containers are equal.
	/// </summary>
	/// <param name="textCon2"></param>
	/// <returns></returns>
	bool operator==(const TextContainer& textCon2)const;
	void setText(const char* _text);

	friend std::istream& operator>>(std::istream& is,TextContainer& container);
	friend std::ostream& operator<<(std::ostream& os, TextContainer const& container);
	char const* getText()const { return text; }
	int getLenghtOfText()const;
	/// <summary>
	/// Operator concatenates the text of containers and returns new container
	/// </summary>
	/// <param name="textCon"></param>
	/// <returns></returns>
	TextContainer operator+(const TextContainer& textCon);
	/// <summary>
	/// The function convert integer value to TextCOntainer with text of nunbers. 
	/// It can convert numbers lower than 10^20.
	/// </summary>
	/// <param name="integer"></param>
	void convertIntToTextContainer(int integer);
	
};