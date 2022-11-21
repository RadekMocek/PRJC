#include <iostream>

#include "Stryng.h"

int main() {
	// Tøída reprezentující string
	const char* c1 = "Dobry den.";

	// Výchozí hodnota øetìzce
	Stryng s1(c1);

	// Získání øetìzce
	std::cout << s1.Value() << "\n";

	// Length
	int len = s1.Length();
	std::cout << len << "\n";

	// Substring
	Stryng s2 = s1.Substring(2, 3);
	std::cout << s2.Value() << "\n";

	// Pøipojení nového øetìzce
	Stryng s3 = s1.Append("haha");
	std::cout << s3.Value() << "\n";

	// Na shledanou
	return 0;
}