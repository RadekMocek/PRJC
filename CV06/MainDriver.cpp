#include <iostream>

#include "Stryng.h"

int main() {
	// T��da reprezentuj�c� string
	const char* c1 = "Dobry den.";

	// V�choz� hodnota �et�zce
	Stryng s1(c1);

	// Z�sk�n� �et�zce
	std::cout << s1.Value() << "\n";

	// Length
	int len = s1.Length();
	std::cout << len << "\n";

	// Substring
	Stryng s2 = s1.Substring(2, 3);
	std::cout << s2.Value() << "\n";

	// P�ipojen� nov�ho �et�zce
	Stryng s3 = s1.Append("haha");
	std::cout << s3.Value() << "\n";

	// Na shledanou
	return 0;
}