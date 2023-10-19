#include <iostream>
#include <list>
#include <cstring>
using namespace std;
/**
 * Um array que ira armazenar uma lista que ira armazenar os pares
 *
 *
 */

class hashTable
{
private:
    static const int gruposHash = 10;
    list<pair<string, double>> array[gruposHash];

public:
    bool Vazio() const;
    int funcaoHash(string chave);
    void insercao(string chave, float valor);
    void remover(string chave);
    void imprimir();
};

bool hashTable::Vazio() const
{
    int soma{}; // inicia a variavel soma como 0
    // itero sobre o array e verificado cada um dos grupos de hash e somo o tamanho deles a variavel soma
    for (int i{}; i < gruposHash; i++)
    {
        soma += array[i].size();
    }
    // If para verificar se está vazio ou nao
    if (!soma)
    {
        cout << "Esta Vazio" << endl;
        return true;
    }
    cout << "Tem algo Dentro" << endl;
    return false;
}

int hashTable::funcaoHash(string chave) {
    int valor = 0;
    for (char c : chave) {
        valor = (abs(valor * 31 + c)) % gruposHash;
    }
    return valor;
}


void hashTable::insercao(string chave, float valor)
{
    // funcao hash devolve o lugar onde a chave e o valor deve ser inserido
    int valorHasheado = funcaoHash(chave);
    // acessa no indice correspondente ao valor hash calculado
    auto& celula = array[valorHasheado];
    // Função começa a iterar sobre os elementos da célula
    auto celulaIterador = begin(celula);
    bool chaveExiste = false;
    for (; celulaIterador != end(celula); celulaIterador++)
    {
        if (celulaIterador->first == chave)
        {
            chaveExiste = true;
            celulaIterador->second = valor;
            cout << "[CUIDADO] A CHAVE JA EXISTE. VALOR SERÁ ATUALIZADO" << endl;
            break;
        }
    }
    if (!chaveExiste)
    {
        celula.emplace_back(chave, valor);
    }
    return;
}

void hashTable::remover(string chave)
{
    // funcao hash devolve o lugar onde a chave e o valor deve ser inserido
    int valorHasheado = funcaoHash(chave);
    // acessa no indice correspondente ao valor hash calculado
    auto celula = array[valorHasheado];
    // Função começa a iterar sobre os elementos da célula
    auto celulaIterador = begin(celula);
    bool chaveExiste = false;
    for (; celulaIterador != end(celula); celulaIterador++)
    {
        if (celulaIterador->first == chave)
        {
            chaveExiste = true;
            celulaIterador = celula.erase(celulaIterador);
            cout << "REMOCAO CONCLUIDA" << endl;
            break;
        }
    }
    if (!chaveExiste)
    {
        cout << "[CUIDADO] CHAVE NAO ENCONTRADA. PORTANTO PAR NAO FOI REMOVIDO" << endl;
    }
    return;
}

void hashTable::imprimir()
{
    for (int i{}; i < gruposHash; i++)
    {
        if (array[i].size() == 0) continue;

        auto iterador = array[i].begin();
        for (; iterador != array[i].end(); iterador++)
        {   

            cout << "Chave: " << iterador->first << " Valor: " << iterador->second << endl;
        }
    }
    return;
}

int main()
{
    hashTable HT;

    HT.Vazio();

    HT.insercao("Banana",float(3.80));
    HT.insercao("Maca",float(0.70));
    HT.insercao("Pera",float(4.50));
    HT.insercao("Leite",float(5));
    HT.insercao("Ovos",float(15));
    HT.insercao("Melancia",float(7));
    HT.insercao("Cerveja",float(2.50));

    HT.imprimir();

    cout<< " --------------------------------------" << endl;
    cout << "Posicao de Banana no hash: " << HT.funcaoHash("Banana") << endl;
    cout << "Posicao de Maca no hash: " << HT.funcaoHash("Maca") << endl;
    cout << "Posicao de Pera no hash: " << HT.funcaoHash("Pera") << endl;
    cout << "Posicao de Leite no hash: " << HT.funcaoHash("Leite") << endl;
    cout << "Posicao de Ovos no hash: " << HT.funcaoHash("Ovos") << endl;
    cout << "Posicao de Melancia no hash: " << HT.funcaoHash("Melancia") << endl;
    cout << "Posicao de Cerveja no hash: " << HT.funcaoHash("Cerveja") << endl;

    return 0;
}

