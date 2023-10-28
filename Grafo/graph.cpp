#include <iostream>
#include <list>

struct Graph
{
    int V;
    std::list<int> *adj;

    Graph(int V) {
        this->V = V;
        adj = new std::list<int>[V];
    }
};

class Grafo {
    Graph *g;
public:
    Grafo(int V) {
        g = new Graph(V);
    }

    void adicionarAresta(int v1, int v2) {
        g->adj[v1].push_back(v2);
        g->adj[v2].push_back(v1);
    }

    void imprimirGrafo() {
        for (int i = 0; i < g->V; ++i) {
            std::cout << "Vertice " << i << " conectado a:";
            for (const auto &v : g->adj[i]) {
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
