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
    for (int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void rearrangeMinMax(int arr[],int n)
{
    int min = 0;
    int max = n-1;
    int maxVal = arr[n-1]+1;
    cout<<maxVal<<endl;
    for(int i =0;i<n;i++)
    {
        if(i%2 == 0)
        {
            cout<<arr[i] << " ";
            arr[i] += ((arr[max--] %maxVal) * maxVal);
            cout<<arr[i] << " ";
        }
        else{
            cout<<arr[i] << " ";
            arr[i] += ((arr[min++] %maxVal) * maxVal);
            cout<<arr[i] << " ";
        }
    }
    cout<<endl;
    displayArray(arr, n);
    
    for(int i =0;i<n;i++)
    {
        arr[i] = arr[i]/maxVal;
    }
}



int main(int argc, const char * argv[]) {
    // insert code here...
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(arr)/sizeof(arr[0]);
    rearrangeMinMax(arr, size);
    cout<<"Result is ";
    displayArray(arr, size);
    return 0;
}
