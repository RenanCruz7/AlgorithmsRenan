#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *right;
    Node *left;

    Node(int val)
    {
        this->val = val;
        right = nullptr;
        left = nullptr;
    }
};

class SearchBinaryTree
{
    Node *root;

public:
    SearchBinaryTree()
    {
        root = nullptr;
    }
    void insert(int val)
    {
        root = insertRecursive(root, val);
    }

    bool search(int val)
    {
        return searchRecursive(root, val);
    }

private:
    Node *insertRecursive(Node *current, int val)
    {
        if (current == nullptr)
        {
            return new Node(val);
        }
        if (val < current->val)
        {
            current->left = insertRecursive(current->left, val);
        }
        else if (val > current->val)
        {
            current->right = insertRecursive(current->right, val);
        }
        return current;
    }

    bool searchRecursive(Node *node, int val)
    {
        if (node == nullptr)
        {
            return false;
        }

        if (val == node->val)
        {
            return true;
        }
        else if (val < node->val)
        {
            return searchRecursive(node->left, val);
        }
        else
        {
            return searchRecursive(node->right, val);
        }
    }
};

int main(){

    SearchBinaryTree tree;

    tree.insert(5);
    tree.insert(1);
    tree.insert(9);
    tree.insert(65);
    tree.insert(-2);
    tree.insert(452);
    tree.insert(-4);
    tree.insert(0);
    tree.insert(5);

    cout << tree.search(8) << endl;
    cout << tree.search(99) << endl;

    return 0;
}
