//
//  main.cpp
//  ArrayPractice
//
//  Created by Aviral Aggarwal on 22/07/17.
//  Copyright © 2017 Aviral Aggarwal. All rights reserved.
//

#include <iostream>
using namespace std;

void printArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void swap(int *a,int*b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void threeWayPartition(int arr[],int n, int low, int high)
{
    int start = 0;
    int end = n-1;
    for(int i=0;i<=end;)
    {
        if(arr[i]<low)
        {
            swap(arr[i++],arr[start++]);
        }
        else if(arr[i]>high)
        {
            swap(arr[i],arr[end--]);
        }
        else
            i++;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int arr[] = {1, 14, 5, 20, 4, 2, 54, 20, 87, 98, 3, 1, 32};
    int size = sizeof(arr)/sizeof(arr[0]);
    threeWayPartition(arr, size, 10, 20);
    printArray(arr, size);
    
    std::cout << "Hello, World!\n";
    return 0;
}
