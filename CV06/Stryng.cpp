#define _CRT_SECURE_NO_WARNINGS

#include <stdexcept>
#include <string.h>

#include "Stryng.h"

Stryng::Stryng(const char* value) : value(value) {}

Stryng::Stryng(const char* value, int length) {
	char* temp = new char[length + 1];
	for (int i = 0; i < length; i++) {
		*(temp + i) = *(value + i);
	}
	*(temp + length) = '\0';
	this->value = temp;
}

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
	char* result = new char[length + 1];
	int subIndex = 0;
	for (int i = startIndex; i < startIndex + length; i++) {
		*(result + subIndex) = *(value + i);
		subIndex++;
	}
	*(result + length) = '\0';
	Stryng newStryng(result, length);
	delete[] result;
	return newStryng;
}

Stryng Stryng::Append(const char* value) {
	int appLen = 0;
	for (int i = 0; *(value + i) != '\0'; i++) appLen++;
	int newLen = appLen + Length();
	char* result = new char[newLen + 1];
	strcpy(result, this->value);
	strcat(result, value);
	Stryng newStryng(result, newLen);
	delete[] result;
	return newStryng;
}
