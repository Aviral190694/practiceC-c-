//
//  main.cpp
//  ArrayPractice
//
//  Created by Aviral Aggarwal on 22/07/17.
//  Copyright © 2017 Aviral Aggarwal. All rights reserved.
//

#include <iostream>
using namespace std;

void printArr(int arr[],int n);


void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void arrayRotationMem(int arr[],int d, int n)
{
    if(d%n==0)
    {
        return;
    }
    else if(d>n)
    {
        d=d%n;
    }
    cout<<d;
    int temp[n],j=d;
    for(int i=0;i<n;i++)
    {
        if(i==n-d)
        {
            j=0;
        }
        temp[i] = arr[j++];
    }
//    swap(arr,temp);
    cout<<"Array is ";printArr(temp, n);
    for(int i=0;i<n;i++)
    {
        arr[i]=temp[i];
    }
}

void printArr(int arr[],int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int arr[] = {1,2,3,4,5,6,7};
    int size = sizeof(arr)/sizeof(arr[0]);
//    printArr(arr, size);
    arrayRotationMem(arr, 2, size);
    printArr(arr, size);
    return 0;
}
