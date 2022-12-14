#pragma once

#include <string>

class IColorSetter {
public:
	virtual const void setColor() = 0;
};

class TextBlock {
private:
	std::string content;
	IColorSetter* colorSetter;
public:
	TextBlock(std::string content);
	std::string* getContent();
	const void setColorSetter(IColorSetter* colorSetter);
	const void setColor();
	friend std::ostream& operator <<(std::ostream& outputStream, const TextBlock& block);
	~TextBlock();
};

class RedColorSetter : public IColorSetter {
private:
	std::string* content;
public:
	RedColorSetter(std::string* content);
	const void setColor();
};

class GreenColorSetter : public IColorSetter {
private:
	std::string* content;
public:
	GreenColorSetter(std::string* content);
	const void setColor();
};
