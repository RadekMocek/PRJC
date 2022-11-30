#pragma once

#include <stack>
#include <vector>

class SemiproductA {
private:
	int height;
public:
	int getHeight();
	SemiproductA(int height);
};

class SemiproductB {
private:
	int width;
public:
	int getWidth();
	SemiproductB(int width);
};

class SemiproductC {
private:
	int depth;
public:
	int getDepth();
	SemiproductC(int depth);
};

class Product {
private:
	int height;
	int width;
	int depth;	
	friend std::ostream& operator <<(std::ostream& outputStream, const Product& prod); // "toString"
public:
	Product(int height, int width, int depth);
};
	
class Machine {
private:
	std::stack<SemiproductA*> stackA;
	std::stack<SemiproductB*> stackB;
	std::stack<SemiproductC*> stackC;
	std::vector<Product*> products;
public:
	void addSemiproduct(SemiproductA* sprod);
	void addSemiproduct(SemiproductB* sprod);
	void addSemiproduct(SemiproductC* sprod);
	void assemble();
	~Machine();
	// Konstruktor
	Machine();
	// Kopírovací konstruktor
	Machine(Machine& other);
	// Operátor =
	Machine& operator=(const Machine& other);
};
