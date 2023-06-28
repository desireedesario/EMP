#include <iostream>

using namespace std;

//char sayhey() {
//    std::cout << "hey";
//}

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

// Questions 
// When should you use a struct? 
// ~ when would you use? 
// Why is using auto frowned upon? and should only be used when declaring iterators? 
// 

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