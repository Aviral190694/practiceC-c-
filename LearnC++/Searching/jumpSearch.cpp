//
//  jumpSearch.cpp
//  Searching
//
//  Created by Aviral Aggarwal on 09/07/17.
//  Copyright © 2017 Aviral Aggarwal. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;
//Lienar Search
int findElement(int *Arr,int element, int size,int start);
int jumpSearch(int Arr[],int element,int size);

int main(int argc, const char * argv[]) {
    // insert code here...
    int arr[] = {10,20,30,40,50,60,70,200,300,1000,2000};
    int isElementPresent = jumpSearch(arr, 1000, 11);
    if(isElementPresent == -1)
    {
        cout<<"Element is not present"<<endl;
    }
    else{
        cout<<"Element found at index "<<isElementPresent<<endl;
    }
    
    return 0;
}

int findElement(int *Arr,int element, int size,int start)
{
    for(int i=start;i<size;i++)
    {
        if(Arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}
int jumpSearch(int Arr[],int X,int size)
{
    int step = sqrt(size);
    cout<<step;
    
    int prev=0;
    while(Arr[min(step,size)-1]<X)
    {
        prev = step;
        step += sqrt(size);
        if (prev >= size)
            return -1;
    }
    // Doing a linear search for x in block
    // beginning with prev.
    return findElement(Arr, X, size, prev);
//    while (Arr[prev] < X)
//    {
//        prev++;
//        
//        // If we reached next block or end of
//        // array, element is not present.
//        if (prev == min(step, size))
//            return -1;
//    }
//    
//    // If element is found
//    if (Arr[prev] == X)
//        return prev;
//    return -1;
}
