//
//  main.cpp
//  STLLibraries
//
//  Created by Aviral Aggarwal on 08/07/17.
//  Copyright © 2017 Aviral Aggarwal. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...

    vector<int> vec;
    int i;
    cout<<"Vector Size"<<vec.size()<<endl;
    
    for (i=0; i<5; i++) {
        vec.push_back(i);
    }
    cout<<"Vector Size"<<vec.size()<<endl;
    
    for (i=0; i<5; i++) {
        cout<<vec[i]<<" ";
    }
    cout<<endl;
    
    cout<<vec.end()-vec.begin();
//    vector<int>::iterator v=vec.begin();
//    while (v!=vec.end()) {
//        cout<<*v<<" ";
//        v++;
//    }
    
    vector<int> vect;
    for(int i=0;i<20;i++)
    {
        vect.push_back(i*i);
    }
    
    if(find(vect.begin(), vect.end(), 361)!=vect.end())
    {
        cout<<"The element is present";
    }
//    vector<int>::iterator v= vect.begin();
//    while(v!=vect.end())
//    {
//        
//        v++;
//    }
//    
    
    
    int data[] = {100,10,20,30,40,50,10,20};
    
//    vector <int> test(data,data+8);
    vector<int> test {1100,10,20,30,40,50,10,20};
    set <int> s(test.begin(),test.end());
    
    for (set<int>::const_iterator vi=s.begin() ; vi!=s.end(); vi++) {
        cout<<*vi<<" ";
    }
    
    vector<int> v2(s.begin(),s.end());
    for (vector<int>::const_iterator vii=v2.begin() ; vii!=v2.end(); vii++) {
        cout<<*vii<<" ";
    }
    
    
    
    
//    for(int i=1;i<=100;i++)
//    {
//        s.insert(i);
//    }
//    s.insert(42);
    
    
    
//Pointers
////     std::cout << "Hello, World!\n";
//  
//    char s1[] = "Hello";
//    cout<<s1<<" "<<sizeof(s1)<<" "<<sizeof(*s1)<<" ";
////    cout<<typeid(s1).name();
//    int a[2][3] = {{1,2,3},{4,5,6}};
//    cout<<sizeof(&a)<<endl;
//
//    int a[5] = {1, 2, 3, 4, 5};
//    int *p = &a[0];
//    
  
    
    
    return 0;
}
