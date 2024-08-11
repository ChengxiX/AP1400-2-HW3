#ifndef BST_H
#define BST_H
#include <cstddef>
#include <exception>

class Node
{
public:
    Node(int v, Node* l, Node* r);
    Node(int value);
    Node();
	Node(const Node& node);
    void display();
    int value;
	Node* left;
	Node* right;
};

class BST
{
public:
    BST(Node*& root);
    Node*& get_root();
    void bfs(void (*func)(Node*&));
    size_t length();
    bool add_node(int value);
    Node** find_node(int value);
    Node** find_parrent(int value);
    Node** find_successor(int value);
    bool delete_node(int value);
private:
    Node* root;
};

class AlreadyExist : public std::exception {};

#endif //BST_H