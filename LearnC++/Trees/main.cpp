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

int calLeaf(tree *node)
{
    if(node ==NULL)
        return 0;
    if(node->left == NULL && node->right ==NULL)
        return 1;
    else
        return calLeaf(node->left) + calLeaf(node->right);
}

void mirror(tree *node)
{
    if(node == NULL)
        return;
    
    mirror(node->left);
    mirror(node->right);
    
    tree *temp;
    temp = node->left;
    node->left = node->right;
    node->right = temp;
}

int size(tree *node)
{
    if(node==NULL)
        return 0;
    else
        return size(node->left) + size(node->right) + 1;
}

int height(tree *node)
{
    if(node == NULL)
    {
        return 0;
    }
    int leftHeight= height(node->left);
    int rightHeight = height(node->right);
    
    if(leftHeight>rightHeight)
        return leftHeight+1;
    else
        return rightHeight+1;
    
}

void bfsLevel(tree *node,int level)
{
    if(node == NULL)
        return;
    if(level ==1)
    {
        cout<<node->val<<" ";
    }
    else{
        bfsLevel(node->left, level-1);
        bfsLevel(node->right, level-1);
    }
    
}

void bfs(tree *node)
{
    int treeHeight = height(node);
    for(int i=1;i<=treeHeight;i++)
    {
        bfsLevel(node,i);
        cout<<endl;
    }
}

void printTreeInOrder(tree *node){
    if(node == NULL)
        return;
    printTreeInOrder(node->left);
    cout<<" "<<node->val;
    printTreeInOrder(node->right);
}

void printTreePostOrder(tree *node){
    if(node == NULL)
        return;
    printTreeInOrder(node->left);
    printTreeInOrder(node->right);
    cout<<" "<<node->val;
}
void printTreePreOrder(tree *node){
    if(node == NULL)
        return;
    cout<<" "<<node->val;
    printTreeInOrder(node->left);
   
    printTreeInOrder(node->right);
}
tree* addNode(int val)
{
    tree *node = new tree();
    
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
    
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
    return 0;
}
