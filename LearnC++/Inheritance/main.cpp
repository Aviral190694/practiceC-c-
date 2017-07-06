//
//  main.cpp
//  Inheritance
//
//  Created by Aviral Aggarwal on 06/07/17.
//  Copyright © 2017 Aviral Aggarwal. All rights reserved.
//

#include <iostream>
using namespace std;

class Shape {
    int width;
    int height;
public:
    void setHeight(int ht);
    void setWidth(int wd);
    int getWidth();
    int getHeight();
};

class Rectanlge : public Shape
{
public:
    void printArea();
};


int main(int argc, const char * argv[]) {
    // insert code here...
    
    Rectanlge rect;
    rect.setWidth(10);
    rect.setHeight(20);
    rect.printArea();
    
    return 0;
}

void Shape:: setHeight(int ht){
    height = ht;
}
void Shape:: setWidth(int wd){
    width = wd;
}
int Shape::getWidth(){
    return width;
}
int Shape::getHeight(){
    return height;
}
void Rectanlge::printArea(){
    cout<<"Area of the Rectangle is "<<getHeight()*getWidth()<<endl;
}
