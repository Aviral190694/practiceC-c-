//
//  selection.cpp
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

void selectionSort(int arr[],int size)
{
    int min = arr[0];
    int pos = 0;
    for(int i=0;i<size-1;i++)
    {
        min = arr[i];
        pos = i;
        for (int j=i+1;j<size;j++)
        {
            if(min>arr[j])
            {
                min = arr[j];
                pos = j;
            }
        }
        swap(&arr[i],&arr[pos]);
    }
}

int main(int argc, const char * argv[]) {
    int arr[] = {65,25,12,22,11};
    selectionSort(arr, 5);
    printArray(arr, 5);
    
    return 0;
}
