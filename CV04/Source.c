#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main() {
	// Alokujte pole longu o velikosti size
	int size = 11;
	long* p_long_array;
	p_long_array = (long*)malloc(sizeof(long) * size);
	if (p_long_array == NULL) return 1;

	// Naplnte pole
	for (int i = 0; i < size; i++) {
		*(p_long_array + i) = i;
	}

	// Vypis
	for (int i = 0; i < size; i++) {
		printf("%ld ", *(p_long_array + i));
	}

	// Zvetsete pole o size prvku a naplnte druhou polovinu stejnymi cisly jako prvni polovina
	int newSize = size * 2;
	long* p_new_long_array;
	p_new_long_array = (long*)malloc(sizeof(long) * newSize);
	if (p_new_long_array == NULL) return 2;

	// - Naplnit
	for (int i = 0; i < size; i++) {
		*(p_new_long_array + i) = *(p_long_array + i);
		*(p_new_long_array + size + i) = *(p_long_array + i);
	}

	// - Dealokace stareho
	free((void*)p_long_array);
	p_long_array = NULL;

	// - Vypis noveho
	printf("\n");
	for (int i = 0; i < newSize; i++) {
		printf("%ld ", *(p_new_long_array + i));
	}

	// Napište cyklus, který bude pøistupovat k poli pomocí ukazatelù a bude prohazovat vždy krajní èísla
	// (tedy indexy 0 a N, 1 a N-1, atd.)
	long* left = p_new_long_array;
	long* right = p_new_long_array + newSize - 1;

	for (int i = 0; i < size; i++) {
		long temp = *left;
		*left = *right;
		*right = temp;

		left++;
		right--;
	}

	// - Vypis prohazeneho
	printf("\n");
	for (int i = 0; i < newSize; i++) {
		printf("%ld ", *(p_new_long_array + i));
	}

	// Dealokace
	free((void*)p_new_long_array);
	p_new_long_array = NULL;

	// Nashledanou
	return 0;
}