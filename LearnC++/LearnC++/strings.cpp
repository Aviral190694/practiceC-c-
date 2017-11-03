//#include <iostream>
//using namespace std;
//#define LENGTH 10
//#define NEWLINE '\n'
//#include <cstring>
//#include <string>
//#include <stdio.h>
//
//int main(int argc, const char * argv[]) {
//    // insert code here...
//    cout << "Hello, World from String!\n";
//    char str1[15] = "Hello";
//    char str2[15] = "World";
//    char str3[15];
//
//    strcpy(str3, str1);
//    cout << "strcpy( str3, str1) : " << str3 << endl;
//
//    strcat(str3, str2);
//    cout << "strcat( str3, str2) : " << str3 << endl;
//
//    cout<<"Enter String 3";
////    cin>>str3;
//
//    cout<<"\n"<<str3<<endl;
//    cout<<"Practise";
//    int a;
//    cin>>a;
//    cout<<"Enter String 3";
//    cin.ignore();
//    cin.getline(str3, 15);
//    cin.ignore();
//    cin>>a;
//    cin.ignore();
//    cin.getline(str3, 15);
//cin.ignore();
//    cout<<"\n"<<str3<<endl;
//
//
//    cin>>a;
//    int len = 0;
//    len = strlen(str3);
//
//    cout<<"length is "<<len;
//
//    //Using library String
//    string st1 = "Hello";
//    string st2 = "World";
//    string st3;
//
//    st3 = st1 + st2;
//
//    len = st3.size();
//
//    cout<<len;
//
//    return 0;
//}

#include<iostream>

using namespace std;

class Empty {
  
};


class DerivedClass_1: public Empty{
  private :
  int var1;
  double var2;
  float var3;
  char var4;
  
};


class DerivedClass: public Empty{
  public :
  int var1;
  double var2;
  
  
};


class NonEmpty{
  public :
  int var1;
  double var2;
  float var3;
    char var4;
  
};

// MAIN FUNCTION

int main() {
  
  Empty *e1= new Empty;
  Empty *e2= new Empty;
  if (&e1== &e2)
    cout << "SAME OBJECT" << endl;
  
  cout << "DERIVED OBJECT" << endl;
  
  // FIND THE SIZE OF THE OBJECT WHEN THE CLASS IS EMPTY ;
  
  int sizeOfobject =  sizeof(e1);
  cout << sizeOfobject << endl;
  
  //   FIND THE SIZE OF THE OBJECT WHEN THE CLASS IS NOT EMPTY  AND DERIVED CONTAIN PUBLIC DATA TYPES;
  
  DerivedClass derivedClass;
  int sizeOfDerivedClass =sizeof(derivedClass);
  cout << "THE SIZE OD DERIVED CLASS OBJECT IS  " << sizeof(derivedClass) << endl;
  
  //   FIND THE SIZE OF THE OBJECT WHEN THE CLASS IS NOT EMPTY  AND DERIVED CONTAIN PRIVATE DATA TYPES;
  
  DerivedClass_1 derivedClass1 ;
  int sizeOfDerivedClass_1 =sizeof(derivedClass1);
  cout << "THE SIZE OD DERIVED CLASS OBJECT IS  " << sizeof(derivedClass1) << endl;
  
  //   FIND THE SIZE OF THE OBJECT WHEN THE CLASS IS NOT EMPTY CONTAIN PUBLIC DATA TYPES;
  
  NonEmpty nonempty ;
  int sizeOfNonEmptyClass =sizeof(nonempty);
  cout << "THE SIZE OD DERIVED CLASS OBJECT IS  " << sizeof(nonempty) << endl;
  
  
  return 0;
}
