#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
//#include <limits.h>

void Add(short s, long* l_p) {
	//*l_p = s + *l_p;
	*l_p += s;
}

void SwapHalves(long* l_p) {
	short* s_p1 = l_p;
	short* s_p2 = s_p1 + 1;

	short temp = *s_p1;
	*s_p1 = *s_p2;
	*s_p2 = temp;
}

void main() {
	printf("sizeof(long) = %zu\nsizeof(int) = %zu\nsizeof(short) = %zu\nsizeof(char) = %zu\n\n", sizeof(long), sizeof(int), sizeof(short), sizeof(char));

	// Nacist cislo long z konzole
	long number;
	//printf("Zadejte cislo:\n>> ");
	//(void)scanf("%ld", &number);
	number = 65526;

	// Pridej k cislu long cislo short (parametr funkce) tak, aby se hodnota long zmenila v hlavnim programu
	long* number_pnt = &number;
	short addedNum = 10;
	printf("%ld", number);
	Add(10, number_pnt);
	printf(" + %hd = %ld\n", addedNum, number);

	// Vypis prvni polovinu bytu cisla long
	short* number_shortPnt = &number;
	printf("\nPrvni polovina vypsana jako short: %hd\n", *number_shortPnt);

	// Obrátit první polovinu long za druhou polovinu vypsat jako long
	SwapHalves(number_pnt);
	printf("\nObraceno: %ld\n", number);
	SwapHalves(number_pnt);
	printf("Obraceno znovu: %ld\n", number);

	// Zápis èísla long po 1byte (char) do bin souboru a jeho opìtovné naètení jako celý long (tedy ne po bytech, ale jako celek)
	FILE* fwb;
	fwb = fopen("File.bin", "wb");
	char* number_charPnt = &number;
	for (int i = 0; i < 4; i++) {
		fwrite(number_charPnt + i, sizeof(char), 1, fwb);
	}
	fclose(fwb);
	fwb = fopen("File.bin", "rb");
	long test;
	fread(&test, sizeof(long), 1, fwb);
	fclose(fwb);
	printf("\nNacteno ze souboru: %ld\n", test);
}