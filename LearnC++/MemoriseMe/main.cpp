//
//  main.cpp
//  MemoriseMe
//
//  Created by Aviral Aggarwal on 23/06/17.
//  Copyright © 2017 Aviral Aggarwal. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,Q,Bi;
    cin>>N;
    int arr[1001] = {0};
    for(int i=0;i<N;i++)
    {
        cin>>Bi;
        arr[Bi]++;
    }
    cin>>Q;
    while (Q--) {
        cin>>Bi;
        if(arr[Bi]==0)
            cout<<"NOT PRESENT"<<endl;
        else
            cout<<arr[Bi]<<endl;
    }
    return 0;
}
