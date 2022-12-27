// gcc -Wall -Wextra -Werror -lstdc++ -lm assignment_operator.cpp

#include<iostream>
#include<stdio.h>

using namespace std;

class Test {
	int *ptr, size;
public:
	Test() {
		size = 0;
		ptr = NULL;
		cout << "Constructor called with size " << size << endl;
	}

	Test(int size) :
			size(size) {
		ptr = new int[size];
		cout << "Single Argument Constructor called" << endl;
	}

	Test(const Test &test) {
		cout << "Copy constructor called" << endl;
		print();		// Garbage value of size and ptr
		test.print();		// It will print size and ptr of test
		size = test.size;
		if (test.size > 0) {
			ptr = new int[test.size];
		} else {
			ptr = NULL;
		}
		print();// It will print size and ptr of this object with copied size value of t1
	}

	Test& operator =(const Test &test) {
		cout << "Assignment operator called" << endl;
		print();		// Garbage value of size and ptr
		test.print();		// It will print size and ptr of test

		/* SELF ASSIGNMENT CHECK */
		if (this != &test) {
			// Deallocate old memory
			delete[] ptr;

			// allocate new space
			ptr = new int[test.size];

			// copy values
			size = test.size;
			for (int i = 0; i < size; i++)
				ptr[i] = test.ptr[i];
		} else {
			cout << "Self Assignment" << endl;
		}
		return *this;
	}

	void print() const {
		cout << this << " - I am " << size
				<< " size object with pointer pointing at " << ptr << endl;
	}

	void print() {
		cout << this << " - I am " << size
				<< " size object with pointer pointing at " << ptr << endl;
	}
};

int main() {

	// Test t2();	// Will declare a function instead of an object
	// is a function declaration rather than variable
	// In c++ anything that can be parsed as a function declaration takes that parsing over the variable alternative.
	// Removing the () would make it a variable

	// Test t2(); will be assumed a function declaration with Test as return type and zero argument.

	Test t1(5), t2;		// Constructor Call

	t1.print();
	t2.print();

	t2 = t1;			// Assignment Function Called
	t1.print();
	t2.print();

	Test t3 = t1;		// Copy Constructor Called
	t1.print();
	t3.print();

	t3 = t3;			// Self Assignment

	return 0;
}
