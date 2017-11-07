//
//  main.cpp
//  PriyanshLinkListDemo
//
//  Created by Aviral Aggarwal on 07/11/17.
//  Copyright © 2017 Aviral Aggarwal. All rights reserved.
//

#include <iostream>
using namespace std;

struct Node {
  int val;
  Node *next;
};

int sumLinkList(Node *head) {
  
  Node *tmp = head;
  Node *curr = head;
  int sum = 0;
  
  while (tmp != NULL) {
    sum += tmp->val;
    
    if (tmp->val == 0) {
      cout << sum << " ";
      curr->val = sum;
      curr->next = tmp->next;
      curr = curr->next;
      sum = 0;
    }
    
    tmp = tmp->next;
  }
  
  if (sum > 0) {
    cout << sum << endl;
    curr->val = sum;
    curr->next = NULL;
  }
  return sum;
}

void printLinkedList(Node *head) {
  Node *tmp = head;
  
  while (tmp->next != NULL) {
    cout << tmp->val << " -> ";
    tmp = tmp->next;
  }
  cout << tmp->val << endl;
}

Node* insertNode(int val) {
  Node *tmp = new Node();
  tmp->val = val;
  tmp->next = NULL;
  return tmp;
}

Node* insertNode(Node *head, int val) {
  
  if (head == NULL) {
    return insertNode(val);
  }
  
  Node *tmp = head;
  while (tmp->next != NULL) {
    tmp = tmp->next;
  }
  
  tmp->next = insertNode(val);
  return head;
}

int main(int argc, const char * argv[]) {
  //Create LinkList
  Node *head;

  head = insertNode(head, 8);
  head = insertNode(head, 3);
  head = insertNode(head, 0);
  head = insertNode(head, 8);
  head = insertNode(head, 5);
  head = insertNode(head, 0);
  head = insertNode(head, 7);
  printLinkedList(head);
  
  cout << "Sum is " << sumLinkList(head) << endl;
  printLinkedList(head);
  return 0;
}
