//
//  main.cpp
//  ArrayPractice
//
//  Created by Aviral Aggarwal on 22/07/17.
//  Copyright © 2017 Aviral Aggarwal. All rights reserved.
//

#include <iostream>
using namespace std;


void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArr(int arr[],int n,int part)
{
    int i = n-1;
    int j = part-1;
    while(i>=part && j>=0)
    {
        cout<<arr[i--]<<" "<<arr[j--];
        cout<<" ";
    }
    while(j>=0)
    {
        cout<<arr[j--]<<" ";
    }
    while(i>=part)
    {
        cout<<arr[i--]<<" ";
    }
    cout<<endl;
}

void printArr(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
        
    }
    cout<<endl;
}

int partition(int arr[],int n)
{
    
    int pivot = 0;
    int j = -1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<pivot)
        {
            swap(arr[i],arr[++j]);
        }
    }
    printArr(arr, n);
    int pos = j+1, neg = 0;
    
    // Increment the negative index by 2 and positive index by 1,
    // i.e., swap every alternate negative number with next
    // positive number
    while (pos < n && neg < pos && arr[neg] < 0)
    {
        swap(&arr[neg], &arr[pos]);
        pos++;
        neg += 2;
    }
    return ++j;
}



int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    int arr[] = {-1, 2, -3, 4, 5, 6, -7, 8, 9};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<partition(arr,size)<<endl;
    printArr(arr, size);
//    reArrange(arr,size,partition(arr,size));
//    printArr(arr, size,partition(arr,size));
    
    return 0;
}
