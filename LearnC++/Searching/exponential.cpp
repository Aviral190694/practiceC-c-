//
//  exponential.cpp
//  Searching
//
//  Created by Aviral Aggarwal on 09/07/17.
//  Copyright © 2017 Aviral Aggarwal. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

//Gets Sorted Array
int binarySearch(int Arr[],int element,int start, int end);
int exponentialSearch(int Arr[],int element, int size)
{
    if(Arr[0]==element)
    {
        return 0;
    }
    
    int i=1;
    while(i<size && Arr[i]<element)
    {
        i=i*2;
    }
    return binarySearch(Arr, i/2, min(i,size), element);
}
int main(int argc, const char * argv[]) {
    int arr[] = {10,20,30,40,50,60,70};
    //    int searchKey = binarySearch(arr,0, (sizeof(arr)/sizeof(arr[0]))-1,70);
    int searchKey = exponentialSearch(arr, 60, 7);
    if(searchKey==-1)
    {
        cout<<"Element is not present"<<endl;
    }
    else{
        cout<<"Element found at index "<<searchKey<<endl;
    }
    return 0;
}


int binarySearch(int Arr[],int l, int r,int x)
{
    if(r >= l)
    {
        int mid = (l+r)/2;
        if (Arr[mid]==x)
            return mid;
        else if(Arr[mid]>x)
            return binarySearch(Arr, l, mid-1, x);
        return binarySearch(Arr, mid+1, r, x);
    }
    return -1;
}
