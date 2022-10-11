#define _CRT_SECURE_NO_WARNINGS   

#include <stdio.h>

int test(int i, float f, double d) {
	int iTest;
	float fTest;
	double dTest;
	// Test txt
	FILE* fwt;
	fwt = fopen("SOUBOR.txt", "r");	
	fscanf(fwt, "%d %f %lf", &iTest, &fTest, &dTest);
	fclose(fwt);
	printf("%d %f %lf\n", iTest, fTest, dTest);
	if (i == iTest && f == fTest && i == iTest) printf("txt ok\n"); else return -1;
	// Test bin
	FILE* fwb;
	fwb = fopen("SOUBOR.bin", "rb");
	fread(&iTest, sizeof(iTest), 1, fwb);
	fread(&fTest, sizeof(fTest), 1, fwb);
	fread(&dTest, sizeof(dTest), 1, fwb);
	fclose(fwb);
	printf("%d %f %lf\n", iTest, fTest, dTest);
	if (i == iTest && f == fTest && i == iTest) printf("bin ok\n"); else return -2;
	return 0;
}

int main() {
	
	// Naètení dat
	printf("Zadejte int, float a double oddelene mezerami:\n");

	int i;
	float f;
	double d;

	scanf("%d %f %lf", &i, &f, &d);

	// Zápis do txt
	FILE* fwt;
	fwt = fopen("SOUBOR.txt", "w");
	fprintf(fwt, "%d %f %lf", i, f, d);
	fclose(fwt);

	// Zápis do bin
	FILE* fwb;
	fwb = fopen("SOUBOR.bin", "wb");
	fwrite(&i, sizeof(i), 1, fwb);
	fwrite(&f, sizeof(f), 1, fwb);
	fwrite(&d, sizeof(d), 1, fwb);
	fclose(fwb);

	// Test
	test(i, f, d);
}
