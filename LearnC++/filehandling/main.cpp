//
//  main.cpp
//  filehandling
//
//  Created by Aviral Aggarwal on 07/07/17.
//  Copyright © 2017 Aviral Aggarwal. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main () {
    char data[100],filename[100];
    
    
//    //Using Ofstream and ifstream objects
//    ofstream outfile;
//    cout<<"Enter the name of the file";
//    cin>>filename;
//    cin.ignore();
//    outfile.open(filename,ios::out|ios::app);
//    cout<<endl<<"Writing to the File";
////    outfile.seekg(0);
//    cout<<"Enter Your name";
//    cin.getline(data,100);
//    
//    outfile<<data<<endl;
//    
//    cout<<"Enter your Age";
//    cin>>data;
//    cin.ignore();
//    
//    outfile<<data<<endl;
//    outfile.close();
//    
//    ifstream infile;
//    infile.open(filename,ios::in);
//    
//    cout << "Reading from the file" << endl;
//    infile>>data;
////    while(infile>>data)
////    {
////        cout << data << endl;
//////        infile>>data;
////    }
//    
//    while(!infile.eof())
//    {
//        cout << data << endl;
//                infile>>data;
//    }
//
//    // close the opened file.
//    infile.close();

    //Using fstream object
    fstream file;
    cout<<"Enter the name of the file";
    cin>>filename;
    cin.ignore();
    file.open(filename,ios::out|ios::in|ios::app);
    cout<<endl<<"Writing to the File";
    //    outfile.seekg(0);
    cout<<"Enter Your name";
    cin.getline(data,100);
    
    file<<data<<endl;
    
    cout<<"Enter your Age";
    cin>>data;
    cin.ignore();
    
    file<<data<<endl;
    
//    ifstream infile;
//    infile.open(filename,ios::in);
    file.seekg(0);
    cout << "Reading from the file" << endl;
    file>>data;
    //    while(infile>>data)
    //    {
    //        cout << data << endl;
    ////        infile>>data;
    //    }
    
    while(!file.eof())
    {
        cout << data << endl;
        file>>data;
    }
    //    infile >> data;
    //
    //    // write the data at the screen.
    //    cout << data << endl;
    //
    //    // again read the data from the file and display it.
    //    infile >> data;
    //    cout << data << endl;
    
    // close the opened file.
    file.close();

    
    
    
    return 0;
}
