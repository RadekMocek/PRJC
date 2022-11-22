#include "Header.h"

std::string Input::getHTML() const {
	return "<input></input>";
}

std::string Select::getHTML() const {
	return "<select></select>";
}

void Form::addElement(FormElement* el) {
	elements.push_back(el);
}

std::string Form::getHTML() const {
	std::string result = "";
	for (FormElement* el : elements) {
		result += el->getHTML() + "\n";
	}
	return result;
}