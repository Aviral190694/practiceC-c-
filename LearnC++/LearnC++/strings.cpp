#include <iostream>
using namespace std;
#define LENGTH 10
#define NEWLINE '\n'
#include <cstring>
#include <string>



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
