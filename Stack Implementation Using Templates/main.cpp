#include <iostream>
#include <string.h>
#include <conio.h>
#include <cstdio>
#include "person.h"
#include "stack.h"

using namespace std;



int main()
{
	stack<int, 8> ex1;
	stack<int, 5> ex2;

	int a = 0;

	cout << "*****************************";
	cout << "\nInitiating ex1 stack:" << endl;
	for (int i = 0; i < 10; i++)
	{
		a = i * 2;
		ex1.push(a);
		cout << ".";
	}
	cout << "\n*****************************";


	cout << "\n\n*****************************";
	cout << "\nCurrent ex1 status:" << endl;
	cout << ex1;
	cout << "\n*****************************";


	cout << "\n\n*****************************";
	cout << "\nInitiating ex2 stack using ex1:" << endl;
	int elementNumber = ex1.getElementCounter();

	for (int i = 0; i < elementNumber; i++)
	{
		ex2.push(ex1.pop());
		cout << ".";
	}
	cout << "\n*****************************";

	cout << "\n\n*****************************";
	cout << "\nCurrent ex1 status:" << endl;
	cout << ex1;
	cout << "\n*****************************";
	cout << "\n\n*****************************";
	cout << "\nCurrent ex2 status:" << endl;
	cout << ex2;
	cout << "\n*****************************";

	stack < string, 10> ex3;

	string a1 = "Loma", b1 = "Chenko", c1 = "Foxtrot";

	ex3.push(a1);
	ex3.push(b1);
	ex3.push(c1);


	cout << "\n*****************************";
	cout << "\nCurrent ex3 status:" << endl;
	cout << ex3;
	cout << "\n*****************************\n";

	ex3.pop();
	ex3.pop();
	//ex3.pop();
	cout << ex3.pop();


}