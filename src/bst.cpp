#include "bst.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <functional>


Node::Node(int v, Node* l, Node* r)
{
    value = v;
    left = l;
    right = r;
}
Node::Node(int v)
{
    value = v;
    left = nullptr;
    right = nullptr;
}

void Node::display()
{
    std::cout << std::setiosflags(std::ios::left) << std::setw(20) << this << "=> value:" << std::setw(12) << value << "left:" << std::setw(20) << left << "right:" << std::setw(20) << right <<std::endl;
}


BST::BST(Node*& r)
{
    root = r;
}

Node*& BST::get_root()
{
    return root;
}

void BST::bfs(std::function<void (Node*&)> func)
{
    std::queue<Node*> q;
    q.push(root);
    Node* current;
    while(q.size()>0){
        current = q.front();
        q.pop();
        func(current);
        if (current->left != nullptr)
        {
            q.push(current->left);
        }
        if (current->right != nullptr)
        {
            q.push(current->right);
        }
    }
}

void BST::display()
{
    bfs([](Node*& x){x->display();});
}

size_t BST::length()
{
    size_t len = 0;
    bfs([&len](Node*& node){len++;});
    return len;
}

BST::~BST()
{
	std::vector<Node*> nodes;
	bfs([&nodes](Node*& node){nodes.push_back(node);});
	for(auto& node: nodes)
		delete node;
}

bool BST::add_node(int value)
{
    Node* current = root;
    while (true)
    {
        if (current->value==value)
        {
            return false;
        }
        if (current->value>value)
        {
            if (current->left==nullptr)
            {
                current->left = new Node(value);
                return true;
            }
            current = current->left;
        }
        else
        {
            if (current->right==nullptr)
            {
                current->right = new Node(value);
                return true;
            }
            current = current->right;
        }
    }
}

Node** BST::find_node(int value)
{
    Node* current = root;
    if (current->value==value)
    {
        return &root;
    }
    while (true)
    {
        if (current->value>value)
        {
            if (current->left==nullptr)
            {
                return nullptr;
            }
            if (current->left->value == value)
            {
                return &current->left;
            }
            current = current->left;
        }
        else
        {
            if (current->right==nullptr)
            {
                return nullptr;
            }
            if (current->right->value == value)
            {
                return &current->right;
            }
            current = current->right;
        }
    }
}

Node** BST::find_parent(int value)
{
    Node** self = &root;
    Node* current = root;
    if (current->value==value)
    {
        return nullptr;
    }
    while (true)
    {
        if (current->value>value)
        {
            if (current->left==nullptr)
            {
                return nullptr;
            }
            if (current->left->value == value)
            {
                return self;
            }
            self = &current->left;
            current = current->left;
        }
        else
        {
            if (current->right==nullptr)
            {
                return nullptr;
            }
            if (current->right->value == value)
            {
                return self;
            }
            self = &current->right;
            current = current->right;
        }
    }
}

bool BST::delete_tree(int value)
{
    Node** p = find_parent(value);
    if (p==nullptr)
    {
        return false;
    }
    Node* a;
    if ((*p)->left!=nullptr&&(*p)->left->value==value)
    {
        a = (*p)->left;
        (*p)->left = nullptr;
    }
    else
    {
        a = (*p)->right;
        (*p)->right = nullptr;
    }
    BST tmp(a);
    // 会自动回收tmp，此时就把这棵树上的回收了
    return true;
}


int main()
{
    Node* r = new Node(10);
    BST btree(r);
    btree.add_node(3);
    btree.add_node(6);
    btree.add_node(14);
    btree.add_node(8);
    btree.add_node(7);
    std::cout << btree.length() <<std::endl;
    //std::cout << *btree.find_parent(7) <<std::endl;
    //std::cout << *btree.find_node(8) <<std::endl;
    btree.delete_tree(3);
    btree.display();
}