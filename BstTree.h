//
// Created by Marcinek on 31.03.2021.
//

#ifndef NOWY_BSTTREE_H
#define NOWY_BSTTREE_H
struct Node
{
    Node *left,*parent, *right;
    int value;
};

class BstTree {
public:
    explicit BstTree();
    void push(int value);
    int size;
    ~BstTree();
    void displayBst();


private:
    Node *root;
    static void inOrder(Node *node);
    static void preOrder(Node *node);
    static void postOrder(Node *node);



};


#endif //NOWY_BSTTREE_H
