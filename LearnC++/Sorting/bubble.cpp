//
//  bubble.cpp
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

void bubbleSort(int arr[],int size)
{
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j], arr[j+1]);
            }
        }
    }
    
}

int main(int argc, const char * argv[]) {
    int arr[] = {65,25,12,22,11};
    bubbleSort(arr, 5);
    printArray(arr, 5);
    
    return 0;
}
