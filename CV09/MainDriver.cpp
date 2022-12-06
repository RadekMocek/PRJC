#include "Exception.hpp"

#include <iostream>

int main() {

	Handler h3(divisionbyzero);
	Handler h2(invalidargument, &h3);
	Handler h1(outofrange, &h2);

	Exception e4(badalloc, 40, "Bad allocation");
	Exception e3(divisionbyzero, 30, "Division by zero");
	Exception e2(invalidargument, 20, "Invalid argument");
	Exception e1(outofrange, 10, "Index out of range");

	try {
		h1.Handle(e1);
		h1.Handle(e2);
		h1.Handle(e3);
		h1.Handle(e4);
	}
	catch (Exception ex) {
		std::cout << "Zachyceno catchem v case " << ex.getTimestamp() << " a popisem " << ex.getDescription() << "\n";
	}

	return 0;
}
