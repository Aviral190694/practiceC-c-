//
//  main.cpp
//  ArrayPractice
//
//  Created by Aviral Aggarwal on 22/07/17.
//  Copyright © 2017 Aviral Aggarwal. All rights reserved.
//

#include <iostream>
using namespace std;




/* Standard Binary Search function*/
int binarySearch(int arr[], int low, int high, int key)
{
    if (high < low)
    return -1;
    int mid = (low + high)/2;  /*low + (high - low)/2;*/
    if (key == arr[mid])
    return mid;
    if (key > arr[mid])
    return binarySearch(arr, (mid + 1), high, key);
    return binarySearch(arr, low, (mid -1), key);
}
//int binSearch(int arr[],int l,int h,int key)
//{
//    if(l>h || l==h)
//    return 0;
//    
//    int mid = l + (h-l)/2;
//    if(arr[mid] == key)
//    {
//        cout<<"Key is "<<arr[mid]<<endl;
//        return 1;
//    }
//    if(key<arr[mid])
//    {
//       return binSearch(arr, l, mid, key);
//    }
//    return binSearch(arr, mid+1, h, key);
//}


int findPivot(int arr[],int l,int h){
    if(h<l)
        return -1;
    if(h==l)
        return -1;
    int mid = (l + h)/2;
    if(mid<h && arr[mid]>arr[mid+1])
    {
        return mid;
    }
    if(mid>l && arr[mid]<arr[mid-1])
    {
        return mid-1;
    }
    if(arr[mid]<arr[l])
        return findPivot(arr, l, mid-1);
    return findPivot(arr, mid+1, h);
    
}
int pivotedBinarySearch(int arr[], int n, int key)
{
    int pivot = findPivot(arr, 0, n-1);
    cout << "Pivot is " << pivot << endl;
    // If we didn't find a pivot, then array is not rotated at all
    if (pivot == -1)
      return binarySearch(arr, 0, n-1, key);
    
    // If we found a pivot, then first compare with pivot and then
    // search in two subarrays around pivot
    if (arr[pivot] == key)
      return pivot;
  
    if (arr[0] <= key)
      return binarySearch(arr, 0, pivot-1, key);
  
    return binarySearch(arr, pivot+1, n-1, key);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    int arr[] = {3, 4, 5, 6, 7, 1, 2};
    int size = sizeof(arr)/sizeof(arr[0]);
    int key = 1;
    cout<<pivotedBinarySearch(arr,size, key);
//    cout<<binSearch(arr, 0, size,key);
    return 0;
}
