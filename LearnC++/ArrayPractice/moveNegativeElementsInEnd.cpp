//
//  main.cpp
//  ArrayPractice
//
//  Created by Aviral Aggarwal on 22/07/17.
//  Copyright © 2017 Aviral Aggarwal. All rights reserved.
//

#include <iostream>
using namespace std;

void displayArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
        
    }
    cout<<endl;
}

void rearrangeArray(int arr[],int n)
{
    int temp[n];
    int j = 0;
    
    for(int i = 0;i<n;i++)
    {
        if(arr[i]>0)
        {
            temp[j++] = arr[i];
        }
    }
    for(int i = 0;i<n;i++)
    {
        if(arr[i]<0)
        {
            temp[j++] = arr[i];
        }
    }
    memcpy(arr, temp, sizeof(temp));
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int arr[] = {1, -1, 3, 2, -7, -5, 11, 6 };
    int size = sizeof(arr)/sizeof(arr[0]);
    
    rearrangeArray(arr, size);
    displayArray(arr, size);
    
    return 0;
}
