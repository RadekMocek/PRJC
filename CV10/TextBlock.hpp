#pragma once

#include <string>

class IColorSetter {
protected:
	std::string* content;
public:
	IColorSetter(std::string* content);
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
	friend std::ostream& operator<<(std::ostream& outputStream, const TextBlock& block);
	~TextBlock();
};

class RedColorSetter : public IColorSetter {
public:
	RedColorSetter(std::string* content);
	const void setColor() override;
};

class GreenColorSetter : public IColorSetter {
public:
	GreenColorSetter(std::string* content);
	const void setColor() override;
};
