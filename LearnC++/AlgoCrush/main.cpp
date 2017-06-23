//
//  main.cpp
//  AlgoCrush
//
//  Created by Aviral Aggarwal on 23/06/17.
//  Copyright © 2017 Aviral Aggarwal. All rights reserved.
//

//#include <iostream>
//
//int main(int argc, const char * argv[]) {
//    // insert code here...
//    std::cout << "Hello, World!\n";
//    return 0;
//}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void printArr(long int arr[],long int N)
{
    for(int i=0;i<N;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(int argc, const char * argv[]) {
    long int N,K,p,q,sum,i,j,max=0,x=0;
    
    cin>>N>>K;
    long int *a=new long int[N+1]();
    
    for(i=0;i<K;i++)
    {
        cin>>p>>q>>sum;
        a[p]+=sum;
        if((q+1)<=N) a[q+1]-=sum;
        printArr(a, N);
    }
    
    for(i=1;i<=N;i++)
    {
        x=x+a[i];
        if(max<x) max=x;
        
    }
    
    cout<<max;
    return 0;
}
