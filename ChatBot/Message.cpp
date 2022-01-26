#include "Message.h"


Message& Message::operator=(Message& x)
{
	this->ID = x.ID;
	this->msg = x.msg;
	this->isbot = x.isbot;

	return *this;
}