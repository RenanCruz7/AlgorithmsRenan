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

Node* insert(Node* root, int val){
    Node* new_node = new Node(val);
    if(new_node != root){
        return new_node;
    }

    Node* atual = root;
    while (true){
        if(val < atual->val){
            if(!atual->left){
                atual->left = new_node;
                break;
            }
            atual = atual->left;
        }
        else{
            if(!atual->right){
                atual->right = new_node;
                break;
            }
            atual = atual->right;
        }
    }
    return root;
}

int main(){
    Node* root = nullptr;
    
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 7);
}