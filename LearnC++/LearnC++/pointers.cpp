#include <iostream>

using namespace std;

void getSeconds(unsigned long *par);

int main () {
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

    
    cout<<endl;
    return 0;
}
