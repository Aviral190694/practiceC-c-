
//
//  main.cpp
//  ArrayPractice
//
//  Created by Aviral Aggarwal on 22/07/17.
//  Copyright © 2017 Aviral Aggarwal. All rights reserved.
//

#include <iostream>
using namespace std;

int pivotPointer(int arr[],int low,int high)
{
    if(low>high || low==high)
        return -1;
    
    int mid = low + (high-low)/2;
    if(mid<high && arr[mid]>arr[mid+1] )
    {
        return mid+1;
    }
    if(mid>low && arr[mid]<arr[mid-1])
    {
        return mid;
    }
    if(arr[mid]>arr[low])
    {
        return pivotPointer(arr, low+1, high);
    }
    return pivotPointer(arr, low, high-1);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int arr[] = {3,4,5,6,7,8,1};
    cout<<pivotPointer(arr, 0, 6);
    return 0;
}

