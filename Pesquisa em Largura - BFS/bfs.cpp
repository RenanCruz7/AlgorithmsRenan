#include <iostream>
#include <queue>

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


void bfs(Node* root){
    queue<Node*> fila;

    queue<Node*> filaVisitado;

    fila.push(root);

    filaVisitado.push(root);

    while(!fila.empty()){
        Node* atual = fila.front();

        fila.pop();

        cout << atual->data << endl;

        if(atual->left != NULL){
            fila.push(atual->left);
        }

        if(atual->right != NULL){
            fila.push(atual->right);
        }
        
        filaVisitado.push(atual);
    }
}



int main(){
    
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    bfs(root);
    cout << endl;

    return 0;
}