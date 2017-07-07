//
//  main.cpp
//  Templates
//
//  Created by Aviral Aggarwal on 07/07/17.
//  Copyright © 2017 Aviral Aggarwal. All rights reserved.
//

#include <iostream>
using namespace std;

#define LAUNCH
#define MAX(a,b) (((a)<(b)) ? b : a)

#define _mkstr(x) #x
#define MKSTR(x) _mkstr(x)
#define concat(a,b) a##b
#define test(a,b) MKSTR(concat(a,b))

template <typename T>
T Max(T a, T b)
{
    cout<<typeid(T).name()<<" ";
    if(std::is_same<T, int>::value)
    {
        cout<<"Yes Int here";
    }
    if(std::is_same<T, char*>::value)
    {
        cout<<"Ola String here ";
    }
    return a<b ? b : a;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Value of __LINE__ : " << __LINE__ << endl;
    cout << "Value of __FILE__ : " << __FILE__ << endl;
    cout << "Value of __DATE__ : " << __DATE__ << endl;
    cout << "Value of __TIME__ : " << __TIME__ << endl;
    int i = 39;
    int j = 29;
    cout<<MAX(i, j);
    cout<< typeid(j).name() <<endl;
#ifdef LAUNC
    cerr <<"Trace: Inside main function" << endl;
#endif
//    csout<< typeof(i) <<endl;
    concat(c, out)<<MKSTR(Hey);
    cout<<MKSTR(concat(this is, crazy));
    cout << "Max(i, j): " << Max(i, j) << endl;
    cout<<MKSTR(This is pretty cool )<<endl;
    double f1 = 13.5;
    double f2 = 20.7;
    cout << "Max(f1, f2): " << Max(f1, f2) << endl;
//    cout<<concat("Hey", "There");
    char s1[] = "Hellos";
    char s2[] = "Aorld";
    cout << "Max(s1, s2): " << Max(s1, s2) << endl;
#ifdef LAUNC
    cerr <<"Trace: Inside main function" << endl;
#endif
    return 0;
}
