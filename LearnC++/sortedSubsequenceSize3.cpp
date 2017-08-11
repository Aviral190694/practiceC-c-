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
    for (int i =0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void printSortedSub(int arr[],int n)
{
//    int smaller[n];
//    int greater[n];
    int max = n-1;
    int min = 0;
    
    int *smaller = new int[n];
    int *greater = new int[n];
    smaller[0] = -1;
    
    for(int i=1;i<n;i++)
    {
        if(arr[i]<=arr[min])
        {
            min = i;
            smaller[i]  = -1;
        }
        else{
            smaller[i]= min;
        }
    }
    
    
    greater[n-1] = -1;
    for(int i=n-2;i>=0;i--)
    {
        if(arr[i]>=arr[max])
        {
            max = i;
            greater[i]  = -1;
        }
        else{
            greater[i]= max;
        }
    }
    
    printArr(greater, n);
    printArr(smaller, n);
    for (int i=0; i<n; i++) {
        if(smaller[i] != -1 && greater[i] != -1)
        {
            cout<<arr[smaller[i]]<<" "<<arr[i]<<" "<<arr[greater[i]]<<endl;
            delete [] greater;
            delete [] smaller;
            return;
        }
    }
    delete [] greater;
    delete [] smaller;
    cout<<"No Element present.";
}


int main(int argc, const char * argv[]) {
    // insert code here...
    int arr[] = {12, 11, 10, 5, 6, 2, 30};
    int size = sizeof(arr)/sizeof(arr[0]);
    printArr(arr, size);
    printSortedSub(arr, size);
    
    
    return 0;
}
