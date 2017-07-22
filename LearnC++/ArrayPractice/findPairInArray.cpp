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

int pivotPointer(int arr[],int low,int high)
{
    if(low>high || low==high)
    return -1;
    
    int mid = low + (high-low)/2;
    if(mid<high && arr[mid]>arr[mid+1] )
    {
        return mid;
    }
    if(mid>low && arr[mid]<arr[mid-1])
    {
        return mid-1;
    }
    if(arr[mid]>arr[low])
    {
        return pivotPointer(arr, low+1, high);
    }
    return pivotPointer(arr, low, high-1);
}
void printArr(int arr[],int size)
{
    for (int i=0; i<size; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void reverseArr(int arr[],int low, int high)
{
    for (int i=low; i<high; i++) {
        swap(arr[i],arr[--high]);
    }
}

int findAllPair(int arr[],int size,int x)
{
    static int total = 0;
    int high = size-1;
    int low = 0;
    while(low<high)
    {
        int sum = (arr[low] + arr[high]);
        if(sum==x)
        {
            total++;
            low++;
            high--;
        }
        else if(sum<x)
        {
            low++;
        }
        else
        {
            high--;
        }
    }
    return total;
}

int findPair(int arr[],int size,int x)
{
    int high = size-1;
    int low = 0;
    while(low<high)
    {
        int sum = (arr[low] + arr[high]);
        if(sum==x)
        {
            cout<<"Indexes are"<<low<<" "<<high<<" "<<sum;
            return 1;
        }
        else if(sum<x)
        {
            low++;
        }
        else
        {
            high--;
        }
    }
    return 0;
}

int getPair(int arr[],int n, int x)
{
    
    int pivot = pivotPointer(arr, 0, n);
    cout<<pivot<<endl;
    if(pivot == -1)
    {
       return findAllPair(arr, n, x);
    }
    
    reverseArr(arr, 0, n);
    reverseArr(arr, 0, n-(pivot+1));
    reverseArr(arr, n-(pivot+1), n);
    printArr(arr, n);
    return findAllPair(arr, n, x);
    
    return 0;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int arr[] = {3,4,5,6,7,8,1,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    int pair = getPair(arr, size, 12);
    cout<<"\nPair is"<<pair;
//    cout<<pivotPointer(arr, 0, size-1);
    return 0;
}
