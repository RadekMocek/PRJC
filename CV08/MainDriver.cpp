#include <iostream>

#include "Machine.hpp"

int main() {
	Machine m1;

	SemiproductA sa1(10);
	
	SemiproductB sb1(12);
	
	SemiproductC sc1(14);

	m1.addSemiproduct(&sa1);
	m1.addSemiproduct(&sb1);
	m1.addSemiproduct(&sc1);

	m1.assemble();

	return 0;
}