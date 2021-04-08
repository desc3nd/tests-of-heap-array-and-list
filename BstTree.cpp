//
// Created by Marcinek on 31.03.2021.
//

#include "BstTree.h"
#include<iostream>
BstTree::BstTree() {
    root= nullptr;
    root->value=0;
    size=0;
}

void BstTree::push(int value) {
    if(size == 0)
    {
        root = new Node;
        root->value = value;
    }

    Node *curr=new Node;
    Node *ptr= nullptr;
    curr->left= nullptr;
    curr->right= nullptr;
    while(root)
    {
        ptr=root;
        if(root->value < value)
        {
            root=root->left;
        } else
        {
            root=root->right;
        }

    }
    curr->parent=ptr;
    if(curr->value < ptr->value)
        ptr->left=curr;
    else
        ptr->right=curr;
}

void BstTree::displayBst()
{
    std::cout<<"this is your tree pre order: ";
    preOrder(root);
    std::cout<<std::endl;
    std::cout<<"this is your tree in order: ";
    inOrder(root);
    std::cout<<std::endl;
    std::cout<<"this is your tree post order: ";
    postOrder(root);

}
void BstTree::inOrder(Node *node)
{
   if(node)
   {
       inOrder(node->left);
       std::cout<<node->value<<" ";
       inOrder(node->right);
   }


}


void BstTree::preOrder(Node *node)
{
    if(node)
    {
        std::cout<<node->value<<" ";
        preOrder(node->left);
        preOrder(node->right);

    }

}

void BstTree::postOrder(Node *node) {
    if (node)
    {
        postOrder(node->left);
    postOrder(node->right);
    std::cout << node->value << " ";
}
}

BstTree::~BstTree() {
    while(root)
        delete root;

}

