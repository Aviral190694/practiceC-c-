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
  //Using fstream object
  fstream file;
  
  cout<<"Enter the name of the file";
  cin>>filename;
  cin.ignore();
  
  file.open(filename,ios::out|ios::in|ios::app);
  
  cout<<endl<<"Writing to the File";
  cout<<"Enter Your name";
  cin.getline(data,100);
  
  //Writing to the File
  file<<data<<endl;
  
  cout<<"Enter your Age";
  cin>>data;
  cin.ignore();
  file<<data<<endl;
  
  file.seekg(0);
  cout << "Reading from the file" << endl;
  file>>data;
  
  while(!file.eof()) {
    cout << data << endl;
    file>>data;
  }
  // close the opened file.
  file.close();
  return 0;
}
