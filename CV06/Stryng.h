#pragma once

class Stryng {

private:
	const char* value;

public:
	Stryng(const char* value);
	Stryng(const char* value, int length);
	const char* Value();
	int Length();
	Stryng Substring(int startIndex, int length);
	Stryng Append(const char* value);

};