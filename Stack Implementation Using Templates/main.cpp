#include <iostream>
#include <string.h>
#include <conio.h>
#include <cstdio>
#include "person.h"
#include "stack.h"

using namespace std;



int main()
{
	Stack<int, 8> stack1("stack1");

	int a = 0;

	cout << "*****************************";
	cout << "\nInitiating Stack<int, 8> stack1:" << endl;
	int intArray[10];

	for (int i = 0; i < 10; i++)
	{
		intArray[i] = i * 2;
	}

	stack1.loadArrayOfObjects(intArray, 10);

	cout << "\n\n*****************************";
	cout << "\nCurrent stack1 status:" << endl;
	cout << stack1;

	cout << endl << endl;


	cout << "\n\n*****************************";
	cout << "\nInitiating Stack<int, 6> stack2 using stack1:" << endl;
	Stack<int, 6> stack2("stack2");

	while (!stack1.empty())
	{
		stack2.push(stack1.pop());
		cout << ".";
	}


	cout << "\n\n*****************************";
	cout << "\nCurrent stack1 status:" << endl;
	cout << stack1;

	cout << "\n\n*****************************";
	cout << "\nCurrent stack2 status:" << endl;
	cout << stack2;
	cout << "\n*****************************";

	cout << "\nInitiating Stack<string, 10> stack3:" << endl;
	Stack <string, 10> stack3("stack3");

	string a1 = "Samba", b1 = "Jive", c1 = "Foxtrot";

	stack3.push(a1);
	stack3.push(b1);
	stack3.push(c1);
	cout << "\nCurrent stack3 status:" << endl;
	cout << stack3;
	cout << "\n*****************************";
	cout << "\nNow popping all the elements of stack3:\n";

	while (!stack3.empty())
	{
		cout << "\t" << stack3.pop() << endl;
	}


	cout << "\n*****************************";
	cout << "\nCurrent stack3 status:" << endl;
	cout << stack3;
	cout << "\n*****************************\n";

	stack3.pop();
	stack3.pop();
	cout << stack3.pop();


	cout << "\n*****************************\n";
	cout << "\nInitiating Stack<Person, 3> stack4:" << endl;
	Stack<Person, 3> stack4("stack4");
	cout << "\nCreating array of Person objects and pushing each person to stack4:\n";

	Person personArray [] = {Person("John"), Person("Peter"), Person("Adam"), Person("Kate")};

	personArray[3] = "Mary";

	stack4.loadArrayOfObjects(personArray, 4);

	cout << "\n*****************************\n";

	cout << "\nCurrent stack4 status:" << endl;
	cout << stack4;
	cout << "\n*****************************\n";
	cout << "Adding another 4-element array of Person objects to the pre-existing stack4:\n";
	Person anotherPersonArray[] = {Person("Ron"), Person("Lilly"), Person("Rollo"), Person("Shaun"), Person("Cecille")};
	stack4.loadArrayOfObjects(anotherPersonArray, 5);
	cout << "\n*****************************\n";
	cout << "Current stack4 status:" << endl;
	cout << stack4;
	cout << "\nAdding another 7-element array of Person objects to the pre-existing stack4:\n";
	Person yetAnotherPersonArray[] = { Person("Jimmie"), Person("Nel"), Person("Rowan"), Person("Liam"), Person("Felix"), Person("Suzie"), Person("Terry") };
	stack4.loadArrayOfObjects(yetAnotherPersonArray, 7);
	cout << "\n*****************************\n";
	cout << "Current stack4 status:" << endl;
	cout << stack4;
	cout << "\n*****************************\n";
	cout << "\nReducing stack4 by reduntant last 8 elements:\n";

	for (int i = 0; i < 8; i++)
	{
		cout << "\tPopping Person " << stack4.pop() << endl;
	}

	cout << "\n*****************************\n";
	cout << "Current stack4 status:" << endl;
	cout << stack4;
	cout << "\n*****************************\n";
	cout << "Now generating 2 Person objects and adding them to the stack4 using push(T) method, one by one:\n";
	Person person1("Anthony"), person2("Brian");
	stack4.push(person1);
	stack4.push(person2);
	cout << "\n*****************************\n";
	cout << "Current stack4 status:" << endl;
	cout << stack4;
	cout << "\n\n\n";
}