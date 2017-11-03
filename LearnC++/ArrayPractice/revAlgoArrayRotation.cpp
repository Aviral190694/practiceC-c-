//
//  main.cpp
//  ArrayPractice
//
//  Created by Aviral Aggarwal on 22/07/17.
//  Copyright © 2017 Aviral Aggarwal. All rights reserved.
//

#include <iostream>
using namespace std;

//PrintArray Function
void printArray(int arr[],int n)
{
    for (int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void swap(int *a,int*b)
{
    int temp = *a;
    *a=*b;
    *b = temp;
}

void reverseArr(int arr[],int l,int h)
{
    for(int i=l;i<h;i++)
    {
        swap(arr[i],arr[--h]);
    }
}

void arrayRotation(int arr[],int d, int n)
{
    if(d%n==0)
    {
        return;
    }
    else if(d>n)
    {
        d=d%n;
    }
    reverseArr(arr,0,d);
    reverseArr(arr, d, n);
    reverseArr(arr, 0, n);
    printArray(arr, n);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    int arr[] = {1,2,3,4,5,6,7};
    int size = sizeof(arr)/sizeof(arr[0]);
    arrayRotation(arr, 2, size);
    
    return 0;
}
