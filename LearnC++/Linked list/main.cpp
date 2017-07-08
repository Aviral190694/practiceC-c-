//
//  main.cpp
//  Linked list
//
//  Created by Aviral Aggarwal on 16/06/17.
//  Copyright © 2017 Aviral Aggarwal. All rights reserved.
//

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
};

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
    list.displayNode();
    list.insertNode(10);
    list.insertNode(20);
    list.displayNode();
    list.insertNode(10);
    list.insertNode(20);
    list.displayNode();
    list.insertNode(10);
    list.insertNode(20);
    list.displayNode();
    list.insertNode(10);
    list.insertNode(20);
    list.displayNode();
    
    return 0;
}
