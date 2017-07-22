#include <iostream>
using namespace std;
#define LENGTH 10
#define NEWLINE '\n'
#include <cstring>
#include <string>
#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World from String!\n";
    char str1[15] = "Hello";
    char str2[15] = "World";
    char str3[15];
    
    strcpy(str3, str1);
    cout << "strcpy( str3, str1) : " << str3 << endl;
    
    strcat(str3, str2);
    cout << "strcat( str3, str2) : " << str3 << endl;
    
    cout<<"Enter String 3";
//    cin>>str3;
    
    cout<<"\n"<<str3<<endl;
    int a;
    cin>>a;
    cout<<"Enter String 3";
    cin.ignore();
    cin.getline(str3, 15);
    cin.ignore();
    cin>>a;
    cin.ignore();
    cin.getline(str3, 15);
cin.ignore();
    cout<<"\n"<<str3<<endl;
    
    
    cin>>a;
    int len = 0;
    len = strlen(str3);
    
    cout<<"length is "<<len;
    
    //Using library String
    string st1 = "Hello";
    string st2 = "World";
    string st3;
    
    st3 = st1 + st2;
    
    len = st3.size();
    
    cout<<len;
    
    return 0;
}
