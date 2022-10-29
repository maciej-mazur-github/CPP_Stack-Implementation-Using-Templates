#pragma once

#include <iostream>
#include <string.h>

using namespace std;

template <class T, int tab_size>
class Stack;

template <class T, int tab_size>
ostream& operator<<(ostream& out, typename Stack<T, tab_size>& arg);


template <class T, int tab_size>
class Stack
{
	int stack_capacity;
	T* array_ptr;
	int stack_element_counter;
public:
	Stack()
	{
		stack_capacity = tab_size;

		array_ptr = new T[stack_capacity];
		stack_element_counter = 0;
	}

	friend ostream& operator<< <T, tab_size> (ostream& out, typename Stack<T, tab_size>& arg);

	~Stack() { delete[] array_ptr; }
	void push(T arg);
	T pop();
	int getElementCounter() { return stack_element_counter; }
	void loadArrayOfObjects(T arr[], int arraySize);
private:
	void expand_Stack();
};


template <class T, int tab_size>
void Stack<T, tab_size>::loadArrayOfObjects(T arr[], int arraySize)
{
	for (int i = 0; i < arraySize; i++) {
		this->push(arr[i]);
		cout << ".";
	}
}

template <class T, int tab_size>
ostream& operator<<(ostream& out, typename Stack<T, tab_size>& arg)
{
	int elementNumber = arg.stack_element_counter;

	for (int i = 0; i < elementNumber; i++)
	{
		cout << arg.array_ptr[i] << "\t";
	}

	return out;
}



template <class T, int tab_size>
void Stack<T, tab_size>::push(T arg)
{
	if (stack_element_counter == stack_capacity)
	{
		cout << "\nThe Stack has got full. This will now be expanded by additional " << tab_size << " fields\n";
		expand_Stack();
	}

	array_ptr[stack_element_counter] = arg;
	stack_element_counter++;
}


template <class T, int tab_size>
T Stack<T, tab_size>::pop()
{
	if (stack_element_counter <= 0)
	{
		cout << "\nThe Stack is empty\n";
		return NULL;
	}


	return array_ptr[--stack_element_counter];
}


template <>
string Stack<string, 10>::pop()     // template specialization to avoid the attempt to return NULL value as String
{
	if (stack_element_counter <= 0)
	{
		cout << "\nThe Stack is empty\n";
		return "";
	}

	return array_ptr[--stack_element_counter];
}


template <class T, int tab_size>
void Stack<T, tab_size>::expand_Stack()
{
	stack_capacity += tab_size;
	T* new_array = new T[stack_capacity];

	for (int i = 0; i < stack_element_counter; i++)
	{
		new_array[i] = array_ptr[i];
	}

	delete[] array_ptr;
	array_ptr = new_array;
}