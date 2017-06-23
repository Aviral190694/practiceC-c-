//
//  main.cpp
//  BinaryQueries
//
//  Created by Aviral Aggarwal on 23/06/17.
//  Copyright © 2017 Aviral Aggarwal. All rights reserved.
//

#include <iostream>
using namespace std;

void checkOddEven(int arr[],int L,int R);

int main(int argc, const char * argv[]) {
    // insert code here...
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     int N,Q,L,R,X,testBit;
    cin>>N>>Q;
    
     int *arr=new int[N]();
    
    for (int i=0;i<N; i++)
        cin>>arr[i];
    
    while(Q--)
    {
        cin>>testBit;
        if(testBit)
        {
            cin>>X;
            //Flipping the bit;
            arr[X-1] = (arr[X-1] + 1)%2;
//            if(arr[X-1])
//            {
//                arr[X-1]=0;
//            }
//            else{
//                arr[X-1]=1;
//            }
        }
        else
        {
            cin>>L>>R;
            checkOddEven(arr, L, R);
        }
    }
    
    return 0;
}

void checkOddEven(int arr[],int L,int R)
{
    int sum = 0;
    for (int i=L-1; i<R; i++) {
        sum = sum*2 + arr[i];
    }
    if(sum%2==0)
        cout<<"EVEN"<<endl;
    else
        cout<<"ODD"<<endl;
}
