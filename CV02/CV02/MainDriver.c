#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "MainHeader.h"

void main() {
	
	while (1) {

		printf("MENU\n1. Zadat a overit cisla\n2. Overit cisla ze souboru\n0. Ukoncit\n>> ");

		int input;
		(void)scanf("%d", &input);

		if (input == 1) {
			loadValues();
		}
		else if (input == 2) {
			readTXT();
		}
		else if (input == 0) {
			return;
		}
	}

}