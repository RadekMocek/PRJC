#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "Header1.h"

void loadValues() {

	printf("Zadejte int a char oddelene mezerami:\n>> ");

	int number;
	char character;

	(void)scanf("%d %c", &number, &character);

	toBinF(number, character);
	toTxtF(number, character);
}