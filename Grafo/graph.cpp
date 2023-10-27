#include <iostream>
#include <list>

class Grafo {
private:
    int V; // Número de vértices
    std::list<int> *adj; // Lista de adjacência

public:
    Grafo(int V) {
        this->V = V;
        adj = new std::list<int>[V];
    }

    void adicionarAresta(int v1, int v2) {
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }

    void imprimirGrafo() {
        for (int i = 0; i < V; ++i) {
            std::cout << "Vértice " << i << " conectado a:";
            for (const auto &v : adj[i]) {
                std::cout << " " << v;
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Grafo grafo(5); // Criar um grafo com 5 vértices

    grafo.adicionarAresta(0, 1);
    grafo.adicionarAresta(0, 2);
    grafo.adicionarAresta(1, 3);
    grafo.adicionarAresta(2, 4);

    grafo.imprimirGrafo();

    return 0;
}