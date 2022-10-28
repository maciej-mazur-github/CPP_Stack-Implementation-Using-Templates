#pragma once
#include <iostream>
#include <string.h>
#include <conio.h>
#include <cstdio>

using namespace::std;

class person
{
	string name;
public:
	person(string arg = "")
		: name(arg) {}
	person(int a)
		: name("") {}

	void operator=(int arg) { name = ""; }
	void operator=(string arg) { name = ""; }


	friend ostream& operator<<(ostream& out, const person& arg);
};

ostream& operator<<(ostream& out, const person& arg)
{
	out << arg.name;
	return out;
}