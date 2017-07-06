//
//  main.cpp
//  overloadingOverriding
//
//  Created by Aviral Aggarwal on 06/07/17.
//  Copyright © 2017 Aviral Aggarwal. All rights reserved.
//

#include <iostream>
using namespace std;

enum class test {
    diamonds = 1,clubs,hearts,spades
};

class sum{
    int a;
public:
    sum()
    {
        a = 10;
    }
    void display()
    {
        cout<<"Sum is "<<a;
    }
    sum operator+(const sum &obj);
    sum operator-();
    friend ostream &operator<<( ostream &output,
                        const sum &D ) {
        output << "F : " << D.a ;
        return output;
    }
    friend istream &operator>>( istream &input,sum&D)
    {
        input >> D.a;
        return input;
    }
    
    void operator++()
    {
        this->a++;
    }
    void operator++(int)
    {
        a = a +2;
    }
    
    sum operator()(int a, int b, int c)
    {
        sum newObj;
        cout<<"Hey";
        newObj.a = this->a + a + b + c;
        return newObj;
        
    }
};

sum sum::operator-()
{
    sum newObj;
    newObj.a = this->a;
    newObj.a--;
    return newObj;
}

sum sum::operator+(const sum &obj)
{
    sum newObj;
    newObj.a = this->a + obj.a;
    return newObj;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    int a = 10;
    int b = 10;
    int c = 0;
    c = a + b;
//    int d = int(test::hearts);
    cout<<c<<" "<<int(test::hearts);
    
    sum first;
    sum second;
    sum third;
    sum fourth;
    cin >> first;
    third = first + second;
    third.display();
    fourth = -third;
    third++;
    third.display();
    fourth.display();
    sum fifth;
    fifth = third(10,20,30);
    cout<<"The text is "<<fourth;
    cout<<fourth;
    fifth.display();
    cout<<fifth;
    return 0;
}
