//
//  main.cpp
//  ArrayPractice
//
//  Created by Aviral Aggarwal on 22/07/17.
//  Copyright © 2017 Aviral Aggarwal. All rights reserved.
//

#include <iostream>
using namespace std;

void fun(int arr[]) {
  int i;
  int arr_size = sizeof(arr)/sizeof(arr[0]);
  
  for (i = 0; i < arr_size; i++) {
    arr[i] = i;  
  }
}

int printFirst(int ptr[]) {
  int x = 100;
  
  cout << "Size of Ptr is " << sizeof(*ptr) << endl;
  cout << "First Variable is " << *ptr << endl;
  
  ptr = &x;
  cout << "address Swap Value is " << *ptr << endl;
  
  return 0;
}

int main(int argc, const char * argv[]) {
  
  int arr[] = {10,20,30,40,50,60};
  int len = sizeof(arr)/sizeof(arr[0]);
  cout << "Array length is " << len << endl;
  printFirst(arr);
  return 0;
}
