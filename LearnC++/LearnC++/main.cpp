//
//  main.cpp
//  LearnC++
//
//  Created by Aviral Aggarwal on 16/06/17.
//  Copyright © 2017 Aviral Aggarwal. All rights reserved.
//

#include <iostream>
using namespace std;
#define LENGTH 10
#define NEWLINE '\n'


//Learning call by Value,Reference and Pointer
void swapValue(int a,int b);
void swap(int &a,int &b);
void swapPointer(int *a, int *b);

int main(int argc, const char * argv[]) {
    // insert code here...
//    cout << "Hello, World!\n";
    const int area = 100;
    //Checking for Carraige Return and all
//    cout << "Hello\tWorld\n\n";
    cout<<LENGTH<<NEWLINE<<area;
    
    //Testing Signed and Unsigned
    
    short int i;
    short unsigned int j;
    j=50000;
    i=j;
    cout<<i<<" "<<j;
    int a = 100;
    int b = 200;
    
    //Learning call by Value,Reference and Pointer
    cout<<endl<<"Initial Values are "<<a<<" "<<b;
//    swapValue(a,b);
    swapPointer(&a, &b);
    cout<<endl<<"Swapped Values are "<<a<<" "<<b;
    
    //Learning String
    char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
    
    cout <<endl<< "Greeting message: ";
    cout << greeting << endl;
    
    cout<<endl;
    return 0;
}

void swapPointer(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void swapValue(int a, int b)
{
    int temp = a;
    a=b;
    b=temp;
    return;
}

void swap(int &a, int &b)
{
    int temp = a;
    a=b;
    b=temp;
    return;
}
