//
//  linear.cpp
//  Searching
//
//  Created by Aviral Aggarwal on 09/07/17.
//  Copyright © 2017 Aviral Aggarwal. All rights reserved.
//

#include <iostream>
using namespace std;

int findElement(int *Arr,int element, int size);


int main(int argc, const char * argv[]) {
    // insert code here...
    int arr[] = {10,20,30,40,50,60,10,200,100,1000,20};
    int isElementPresent = findElement(arr, 2200, 11);
    if(isElementPresent == -1)
    {
        cout<<"Element is not present"<<endl;
    }
    else{
        cout<<"Element found at index "<<isElementPresent<<endl;
    }
    
    return 0;
}

int findElement(int *Arr,int element, int size)
{
    for(int i=0;i<size;i++)
    {
        if(Arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}
