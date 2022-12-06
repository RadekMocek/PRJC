#pragma once

#include <string>

enum ExceptionType { outofrange, divisionbyzero, invalidargument, badalloc };

class Exception {
private:
	ExceptionType type;
	int timestamp;
	std::string description;
public:
	Exception(ExceptionType type, int timestamp, std::string description);
	const ExceptionType getType() const;
	const int getTimestamp() const;
	const std::string getDescription() const;
};

class Handler {
private:
	ExceptionType acceptedType;
	Handler* nextHandler;
public:
	Handler(ExceptionType acceptedType, Handler* nextHandler);
	Handler(ExceptionType acceptedType);
	const void Handle(Exception& ex) const;
};
