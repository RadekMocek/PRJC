#include <iostream>

#include "Stryng.h"

int main() {
	// Trída reprezentující string
	const char* c1 = "Dobry den.";

	// Výchozí hodnota retezce
	Stryng s1(c1);

	// Získání retezce
	std::cout << s1.Value() << "\n";

	// Length
	int len = s1.Length();
	std::cout << len << "\n";

	// Substring
	Stryng s2 = s1.Substring(2, 3);
	std::cout << s2.Value() << "\n";

	// Pripojení nového retezce
	Stryng s3 = s1.Append("haha");
	std::cout << s3.Value() << "\n";

	// Na shledanou
	return 0;
}