#include <iostream>

using namespace std;

class two;

class test
{
    private:
        int width;
        int *ptr;
    public :
        void setWidth(int length);
        int getWidth();
        int getPointer();
        void setPointer(int l);
    friend void display(test onj);
    void testFriend(two &obj);
        test();
        test(const test &obj);
};

class two{
    int a,b;
public:
    friend void test::testFriend(two &obj);
    two() : a(1), b(2)
    {
        
    }
};

void test::testFriend(two &obj)
{
    
}
    test::test(const test &obj)
    {
        cout<<"copy constructor";
        width = obj.width;
        ptr = new int();
        *ptr = *obj.ptr;
    }

test::test()
{
    cout<<"This is a test constructor";
    ptr = new int;
    *ptr = 10;
}

void test::setWidth(int width)
{
    this->width = width;
}

void test::setPointer(int l)
{
    *ptr = l;
}


int test::getWidth()
{
    return width;
}
int test::getPointer()
{
    return *ptr;
}

void display(test obj)
{
    cout<<endl<<obj.width;
}

void getSeconds(unsigned long *par);
double getAverage(int *arr,int size);
int * getRandom( ) {
    static int  r[10];
    
    // set the seed
    srand( (unsigned)time( NULL ) );
    
    for (int i = 0; i < 10; ++i) {
        r[i] = rand();
        cout << r[i] << endl;
    }
    
    return r;
}

int main () {
    
    test newTest;
    newTest.setWidth(5);
    cout<<newTest.getWidth()<<" "<<newTest.getPointer();
    
    test second(newTest);
    newTest.setPointer(20);
    cout<<endl<<second.getWidth()<<" "<<second.getPointer()<<endl;
    display(newTest);
    
    int var1;
    char var2[10];
    cout << "Address of var1 variable: ";
    cout << &var1 << " " << sizeof(&var1)<< endl;
    
    cout << "Address of var2 variable: ";
    cout << &var2 << " " << sizeof(&var2)<<" "<<sizeof(var2)<<sizeof(var2[0])<< endl;
    
    int var = 20;
    int *p;
    
    p = &var; // Store the address of var in P
    
    cout<<endl<<"Value of Var "<<var;
    cout<<endl<<"Value of Address "<<p;
    cout<<endl<<"Value of Pointer "<<*p;
    
    int arr[] = {10,100,1000};
    int *ptr;
    *(arr + 2) = 500;
    
    ptr = arr;
    //    cout<<endl<<" "<<arr<<" "<<arr[0]<<" "<<&arr;
    for(int i=0;i<3;i++)
    {
        cout<<endl<<ptr<<" "<<*ptr;
        ptr++;
    }
    
    for (int i =2; i>-1; i--) {
        ptr--;
        cout<<endl<<ptr<<" "<<*ptr;
        
    }
    
    char *names[4] = {"Zara Aliass","Hina Aliss","Nuha Aliss","Sara Ali"};
    cout<<endl<<names[0]<<" "<<names[0][1]<<" "<<&names<<" "<<&names[0]<<" "<<sizeof(names)<<" "<<sizeof(names[0])<<sizeof(*names[0]);
    
    
    
    int **doublePtr;
    int *singlePtr;
    int val = 3000;
    
    singlePtr = &val;
    doublePtr = &singlePtr;
    // take the value using pptr
    cout <<endl<< "Value of var :" << val << endl;
    cout << "Value available at *singlePtr :" << *singlePtr << endl;
    cout << "Value available at **doublePtr :" << **doublePtr << endl;
    
    unsigned long sec;
    getSeconds(&sec);
    cout<<endl<<"Nummer of seconds :"<<sec;
    
    
    int balance[5] = {1000, 2, 3, 17, 50};
    double avg;
    
    // pass pointer to the array as an argument.
    avg = getAverage( balance, 5 ) ;
    
    // output the returned value
    cout <<endl<< "Average value is: " << avg;
    
    int *pp;
    
    pp = getRandom();
    
    for ( int i = 0; i < 10; i++ ) {
        cout << "*(pp + " << i << ") : ";
        cout << *(pp + i) <<" "<<pp[i]<< endl;
    }
    
    cout<<endl;
    
    return 0;
}

void getSeconds(unsigned long *par)
{
    *par = time(NULL);
    return;
}

double getAverage(int *arr,int size)
{
    double avg = 0.0;
    for (int i=0; i<size; i++) {
        avg = avg + *(arr + i);
        //or avg += arr[i];
    }
    return avg/size;
}
