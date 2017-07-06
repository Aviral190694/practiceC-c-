//
//  main.cpp
//  Polymorphism
//
//  Created by Aviral Aggarwal on 07/07/17.
//  Copyright © 2017 Aviral Aggarwal. All rights reserved.
//

#include <iostream>
using namespace std;

class Shape{
protected:
    int width;
    int height;
public:
    
    Shape(int wid,int hei);
    virtual int area() = 0;
};

class Rectangle: public Shape
{
public:
    Rectangle(int wid, int hei);
    int area()
    {
        cout<<"Rectanle Area is ";
        return width*height;
    }
};

class Triangle : public Shape
{
public:
    Triangle(int wid, int hei);
    int area()
    {
        cout<<"Traingle Area is ";
        return (width*height)/2;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Shape *ptr;
    Rectangle rect(10,20);
    Triangle tri(10,20);
    ptr = &rect;
    cout<<ptr->area();
    ptr = &tri;
    cout<<ptr->area();
    
    return 0;
}
Triangle::Triangle(int wid, int hei) : Shape(wid,hei) {
    
}


Rectangle::Rectangle(int wid , int hei)  : Shape(wid,hei) {
    
}

Shape::Shape(int wid,int hei)
{
    width = wid;
    height = hei;
}
