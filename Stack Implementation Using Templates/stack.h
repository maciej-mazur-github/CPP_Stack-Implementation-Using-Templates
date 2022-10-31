#pragma once

#include <iostream>
#include <string.h>

using namespace std;

template <class T, int tabSize>
class Stack;

template <class T, int tabSize>
ostream& operator<<(ostream& out, typename Stack<T, tabSize>& arg);


template <class T, int tabSize>
class Stack
{
	int stackCapacity;
	T* arrayPtr;
	int stackElementCounter;
public:
	Stack()
	{
		stackCapacity = tabSize;

		arrayPtr = new T[stackCapacity];
		stackElementCounter = 0;
	}

	friend ostream& operator<< <T, tabSize> (ostream& out, typename Stack<T, tabSize>& arg);

	~Stack() { delete[] arrayPtr; }
	void push(T arg);
	T pop();
	int getElementCounter() { return stackElementCounter; }
	void loadArrayOfObjects(T arr[], int arraySize);
private:
	void expandStack();
};


template <class T, int tabSize>
void Stack<T, tabSize>::loadArrayOfObjects(T arr[], int arraySize)
{
	for (int i = 0; i < arraySize; i++) {
		this->push(arr[i]);
		cout << ".";
	}
}

template <class T, int tabSize>
ostream& operator<<(ostream& out, typename Stack<T, tabSize>& arg)
{
	int elementNumber = arg.stackElementCounter;

	for (int i = 0; i < elementNumber; i++)
	{
		cout << arg.arrayPtr[i] << "\t";
	}

	return out;
}



template <class T, int tabSize>
void Stack<T, tabSize>::push(T arg)
{
	if (stackElementCounter == stackCapacity)
	{
		cout << "\nThe Stack has got full. This will now be expanded by additional " << tabSize << " fields\n";
		expandStack();
	}

	arrayPtr[stackElementCounter] = arg;
	stackElementCounter++;
}


template <class T, int tabSize>
T Stack<T, tabSize>::pop()
{
	if (stackElementCounter <= 0)
	{
		cout << "\nThe Stack is empty\n";
		return NULL;
	}


	return arrayPtr[--stackElementCounter];
}


template <>
string Stack<string, 10>::pop()     // template specialization to avoid the attempt to return NULL value as String
{
	if (stackElementCounter <= 0)
	{
		cout << "\nThe Stack is empty\n";
		return "";
	}

	return arrayPtr[--stackElementCounter];
}


template <class T, int tabSize>
void Stack<T, tabSize>::expandStack()
{
	stackCapacity += tabSize;
	T* newArray = new T[stackCapacity];

	for (int i = 0; i < stackElementCounter; i++)
	{
		newArray[i] = arrayPtr[i];
	}

	delete[] arrayPtr;
	arrayPtr = newArray;
}