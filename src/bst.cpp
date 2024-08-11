#include "bst.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>


Node::Node(int value, Node* left, Node* right)
{
    value = value;
    left = left;
    right = right;
}
Node::Node(int value)
{
    value = value;
}

void Node::display()
{
    std::cout << std::setiosflags(std::ios::left) << std::setw(20) << this << "=> value:" << std::setw(12) << value << "left:" << std::setw(20) << left << "right:" << std::setw(20) << right <<std::endl;
}


BST::BST(Node*& root)
{
    root = root;
}

Node*& BST::get_root()
{
    return root;
}

void BST::bfs(void (*func)(Node*&))
{
    std::queue<Node*> q;
    q.push(root);
    Node* current;
    while(q.size()>0){
        current = q.front();
        q.pop();
        func(current);
        if (current->left != NULL)
        {
            q.push(current->left);
        }
        if (current->right != NULL)
        {
            q.push(current->right);
        }
    }
}

size_t BST::length()
{
    size_t len = 0;
    std::queue<Node*> q;
    q.push(root);
    Node* current;
    while(q.size()>0){
        current = q.front();
        q.pop();
        len++;
        if (current->left != NULL)
        {
            q.push(current->left);
        }
        if (current->right != NULL)
        {
            q.push(current->right);
        }
    }
    return len;
}

bool BST::add_node(int value)
{
    Node* current = root;
    while (true)
    {
        if (current->value==value)
        {
            AlreadyExist e;
            throw e;
        }
        
    }
    
}

int main()
{
    Node a1(1);
    Node* n1 = &a1;
    BST btree(n1);
    std::cout << btree.length();
    btree.bfs([](Node*& x){x->display();});
}