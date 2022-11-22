#pragma once

#include <string>
#include <vector>

class FormElement {
public:
	virtual std::string getHTML() const = 0;
};

class Input : public FormElement {
public:
	virtual std::string getHTML() const;
};

class Select : public FormElement {
public:
	virtual std::string getHTML() const;
};

class Form {
private:
	std::vector<FormElement*> elements;
public:
	void addElement(FormElement* el);
	std::string getHTML() const;
};
