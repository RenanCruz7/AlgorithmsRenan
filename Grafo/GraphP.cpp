#include <iostream>
#include <list>
#include <utility>

class GrafoPonderado {
private:
    int V; // Número de vértices
    std::list<std::pair<int, int>> *adj; // Lista de adjacência com pares (vértice destino, peso)

public:
    GrafoPonderado(int V) {
        this->V = V;
        adj = new std::list<std::pair<int, int>>[V];
    }

    void adicionarAresta(int v1, int v2, int peso) {
        adj[v1].push_back(std::make_pair(v2, peso));
        adj[v2].push_back(std::make_pair(v1, peso)); // Para um grafo não direcionado
    }

    void imprimirGrafo() {
        for (int i = 0; i < V; ++i) {
            std::cout << "Vertice " << i << " conectado a:";
            for (const auto &pair : adj[i]) {
                int v = pair.first;
                int peso = pair.second;
                std::cout << " (" << v << " Peso: " << peso << ")";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    GrafoPonderado grafo(5); // Criar um grafo com 5 vértices

    grafo.adicionarAresta(0, 1, 2);
    grafo.adicionarAresta(0, 2, 4);
    grafo.adicionarAresta(1, 3, 1);
    grafo.adicionarAresta(2, 4, 3);

    grafo.imprimirGrafo();

    return 0;
}
