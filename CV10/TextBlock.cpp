#include "TextBlock.hpp"

#include <iostream>

//
// -- TextBlock --

TextBlock::TextBlock(std::string content) : content(content) {}

std::string* TextBlock::getContent() {
	return &content;
}

const void TextBlock::setColorSetter(IColorSetter* colorSetter) {
	this->colorSetter = colorSetter;
}

const void TextBlock::setColor() {
	colorSetter->setColor();
}

std::ostream& operator <<(std::ostream& outputStream, const TextBlock& block) {
	return outputStream << block.content;
}

TextBlock::~TextBlock() {
	delete colorSetter;
}

//
// -- RedColorSetter --

RedColorSetter::RedColorSetter(std::string* content) : content(content) {}

const void RedColorSetter::setColor() {
	*content = "<color=red>" + *content + "</color>";
}

//
// -- GreenColorSetter --

GreenColorSetter::GreenColorSetter(std::string* content) : content(content) {}

const void GreenColorSetter::setColor() {
	*content = "<color=green>" + *content + "</color>";
}
