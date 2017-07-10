//
//  merge.cpp
//  Sorting
//
//  Created by Aviral Aggarwal on 09/07/17.
//  Copyright © 2017 Aviral Aggarwal. All rights reserved.
//

#include <iostream>
using namespace std;

void printArray(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void mergeArr(int arr[],int l,int m, int r)
{
    int i,j,k;
    int n1 = m-l+1;
    int n2 = r-m;
    
    int lArr[n1],rArr[n2];
    
    for(i=0;i<n1;i++)
    {
        lArr[i] = arr[i+l];
    }
    for(j=0;j<n2;j++)
    {
        rArr[j] = arr[m+j+1];
    }
    cout<<"LArray :"; printArray(lArr, n1);
    cout<<"RArray :";printArray(rArr, n2);
    
    k=l;
    i=0;
    j=0;
    while(i<n1 && j<n2)
    {
        if(lArr[i]<=rArr[j])
        {
            arr[k] = lArr[i];
            i++;
        }
        else{
            arr[k]= rArr[j];
            j++;
        }
        k++;
    }
    
    while(i<n1)
    {
        arr[k] = lArr[i];
        k++;
        i++;
    }
    while(j<n2)
    {
        arr[k] = rArr[j];
        k++;
        j++;
    }
}

void MergeSort(int arr[],int l, int r)
{
    if(l<r)
    {
        int mid = l + (r-l)/2;
        cout<<"Mid is  : "<<mid<<" "<<endl;
        MergeSort(arr, l, mid);
        MergeSort(arr, mid+1, r);
        mergeArr(arr,l,mid,r);
    }
}


int main(int argc, const char * argv[]) {
    int arr[] = {10, 7, 8, 9, 1, 5};//{65,25,12,22,11};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    MergeSort(arr, 0, size-1);
    cout<<endl;
    printArray(arr, size);
    
    return 0;
}
