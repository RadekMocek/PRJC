#pragma once

class Stryng {

private:
	const char* value;

public:
	Stryng(const char* value);
	const char* Value();
	int Length();
	Stryng Substring(int startIndex, int length);
	Stryng Append(const char* value);
	~Stryng();

};