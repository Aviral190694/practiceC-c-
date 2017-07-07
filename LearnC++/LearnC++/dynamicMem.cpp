//#include <iostream>
//#include <cstring>
//
//using namespace std;
//
//class box{
//public:
//    box()
//    {
//        cout<<"Constructor Called"<<endl;
//    }
//    ~box()
//    {
//        cout<<"Destructor Called"<<endl;
//    }
//};
//
//int main () {
//    
//    box *arr = new box[4];
//    delete [] arr;
//    
//       return 0;
//}
// A program with virtual destructor
#include<iostream>

using namespace std;

class base {
public:
    base()
    { cout<<"Constructing base \n"; }
    virtual ~base()
    { cout<<"Destructing base \n"; }
};

class derived: public base {
public:
    derived()
    { cout<<"Constructing derived \n"; }
    ~derived()
    { cout<<"Destructing derived \n"; }
};

int main(void)
{
    derived *d = new derived();
    base *b = d;
    delete b;
    getchar();
    return 0;
}
