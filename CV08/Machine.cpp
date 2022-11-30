#include <iostream>
#include <sstream>

#include "Machine.hpp"

const int maxStackSize = 10;

SemiproductA::SemiproductA(int height) : height(height) {}
int SemiproductA::getHeight() { return height; }

SemiproductB::SemiproductB(int width) : width(width) {}
int SemiproductB::getWidth() { return width; }

SemiproductC::SemiproductC(int depth) : depth(depth) {}
int SemiproductC::getDepth() { return depth; }

Product::Product(int height, int width, int depth) : height(height), width(width), depth(depth) {}

std::ostream& operator <<(std::ostream& outputStream, const Product& prod) {
	return outputStream << "Product {\n\theight: " << prod.height << "\n\twidth: " << prod.width << "\n\tdepth: " << prod.depth << "\n}";
}

void Machine::addSemiproduct(SemiproductA* sprod) {
	if (stackA.size() < maxStackSize) {
		stackA.push(sprod);
	}
}

void Machine::addSemiproduct(SemiproductB* sprod) {
	if (stackB.size() < maxStackSize) {
		stackB.push(sprod);
	}
}

void Machine::addSemiproduct(SemiproductC* sprod) {
	if (stackC.size() < maxStackSize) {
		stackC.push(sprod);
	}
}

void Machine::assemble() {
	if (stackA.empty() || stackB.empty() || stackC.empty()) return;
	SemiproductA* sprodA = stackA.top();
	stackA.pop();
	SemiproductB* sprodB = stackB.top();
	stackB.pop();
	SemiproductC* sprodC = stackC.top();
	stackC.pop();
	Product* newProd = new Product(sprodA->getHeight(), sprodB->getWidth(), sprodC->getDepth());
	products.push_back(newProd);
	std::cout << *newProd << "\n";
}

Machine::~Machine() {
	products.clear();
}

// Konstruktor
Machine::Machine() {

}

// Kopírovací konstruktor
Machine::Machine(Machine& other) : Machine() {

}

// Operátor
Machine& Machine::operator=(const Machine& other) {
	return *this;
}