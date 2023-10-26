#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct Node {

    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};


void dfs(Node* root){
    if (root == nullptr) {
        return;
    }
    // Processa o nó atual (imprime o valor)
    std::cout << root->data << " ";
    // Recursivamente chama a DFS nos filhos do nó
    dfs(root->left);
    dfs(root->right);
}



int main(){
    
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    dfs(root);
    cout << endl;

    return 0;
}