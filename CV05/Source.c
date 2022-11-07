#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int alloc_string(char** string_p_p, int len) {
	if (len < 1) return 1;

	*string_p_p = (char*)malloc(len * sizeof(char));
	return 0;
}

int fill_string(char* string_p, int len) {
	if (len < 1) return 1;

	for (int i = 0; i < len - 1; i++) {
		*(string_p + i) = 'A' + (rand() % 26);
	}
	*(string_p + len - 1) = '\0';
	return 0;
}

void print_string(char* string_p, int len) {
	for (int i = 0; i < len; i++) {
		printf("%c", *(string_p + i));
	}
	printf("\n");
}

int edit_char(char* string_p, char newChar, int position) {
	if (position < 0) return 1;
	for (int i = 0; i <= position; i++) {
		if (*(string_p + i) == '\0') return 2;
	}

	*(string_p + position) = newChar;
	return 0;
}

int edit_substring(char* string_p, char* substring_p, int from) {
	if (from < 0) return 1;
	int subChars;
	for (int i = 0; ; i++) {
		if (*(substring_p + i) == '\0') {
			subChars = i;
			break;
		}
	}
	if (subChars <= 0) return 2;
	for (int i = 0; i <= from + subChars - 1; i++) {
		if (*(string_p + i) == '\0') return 3;
	}

	for (int i = 0; i < subChars; i++) {
		*(string_p + from + i) = *(substring_p + i);
	}
	return 0;

	return 0;
}

int main() {
	srand(time(NULL));

	// Alokovat string o velikosti n znaku
	int n = 10;
	char* string;
	alloc_string(&string, n);

	if (string == NULL) return 1;

	// Naplnit string
	fill_string(string, n);

	// Vypsat string
	print_string(string, n);

	// Zmena charu
	edit_char(string, 'a', 0);
	print_string(string, n);

	// Zmena substringu
	edit_substring(string, "bcd", 1);
	print_string(string, n);

	// Uklidit
	free((void*)string);
	string = NULL;

	// Nashledanou
	return 0;
}