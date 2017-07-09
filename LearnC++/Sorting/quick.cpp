//
//  quick.cpp
//  Sorting
//
//  Created by Aviral Aggarwal on 09/07/17.
//  Copyright © 2017 Aviral Aggarwal. All rights reserved.
//

#include <iostream>
using namespace std;

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int partition(int arr[],int low, int high)
{
    int pivot = arr[high];
    int i = (low -1);
    
    for(int j=low;j<high;j++)
    {
        if(arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return (i+1);
}

void quickSort(int arr[],int low,int high)
{
        if(low<high)
        {
            int pi = partition(arr, low, high);
            
            quickSort(arr,low,pi-1);
            quickSort(arr, pi+1, high);
        }
}

int main(int argc, const char * argv[]) {
    int arr[] = {10, 7, 8, 9, 1, 5};//{65,25,12,22,11};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    quickSort(arr, 0, size-1);
     printArray(arr, size);
    return 0;
}
