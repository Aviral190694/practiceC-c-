//
//  main.cpp
//  ArrayPractice
//
//  Created by Aviral Aggarwal on 22/07/17.
//  Copyright © 2017 Aviral Aggarwal. All rights reserved.
//

#include <iostream>
using namespace std;


void printArr(int arr[],int n)
{
    for (int i =0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortWave(int arr[],int size)
{
    for(int i = 0;i<size;i=i+2)
    {
     if(i-1>0 && i+1!=size)
     {
         if(arr[i]<arr[i-1])
         {
             swap(arr[i], arr[i-1]);
         }
         if(arr[i]<arr[i+1])
         {
             swap(arr[i], arr[i+1]);
         }
     }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int arr[] = {2, 4, 6, 8, 10, 20};//{20, 10, 8, 6, 4, 2};//{10, 5, 6, 3, 2, 20, 100, 80};
    int size = sizeof(arr)/sizeof(arr[0]);
    sortWave(arr, size);
    printArr(arr, size);
    std::cout << "Hello, World!\n";
    return 0;
}
