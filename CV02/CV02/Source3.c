#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "Header3.h"

void toTxtF(int i, char ch) {
	FILE* f;
	f = fopen("./SOUBOR.txt", "a");
	
	if (numberMatchesAsciiValue(i, ch) == 1) {
		fprintf(f, "%c=%d\n", ch, i);
	}

	fclose(f);
}

void toBinF(int i, char ch) {
	FILE* f;
	f = fopen("./BINARY.dat", "a");

	if (numberMatchesAsciiValue(i, ch) == 1) {
		fwrite(&i, sizeof(i), 1, f);
		fwrite(&ch, sizeof(ch), 1, f);
	}

	fclose(f);
}