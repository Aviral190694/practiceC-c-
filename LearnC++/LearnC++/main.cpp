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

    
    return 0;
}
