#pragma once

#include <iostream>
#include <string.h>

using namespace std;

template <class T, int tabSize>
class Stack;

template <class T, int tabSize>
ostream& operator<<(ostream& out, typename Stack<T, tabSize>& arg);

enum CapacityModification {expand, reduce};


template <class T, int tabSize>
class Stack
{
	int stackCapacity;
	T* arrayPtr;
	int stackElementCounter;
	string instanceName;
public:
	Stack(string instanceName = "No-name object")
	{
		stackCapacity = tabSize;

		arrayPtr = new T[stackCapacity];
		stackElementCounter = 0;
		this->instanceName = instanceName;
	}

	friend ostream& operator<< <T, tabSize> (ostream& out, typename Stack<T, tabSize>& arg);

	~Stack() { delete[] arrayPtr; }
	void push(T arg);
	T pop();
	int getElementCounter() { return stackElementCounter; }
	string getInstanceName() { return instanceName; }
	void loadArrayOfObjects(T arr[], int arraySize);
	bool empty();
private:
	void changeStackCapacity(CapacityModification action);    // used by pop() and push(T)
	void changeStackCapacity(int expansionFactor);  // method overload for loadArrayOfObjects optimization
};



template <class T, int tabSize>
bool Stack<T, tabSize>::empty()
{
	return stackElementCounter == 0 ? true : false;
}

template <class T, int tabSize>
void Stack<T, tabSize>::loadArrayOfObjects(T arr[], int arraySize)
{
	if (stackElementCounter + arraySize > stackCapacity)
	{
		int expansionFactor = (stackElementCounter + arraySize) / tabSize;  // to check how much to expand the Stack before loading the input array

		if ((stackElementCounter + arraySize) % tabSize != 0)    // if the eventual needed capacity is > n*tabSize and < (n+1)*tabSize
		{
			expansionFactor++;
		}

		this->changeStackCapacity(expansionFactor);
	}

	for (int i = 0; i < arraySize; i++) 
	{
		this->push(arr[i]);
		cout << ".";
	}
}

template <class T, int tabSize>
ostream& operator<<(ostream& out, typename Stack<T, tabSize>& arg)
{
	if (arg.empty())
	{
		out << "Stack " << arg.getInstanceName() << " is empty";
		return out;
	}

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
	stackElementCounter++;

	if (stackElementCounter > stackCapacity)    // if the point of Stack overflow is reached
	{
		cout << "\nThe Stack " << instanceName << " now needs to be expanded by additional " << tabSize << " fields\n";
		changeStackCapacity(expand);
	}

	arrayPtr[stackElementCounter - 1] = arg;
}


template <class T, int tabSize>
T Stack<T, tabSize>::pop()
{
	if (stackElementCounter <= 0)
	{
		cout << "\nThe Stack " << instanceName << " is empty\n";
		return NULL;
	}

	int indexToPop = stackElementCounter - 1;
	T objectToPop = arrayPtr[indexToPop];
	stackElementCounter--;

	if (stackElementCounter % tabSize == 0 && stackElementCounter >= tabSize)    // if the current element number decrements to the multiplicity of tabSize, excluding the single tabSize length
	{
		cout << "\nThe Stack " << instanceName << " can now be reduced by reduntant " << tabSize << " fields\n";
		changeStackCapacity(reduce);
	}

	return objectToPop;
}


template <>
string Stack<string, 10>::pop()     // full template specialization to avoid the attempt to return NULL value as String; due to partial template specialization the user can only use string Stacks of 10-element size, i.e. 10, 20, 30 etc. Not 5, 7, 11, etc. like for template arguments other than string 
{
	if (stackElementCounter <= 0)
	{
		cout << "\nThe Stack " << instanceName << " is empty\n";
		return "";
	}

	return arrayPtr[--stackElementCounter];
}


template <class T, int tabSize>
void Stack<T, tabSize>::changeStackCapacity(CapacityModification action)
{
	int howManyToRewrite = stackElementCounter;

	if (action == expand)
	{
		stackCapacity += tabSize;
		howManyToRewrite--;      // to avoid rewriting one object too many when expanding the Stack; found that bug during debugging
	}
	else
	{
		stackCapacity -= tabSize;
	}
	
	T* newArray = new T[stackCapacity];

	for (int i = 0; i < howManyToRewrite; i++)
	{
		newArray[i] = arrayPtr[i];
	}

	delete[] arrayPtr;
	arrayPtr = newArray;
}


template <class T, int tabSize>
void Stack<T, tabSize>::changeStackCapacity(int expansionFactor)
{
	stackCapacity = expansionFactor * tabSize;
	T* newArray = new T[stackCapacity];

	if (!this->empty())						// in case loadArrayOfObjects is used to add objects from an array to the Stack already containing some objects
	{
		for (int i = 0; i < stackElementCounter; i++)
		{
			newArray[i] = arrayPtr[i];
		}

		delete[] arrayPtr;
	}

	arrayPtr = newArray;
}