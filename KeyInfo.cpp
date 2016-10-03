#include "KeyInfo.h"

KeyInfo::KeyInfo()
{
	this->repGramm = "";
	this->length = 0;
	this->gcd = 0;
}

void KeyInfo::setLength(int length)
{
	this->length = length;
}

int KeyInfo::getLength()
{
	return this->length;
}

void KeyInfo::setGcd(int gcd)
{
	this->gcd = gcd;
}

int KeyInfo::getGcd()
{
	return this->gcd;
}

void KeyInfo::setRepGramm(String^ repGramm)
{
	this->repGramm = repGramm;
}

String^ KeyInfo::getRepGramm()
{
	return this->repGramm;
}
