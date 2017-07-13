//
//  main.cpp
//  Linked list
//
//  Created by Aviral Aggarwal on 16/06/17.
//  Copyright © 2017 Aviral Aggarwal. All rights reserved.
//

//LinkList to Insert a key
//Display the linklist
//Search a Linklist
//Delete a key from a linkList
//Delete a node by Position
//Length of a linklist
#include <iostream>
using namespace std;

//void insert(int val);


struct node
{
    int val;
    node *next;
};

class Linklist
{
    node *head,*tail;
public:
    Linklist()
    {
        head = NULL;
//        tail = NULL;
    }
    void insertNode(int val);
    node* reachEnd(node *tmp);
    void displayNode();
    void searchKey(int key);
    void deleteKey(int key);
    void deleteKeyByPos(int pos);
    int getLength();
    //int getLengthRec(node *tmp);
    void swap(int x,int y);
};

void Linklist::swap(int x, int y)
{
    if(x == y)
    {
        return;
    }
//    if(head == NULL && head->next == NULL)
//    {
//        cout<<"Not possible to Swap : List has elements less than 2"<<endl;
//    }
    cout<<"Hello"<<endl;
    node *currX=NULL,*currY=NULL;
    node *prevX=NULL,*prevY=NULL;
    
    currX = head;
    while(currX && currX->val!=x)
    {
        prevX = currX;
        currX=currX->next;
    }
    currY = head;
    while(currY && currY->val!=y)
    {
        prevY = currY;
        currY=currY->next;
    }
    
    if(currY == NULL || currX == NULL)
    {
        cout<<"Element is not present"<<endl;
        return;
    }
    
    
    if(prevX!=NULL)
        prevX->next = currY;
    else
        head = currY;
    
    
    if(prevY!=NULL)
        prevY->next = currX;
    else
        head = currX;
    
    
    node *tmp2 = currY->next;
    currY->next = currX->next;
    currX->next = tmp2;
    
    return;
    
    
}

int Linklist::getLength()
{
    int length = 0;
    node *tmp = new node();
    tmp = head;
    while(tmp!=NULL)
    {
        length++;
        tmp=tmp->next;
    }
    return length;
}

void Linklist::deleteKeyByPos(int pos)
{
    
    if(head == NULL)
    {
        cout<<"The list is Empty";
        return;
    }
    
    node *tmp = new node();
    tmp = head;
    if(pos == 0)
    {
        head = head->next;
        delete(tmp);
    }
    
    
    for(int i=0; i<pos-1 && tmp!=NULL;i++)
    {
        tmp=tmp->next;
    }
    
    if(tmp ==NULL || tmp->next==NULL)
    {
        cout<<"Error : Element is not present"<<endl;
        return;
    }
    
    node *tmp2 = new node();
    tmp2= tmp->next;
    tmp->next = tmp2->next;
    delete(tmp2);
    return;
}

void Linklist::deleteKey(int key)
{
    if(head == NULL)
    {
        cout<<"The list is empty";
        return;
    }
    node *prev,*tmp;
    tmp = head;
    prev = head;
    
    while(tmp!=NULL)
    {
        if(tmp->val == key)
        {
            cout<<"Deleting the Node"<<endl;
            if(tmp == head)
            {
                head = head->next;
            }
            else
            {
                prev->next = tmp->next;
            }
            delete(tmp);
            return;
        }
        prev = tmp;
        tmp=tmp->next;
    }
    cout<<"Element is not Present"<<endl;
    return;
    
}

void Linklist::searchKey(int key)
{
    if(head==NULL)
    {
        cout<<"Search Key is not present"<<endl;
        return;
    }
    node *ptr = new node();
    ptr = head;
    while(ptr!=NULL)
    {
        if(ptr->val == key)
        {
            cout<<"Search Key is Present";
            return ;
        }
        ptr=ptr->next;
        
    }
    cout<<"Search Key is not Present";
    return;
}

void Linklist::insertNode(int val)
{
    node *ptr = new node();
        ptr->val = val;
        ptr->next = NULL;
        if(head == NULL)
        {
            head = ptr;
//            tail = ptr;
            ptr = NULL;
//            delete(ptr);
        }
        else{
            node *tmp = head;
//            while(tmp->next !=NULL)
//            {
//                tmp = tmp->next;
//            }
            tmp = reachEnd(tmp);
            tmp->next = ptr;
        }
    
}

node* Linklist::reachEnd(node *tmp)
{
    if(tmp == NULL)
    {
        return tmp;
    }
    else
    {
        while(tmp->next !=NULL)
        {
            tmp = tmp->next;
        }
        return tmp;
    }
}
void Linklist::displayNode()
{
    node *tmp = head;
    if(tmp == NULL)
    {
        cout<<"The list is empty";
    }
    else{
        while(tmp != NULL)
        {
            cout<<tmp->val<<" ";
            tmp = tmp->next;

        }
    }
    cout<<endl;
}

//node reachEnd(node *tmp);
//void displayNode();

int main(int argc, const char * argv[]) {
    // insert code here...
    Linklist list;
    cout<<"Length is "<<list.getLength()<<endl;
    list.deleteKey(20);
    list.searchKey(20);
    list.displayNode();
    list.insertNode(10);
    list.insertNode(20);
    list.displayNode();
    list.insertNode(30);
    list.insertNode(20);
    list.displayNode();
    list.insertNode(40);
    list.insertNode(20);
    list.displayNode();
    list.insertNode(60);
    list.insertNode(20);
    list.displayNode();
    list.deleteKey(20);
    list.deleteKey(20);
    list.deleteKey(20);
    list.deleteKey(20);
    list.deleteKey(20);
    list.insertNode(20);
    list.displayNode();
    
    cout<<"Length is "<<list.getLength()<<endl;
    list.deleteKeyByPos(4);
    
    list.deleteKeyByPos(4);
    
    list.deleteKeyByPos(2);
     list.displayNode();
    
    cout<<"Length is "<<list.getLength()<<endl;
    list.insertNode(20);
    list.swap(20,30);
    list.displayNode();
    return 0;
}
