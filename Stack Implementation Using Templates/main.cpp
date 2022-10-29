#include <iostream>
#include <string.h>
#include <conio.h>
#include <cstdio>
#include "person.h"
#include "stack.h"

using namespace std;



int main()
{
	Stack<int, 8> ex1;
	Stack<int, 5> ex2;

	int a = 0;

	cout << "*****************************";
	cout << "\nInitiating ex1 Stack:" << endl;
	int intArray[10];

	for (int i = 0; i < 10; i++)
	{
		intArray[i] = i * 2;
	}

	ex1.loadArrayOfObjects(intArray, 10);
	cout << "\n*****************************";


	cout << "\n\n*****************************";
	cout << "\nCurrent ex1 status:" << endl;
	cout << ex1;
	cout << "\n*****************************";


	cout << "\n\n*****************************";
	cout << "\nInitiating ex2 Stack using ex1:" << endl;
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

	Stack <string, 10> ex3;

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
	cout << ex3.pop();


	Stack<Person, 3> ex4;

	cout << "\n\n************************************\n";
	cout << "Creating array of Person and pushing each person to stack ex4:\n";

	Person personArray [] = {Person("John"), Person("Peter"), Person("Adam"), Person("Kate")};

	personArray[3] = "Mary";

	ex4.loadArrayOfObjects(personArray, 4);

	cout << "\n*****************************\n";

	cout << "\nCurrent ex4 status:" << endl;
	cout << ex4;
	cout << "\n*****************************";

}