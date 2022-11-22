#include <iostream>

#include "Header.h"

int main() {

	Form* fp = new Form();

	Input* ip1 = new Input();
	Input* ip2 = new Input();
	Select* sp1 = new Select();
	Input* ip3 = new Input();

	fp->addElement(ip1);
	fp->addElement(ip2);
	fp->addElement(sp1);
	fp->addElement(ip3);

	std::cout << fp->getHTML();

	// Na shledanou
	return 0;
}