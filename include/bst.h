#ifndef BST_H
#define BST_H
#include <cstddef>
#include <functional>
// #include <exception>

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
    void bfs(std::function<void (Node*&)>);
    void display();
    size_t length();
    bool add_node(int value);
    Node** find_node(int value);
    Node** find_parent(int value);
    Node** find_successor(int value);
    bool delete_node(int value);
    ~BST();
private:
    Node* root;
};

#endif //BST_H