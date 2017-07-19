//
//  main.cpp
//  MaxsubArray
//
//  Created by Aviral Aggarwal on 19/07/17.
//  Copyright © 2017 Aviral Aggarwal. All rights reserved.
//

#include <iostream>
using namespace std;


int max(int a,int b)
{
    return a>b ? a : b;
}

int max(int a, int b,int c)
{
    return max(max(a,b),c);
}

int maxCrossing(int *arr,int l, int mid,int h)
{
    int sum = 0;
    int left_sum = INT_MIN;
    for (int i=mid; i>=l; i--) {
        sum = sum + arr[i];
        if(sum > left_sum)
            left_sum = sum;
    }
    sum = 0;
    int right_sum = INT_MIN;
    for (int i=mid +1; i<=h; i++) {
        sum = sum + arr[i];
        if(sum > right_sum)
            right_sum = sum;
    }
    
    return left_sum+right_sum;
}

int maxSubArray(int *arr,int l,int h)
{
    if(l==h)
        return arr[l];
    int mid = (l + h)/2;
    return max(maxSubArray(arr, 0, mid),maxSubArray(arr, mid+1, h),maxCrossing(arr,l,mid,h));
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    int arr[] = {1,2,3,4,5,7,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    int maxSum = maxSubArray(arr, 0,size-1);
    cout<<"Max Sum is"<<maxSum;
    return 0;
}
