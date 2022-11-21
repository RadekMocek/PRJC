#define _CRT_SECURE_NO_WARNINGS   

#include <stdexcept>
#include <string.h>

#include "Stryng.h"

Stryng::Stryng(const char* value) : value(value) {}

const char* Stryng::Value() {
	return value;
}

int Stryng::Length() {
	int result = 0;
	for (int i = 0; *(value + i) != '\0'; i++) result++;
	return result;
}

Stryng Stryng::Substring(int startIndex, int length) {
	int valueLen = Length();
	if (length < 0 || startIndex < 0 || startIndex + length > valueLen) throw std::invalid_argument("received invalid value(s)");
	char* result = (char *)malloc((length + 1) * sizeof(char *));
	int subIndex = 0;
	for (int i = startIndex; i < startIndex + length; i++) {
		*(result + subIndex) = *(value + i);
		subIndex++;
	}
	*(result + length) = '\0';
	return Stryng(result);
}

Stryng Stryng::Append(const char* value) {
	int appLen = 0;
	for (int i = 0; *(value + i) != '\0'; i++) appLen++;
	int newLen = appLen + Length();
	char* result = (char*)malloc((newLen + 1) * sizeof(char*));
	strcpy(result, this->value);
	strcat(result, value);
	return Stryng(result);
}

Stryng::~Stryng() {
	//TODO
	//delete[] value;
}
