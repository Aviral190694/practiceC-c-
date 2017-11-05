//
//  main.cpp
//  Trees
//
//  Created by Aviral Aggarwal on 16/07/17.
//  Copyright © 2017 Aviral Aggarwal. All rights reserved.
//

#include <iostream>
using namespace std;

struct tree{
  int val;
  tree *left;
  tree *right;
};

struct queue {
  tree *tNode;
  queue *next;
};

int isSumProperty(struct tree* node)
{
  /* left_data is left child data and right_data is for right
   child data*/
  int left_data = 0,  right_data = 0;
  
  /* If node is NULL or it's a leaf node then
   return true */
  if(node == NULL ||
     (node->left == NULL && node->right == NULL))
    return 1;
  else
  {
    /* If left child is not present then 0 is used
     as data of left child */
    if(node->left != NULL)
      left_data = node->left->val;
    
    /* If right child is not present then 0 is used
     as data of right child */
    if(node->right != NULL)
      right_data = node->right->val;
    
    /* if the node and both of its children satisfy the
     property return 1 else 0*/
    if((node->val == left_data + right_data)&&
       isSumProperty(node->left) &&
       isSumProperty(node->right))
      return 1;
    else
      return 0;
  }
}


int height(tree *node) {
  if (node == NULL) {
    return 0;
  }
  
  int leftHeight = height(node->left);
  int rightHeight = height(node->right);
  
  if (leftHeight > rightHeight)
    return leftHeight + 1;
  else
    return rightHeight + 1;
}


/* Print nodes at a given level */
void printGivenLevel(struct tree* root, int level, int ltr)
{
  if(root == NULL)
    return;
  if(level == 1)
    printf("%d ", root->val);
  else if (level > 1)
  {
    if(ltr)
    {
      printGivenLevel(root->left, level-1, ltr);
      printGivenLevel(root->right, level-1, ltr);
    }
    else
    {
      printGivenLevel(root->right, level-1, ltr);
      printGivenLevel(root->left, level-1, ltr);
    }
  }
}


void printSpiral(tree* root)
{
  int h = height(root);
  int i;
  
  /*ltr -> Left to Right. If this variable is set,
   then the given level is traverseed from left to right. */
  bool ltr = false;
  for(i=1; i<=h; i++)
  {
    printGivenLevel(root, i, ltr);
    
    /*Revert ltr to traverse next level in opposite order*/
    ltr = !ltr;
  }
}


int calLeaf(tree *node) {
  if (node ==  NULL)
    return 0;
  if (node->left == NULL && node->right == NULL)
    return 1;
  else
    return calLeaf(node->left) + calLeaf(node->right);
}

void mirror(tree *node) {
  if (node == NULL)
    return;
  
  mirror(node->left);
  mirror(node->right);
  
  tree *temp;
  temp = node->left;
  node->left = node->right;
  node->right = temp;
}

int size(tree *node) {
  if (node==NULL)
    return 0;
  else
    return size(node->left) + size(node->right) + 1;
}

void bfsLevel(tree *node,int level) {
  
  if (node == NULL)
    return;
  
  if (level == 1) {
    cout << node->val << " ";
  }
  else {
    bfsLevel(node->left, level-1);
    bfsLevel(node->right, level-1);
  }
  
}

void bfs(tree *node) {
  int treeHeight = height(node);
  
  for(int i=1; i<=treeHeight; i++) {
    bfsLevel(node,i);
    cout<<endl;
  }
}

void printTreeInOrder(tree *node) {
  if (node == NULL)
    return;
  
  printTreeInOrder(node->left);
  cout << " " << node->val;
  printTreeInOrder(node->right);
}

void printTreePostOrder(tree *node) {
  if (node == NULL)
    return;
 
  printTreeInOrder(node->left);
  printTreeInOrder(node->right);
  cout << " " << node->val;
}

void printTreePreOrder(tree *node) {
  if (node == NULL)
    return;
  
  cout << " " << node->val;
  printTreeInOrder(node->left);
  printTreeInOrder(node->right);
}

tree* addNode(int val) {
  tree *node = new tree();
  
  node->val = val;
  node->left = NULL;
  node->right = NULL;
  return node;
}

int getTreeHeight(tree *node) {
  
  if (node == NULL) {
    return 0;
  }
  
  int lHeight = getTreeHeight(node->left);
  int rHeight = getTreeHeight(node->right);
  
  if (lHeight > rHeight)
    return lHeight + 1;
  else
    return rHeight + 1;
  
}

void printGivenLevel(tree *node, int level) {
  if (node == NULL)
    return;
  
  if (level == 1) {
    cout << node->val << " ";
  }
  else if (level > 1) {
    printGivenLevel(node->left, level -1);
    printGivenLevel(node->right, level - 1);
  }
  
}



void printLevelOrder(tree *node) {
  
  if (node == NULL)
    return;
  
  int height = getTreeHeight(node);
  
  for (int i=0; i<height; i++) {
    printGivenLevel(node, i+1);
  }
  
}

int queueHeight(queue *front) {
  
  int height = 0;
  while (front != NULL) {
    height++;
    front = front->next;
  }
  
  return height;
}

queue* addNode(tree *node) {
  
  queue *qNode = new queue();
  qNode->tNode = node;
  qNode->next = NULL;
  return qNode;
}

queue* pushToQueue(queue *front, tree *node) {
  if (front == NULL) {
    front = addNode(node);
    return front;
  }
  queue *tmp = front;
  while (front->next != NULL)
    front = front->next;
  
  front->next = addNode(node);
  return tmp;
}

queue* removeFront(queue *front) {
  if (front == NULL) {
    return NULL;
  }
  
  if (front->next == NULL) {
    delete(front);
    return NULL;
  }
  
  queue *tmp = front;
  front = front->next;
  delete(tmp);
  return front;
  
}

void printLevelOrderQueue(tree *node) {
  if (node == NULL)
    return;
  
  queue *front;
  front = addNode(node);
  
  while (1) {
    
    int nodeCount = queueHeight(front);
    
    if (nodeCount == 0) {
      break;
    }
    
    while (nodeCount > 0) {
      tree *treeNode = front->tNode;
      cout << treeNode->val << " ";
      front = removeFront(front);
      
      if (treeNode->left != NULL) {
        front = pushToQueue(front, treeNode->left);
      }
      
      if (treeNode->right != NULL) {
        front = pushToQueue(front, treeNode->right);
      }
      nodeCount--;
    }
    cout << endl;
  }
  
  
}

int main(int argc, const char * argv[]) {
  // insert code here...
  cout << "Hello, World!\n";
  tree *root= addNode(10);
  root->left = addNode(20);
  root->right = addNode(30);
  root->left->left = addNode(40);
  root->left->right = addNode(50);
  root->right->left = addNode(60);
  root->right->right = addNode(70);
  cout << "Height of the tree is " << getTreeHeight(root) << endl;
  printLevelOrderQueue(root);
  cout << endl;
  cout << "Level order is " << "\n";
  printLevelOrder(root);
  cout << endl;
  printTreeInOrder(root);
  cout<<endl;
  printTreePreOrder(root);
  cout<<endl;
  printTreePostOrder(root);
  cout<<endl;
  bfs(root);
  cout<<size(root)<<endl;
  bfs(root);
  mirror(root);
  cout<<endl;
  bfs(root);
  cout<<"Leafs are"<<calLeaf(root)<<endl;
  printSpiral(root);
  cout<<" "<<isSumProperty(root)<<" ";
  return 0;
}

