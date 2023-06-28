#include <iostream>

using namespace std;


int increments() {
	int x = 10;
	// If you add the increment operator as a postfix, the current value of x will
	// be stored by y, and then incremented by 1
	// int y = x++; // x = 11, y = 10

	// if you add the increment operator as a prefix, first x will be incremented by one 
	// and then the result will be stored in the other variable 
	int z = ++x; // x = 11, y = 11

	std::cout << x; // x turns into 11 

	return 0;
}

int changingVar() {
	int x = 10;
	x = x + 5;
	std::cout << x;

	return 0;
}

int gettingRemainder() {
	int x = 10;
	int y = 3;
	int z = x % y;
	std::cout << z;

	return 0;

}

int usingDoubles() {

	double x = 10; // At least one int needs to be a double to acess a float
	int y = 3;
	double z = x / y; // number will not return as a float
	std::cout << z;

	return 0;
}

int constUsage() {
	const double pi = 3.14;
	//pi = 0;
	return 0;
}

int swapvariables() {
	int a = 1;
	int b = 2;
	int temp = a;
	a = b;
	b = temp;
	cout << b;

	return 0;
}


int test() {
	int file_size = 0;
	int counter = 0;
	double sales = 9.99;
	std::cout << file_size;
	return 0;
}


// Notes 
// int returns an integer 
// iostream is input output stream
//std stand library 
//cout is character out - we could output characters with this
// semi color terminates a statement 
// 0 tells the operating system that our program terminated corrrectly 
// file_size is the variable 
// double initializes a decimal 
// garbage : the data in memory 
// fyi, dont name your func const...

// const - cannot reassign/modify a variable 



// EMP.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 


const int trucker = 3;

int l()
{
    while (true)
    {

    }
    return 1;
}


struct Shape // struct - a way to group several related variables into one place
{
    virtual void Draw() = 0; //pure virtual foundation 
    virtual ~Shape() { } // ensure derived dtors are virtual - implementing inheritance 
};

struct Circle : public Shape // ? What is the difference between member-declarations and base-class public? 
{
    virtual void Draw()
    {
        // draw shape as a circle 
    }
};

struct Rectangle : public Shape
{
    virtual void Draw();
};





// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

// Questions 
// When should you use a struct? 
// ~ when would you use? 
