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
    for (int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int binarSearch(int arr[],int low, int high,int x)
{
    if(low>high)
        return 0;
    if(low==high)
        return low;
    int mid = low + (high-low)/2;
    int midDiff = abs(arr[mid] - x);
    
    
    if(mid<high && mid>low && midDiff<=abs(arr[mid+1]-x) && midDiff<abs(arr[mid-1]-x))
    {
        return mid;
    }
    if( abs(arr[mid+1]-x) < abs(arr[mid-1]-x))
    {
       return binarSearch(arr, mid+1, high, x);
    }
    return binarSearch(arr, low, mid-1, x);
}

void sortArrDiff(int arr[],int n, int x)
{
    sort(arr,arr+n);
    int pivot = binarSearch(arr, 0, n-1, x);
    
    int i =pivot-1;
    int j = pivot+1;
    
    cout<<arr[pivot]<<" ";
    while(i>=0 && j<n)
    {
        if(abs(arr[i]-x)<abs(arr[j]-x))
        {
            cout<<arr[i]<<" ";
            i--;
        }
        else{
            cout<<arr[j]<<" ";
            j++;
        }
    }
    while(i>=0)
    {
        cout<<arr[i]<<" ";
        i--;
    }
    while(j<n)
    {
        cout<<arr[j]<<" ";
        j++;
    }
    cout<<endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    int arr[] = {1,2,3,4,5};//{10,5,3,9,2};//{0,1,2,3,4,5,6,8,9,11};//{10,5,3,9,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    sortArrDiff(arr, size, 6);
//    printArr(arr, size);
    return 0;
}
