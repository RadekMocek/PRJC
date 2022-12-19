#include "TextBlock.hpp"

#include <vector>
#include <iostream>

int main() {

	std::vector<TextBlock*> paragraph;

	TextBlock* tp1 = new TextBlock("Dobry den");
	tp1->setColorSetter(new RedColorSetter(tp1->getContent()));

	std::cout << *tp1 << "\n";

	tp1->setColor();

	std::cout << *tp1 << "\n";
	
	return 0;
}
