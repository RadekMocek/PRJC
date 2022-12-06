#include "Exception.hpp"

#include <iostream>

Exception::Exception(ExceptionType type, int timestamp, std::string description)
	: type(type), timestamp(timestamp), description(description) {}

const ExceptionType Exception::getType() const { return type; }
const int Exception::getTimestamp() const { return timestamp; }
const std::string Exception::getDescription() const { return description; }

Handler::Handler(ExceptionType acceptedType, Handler* nextHandler)
	: acceptedType(acceptedType), nextHandler(nextHandler) {}

Handler::Handler(ExceptionType acceptedType)
	: acceptedType(acceptedType)
{
	nextHandler = nullptr;
}

const void Handler::Handle(Exception& ex) const {
	if (ex.getType() == acceptedType) {
		std::cout << "Zachyceno handlerem v case " << ex.getTimestamp() << " a popisem " << ex.getDescription() << "\n";
	}
	else if (nextHandler != nullptr) {
		nextHandler->Handle(ex);
	}
	else {
		throw(ex);
	}
}
