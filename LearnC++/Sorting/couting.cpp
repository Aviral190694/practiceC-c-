//
//  counting.cpp
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
void countSort(int arr[],int n)
{
    cout<<"Size is "<<n<<endl;
    int cArr[n];
    int rangeArr[10] = {0};
    
    for(int i=0;i<n;i++)
    {
        cArr[i] = 0;
    }
    
    for(int i=0;i<n;i++)
    {
        cArr[i]=arr[i];
        rangeArr[arr[i]]++;
    }
    
    for(int j=1;j<10;j++)
    {
        rangeArr[j] += rangeArr[j-1];
    }
    
    for(int i=0;i<n;i++)
    {
        arr[rangeArr[cArr[i]]-1] = cArr[i];
        rangeArr[cArr[i]]--;
    }
}





int main(int argc, const char * argv[]) {
    int arr[] = {6,5,2,5,1,2,2,2,1,1};
    int size = (sizeof(arr)/sizeof(arr[0]));
    countSort(arr, size);
    printArray(arr, size);
    
    return 0;
}
