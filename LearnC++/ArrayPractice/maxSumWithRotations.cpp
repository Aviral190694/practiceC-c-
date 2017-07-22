//
//  main.cpp
//  ArrayPractice
//
//  Created by Aviral Aggarwal on 22/07/17.
//  Copyright © 2017 Aviral Aggarwal. All rights reserved.
//

#include <iostream>
using namespace std;


int maxSum(int arr[],int n)
{
    
    int currVal = 0;
    int arrSum = 0;
    for(int i=0;i<n;i++)
    {
        currVal = currVal + i*arr[i];
        arrSum = arrSum + arr[i];
    }
    int maxVal = currVal;
    int rotations = 0;
    for(int j=1;j<n;j++)
    {
        currVal = currVal + arrSum-n*arr[n-j];
        if (currVal > maxVal)
        {
            maxVal = currVal;
            rotations = j;
        }
    }
    cout<<rotations<<" ";
    return maxVal;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    int arr[] = {10,1,2,3,4,5,6,7,8,9};
    
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<maxSum(arr, size);
    return 0;
}
