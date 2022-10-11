#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "Header4.h"

/*
* format TXT
* bez mezery s jednim = pro oddeleni
* první bude char druhy int
*/
int readTXT() {
	FILE* fr;
	int c;
	char ch;
	fr = fopen("./INPUT.txt", "r");

	while (fscanf(fr, "%c=%d", &ch, &c) != EOF) {
		toTxtF(c, ch);
		toBinF(c, ch);
	}

	fclose(fr);
	return 0;
}