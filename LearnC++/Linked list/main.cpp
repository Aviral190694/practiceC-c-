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
//print Nth Node
//Print Nth Node from Back
//Reverse the linklist.
//Reverse K-Alt Nodes in a linklist.
//Merge Sort
//Reverse k-Alt Nodes
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
    void printMiddle();
    void printNthNode(int n);
    void printNthNodeLast(int n);
    void printNthNodeLastTwoPointers(int n);
    void reverse();
    void testReverse();
    void kAltReverse(int k);
    node* kAltReverseInt(node *tmp,int k);
    node* kAltReverseIntFlipAll(node *tmp,int k);
    void mergeSort();
    void mergeS(node **ptr);
    node* sortedMerge(node *left, node * right);
    void partition(node *ptr,node **left, node **right);
};

void Linklist::mergeSort()
{
    if(head == NULL || head->next == NULL)
    {
        return;
    }
    mergeS(&head);
}

void Linklist::partition(node *ptr,node **left, node **right) {
  
    if (ptr == NULL || ptr->next == NULL) {
        *left = ptr;
        *right = NULL;
        return;
    }
    
    node *slow = ptr;
    node *fast = ptr->next;
  
    while (fast != NULL && fast->next != NULL) {
        slow= slow->next;
        fast = fast->next->next;
    }
    
    *left = ptr;
    *right = slow->next;
    slow->next = NULL;
    
}

node * Linklist::sortedMerge(node *left, node *right)
{
    node *result=NULL;
    node *tail;
    
    if(left ==NULL)
    {
        return right;
    }
    if(right ==NULL)
    {
        return left;
    }
    
    while(left!=NULL && right!=NULL)
    {
        if(left->val<right->val)
        {
            if(result ==NULL)
            {
                result = left;
                tail = left;
            }
            else
            {
                tail->next = left;
                tail = tail->next;
            }
            left = left->next;
        }
        else{
            if(result ==NULL)
            {
                result = right;
                tail = right;
            }
            else
            {
                tail->next = right;
                tail = tail->next;
            }
            right = right->next;
        }
    }
    
    while(left!=NULL)
    {
        tail->next = left;
        tail = tail->next;
        left = left->next;
    }
    
    while(right!=NULL)
    {
        tail->next = right;
        tail = tail->next;
        right = right->next;
    }
    return result;
}

void Linklist::mergeS(node **ptr)
{
    
    node *tmp = *ptr;
    node *left = NULL;
    node* right = NULL;
    if(tmp == NULL || tmp->next ==NULL)
    {
        return;
    }
   
    partition(tmp,&left, &right);
    
    mergeS(&left);
    mergeS(&right);
    
    *ptr = sortedMerge(left, right);
    
    
}

node* Linklist::kAltReverseIntFlipAll(node *tmp, int k)
{
    node *current = tmp;
    node *prev = NULL;
    node* next;
    
    int count = 0;
    while(current !=NULL && count<k)
    {
        count++;
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    if(tmp!=NULL)
    {
        tmp->next = kAltReverseInt(current, k);;
    }
    
    //    count = 0;
    //    while(current!=NULL && count<k-1)
    //    {
    //        count++;
    //        current = current->next;
    //    }
    
    //    if(current!=NULL)
    //    {
    //        current->next = kAltReverseInt(current->next, k);
    //    }
    
    return prev;
}

node* Linklist::kAltReverseInt(node *tmp, int k)
{
    node *current = tmp;
    node *prev = NULL;
    node* next;
    
    int count = 0;
    while(current !=NULL && count<k)
    {
        count++;
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    if(tmp!=NULL)
    {
        tmp->next = current;
    }
    
    count = 0;
    while(current!=NULL && count<k-1)
    {
        count++;
        current = current->next;
    }
    
    if(current!=NULL)
    {
        current->next = kAltReverseInt(current->next, k);
    }
    
    return prev;
}
void Linklist::kAltReverse(int k)
{
    if(head == NULL)
    {
        cout<<"The List is empty";
        return;
    }
    head = kAltReverseInt(head, k);
}

void Linklist::testReverse()
{
     node* prev   = NULL;
     node* current = head;
     node* next;
    while (current != NULL)
    {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}


void Linklist::reverse()
{
    
    if(head == NULL) {
        cout<<"The list is empty";
        return;
    }
    
    if(head->next == NULL)
        return;
    
    node *current = head->next;
    node *prev = head;
    node *next = NULL;
    
    while (current) {
      next = current->next;
      current->next = prev;
      
      if(prev == head)
            prev->next = NULL;
      prev = current;
      current = next;
    }
    
    head = prev;
    
}

void Linklist::printNthNodeLastTwoPointers(int n)
{
    node *main = head;
    node *ref = head;
    
    
    if(head == NULL || n<0)
    {
        cout<<"List is Empty";
        return;
    }
    
    while(ref!=NULL && n>=0)
    {
        ref=ref->next;
        n--;
    }
    
    if(n==-1 && ref==NULL)
    {
        cout<<"Nth Element is "<<main->val<<endl;
        return;
    }
    
    if(ref==NULL)
    {
        cout<<"Out of list"<<endl;
        return;
    }
    
    while(ref!=NULL)
    {
        main=main->next;
        ref=ref->next;
    }
    cout<<"Nth Element is "<<main->val<<endl;
    
}



void Linklist::printNthNodeLast(int n){
    
    int length = getLength();
    if(n>length)
    {
        cout<<"out of list";
        return;
    }
    printNthNode(length-n-1);
    
}

void Linklist::printNthNode(int n)
{
    if(head == NULL)
    {
        cout<<"List is Empty";
        return;
    }
    node *tmp = head;
    
    while(tmp && n>0)
    {
        tmp=tmp->next;
        n--;
    }
    
    if(tmp == NULL)
    {
        cout<<"Out of list";
        return;
    }
    cout<<"Nth Element is "<<tmp->val<<endl;
    
}

void Linklist::printMiddle()
{
    if(head==NULL)
    {
        cout<<"List is Empty";
        return;
    }
    node *ptr=head;
    node *fastptr = head;
    while(fastptr!=NULL && fastptr->next!=NULL)
    {
        ptr = ptr->next;
        fastptr = fastptr->next->next;
    }
    cout<<"Middle is "<<ptr->val<<endl;
}

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
    list.insertNode(90);
    list.displayNode();
    list.insertNode(40);
    list.insertNode(110);
    list.displayNode();
    list.insertNode(60);
    list.insertNode(202);
    
    list.insertNode(50);
    list.displayNode();
    list.kAltReverse(2);
    cout<<"KAltReverse";list.displayNode();
    list.reverse();
    list.displayNode();
    list.reverse();
    list.displayNode();
    list.kAltReverse(2);
    cout<<"KAltReverse";list.displayNode();
    list.mergeSort();
    cout<<"Merge Sort";list.displayNode();
    list.printMiddle();
    list.deleteKey(20);
    list.deleteKey(20);
    list.deleteKey(20);
    list.deleteKey(20);
    list.deleteKey(20);
    list.insertNode(20);
    list.displayNode();
    list.printMiddle();
    
    cout<<"Length is "<<list.getLength()<<endl;
    
    list.deleteKeyByPos(4);
    
    list.deleteKeyByPos(4);
    
    list.deleteKeyByPos(2);
     list.displayNode();
    
    cout<<"Length is "<<list.getLength()<<endl;
    list.insertNode(20);
    list.swap(20,30);
    list.displayNode();
    list.printMiddle();
//    list.printNthNode(1);
    list.printNthNodeLast(3);
    list.printNthNodeLastTwoPointers(1);
    list.reverse();
    list.displayNode();
    list.testReverse();
    list.displayNode();
    
//    list.printNthNodeLastTwoPointers(5);
    
    return 0;
}
