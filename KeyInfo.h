#ifndef KEYINFO_H
#define KEYINFO_H

using namespace System;

public ref class KeyInfo
{
public:
	KeyInfo();
	void setLength(int);
	int getLength();
	void setGcd(int);
	int getGcd();
	void setRepGramm(String^);
	String^ getRepGramm();
private:
	int length;
	int gcd;
	String^ repGramm;
};

#endif KEYINFO_H