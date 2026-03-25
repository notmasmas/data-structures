//Problema da Mochila - Heurística Gulosa
//Knapsack Problem

#include <iostream>
#include <vector>

using namespace std;

class Item {

    public:
    
    int tipo;
    int utilidade;
    int peso;
    float utilidadePeso;
    int numItens;
    int itensUtilizados;

    Item (int tipo, int utilidade, int peso, int numItens) {
        this->tipo = tipo; //id do tipo de item
        this->utilidade = utilidade;
        this->peso = peso;
        this->utilidadePeso = float(utilidade)/float(peso); //para não obter o resultado truncado
        this->numItens = numItens; //número total de itens daquele tipo disponíveis
        this->itensUtilizados = 0; //número de itens daquele tipo que foram inseridos na mochila
    }
};

void insertionSort(vector<Item>& v) { //ordena itens por utilidade/peso de forma decrescente

    for (int i = 1; i < v.size(); i++) {
        int j = i;
        Item pivot = v[j];

        while (j > 0 && v[j-1].utilidadePeso < pivot.utilidadePeso) {
            v[j] = v[j-1];
            j--;
        }

        v[j] = pivot;
    }
}

//insere itens na mochila seguindo os critérios do problema
vector<Item> inserirItens(vector<Item>& v, int capacidadeMochila) {
    vector<Item> espaco; //bolso da mochila. Onde são guardados os itens

    for (int i = 0; i < v.size(); i++) {

        //enquanto ainda há espaço na mochila e ainda há itens daquele tipo disponíveis
        while (capacidadeMochila >= v[i].peso && v[i].itensUtilizados < v[i].numItens) {
            v[i].itensUtilizados++;
            capacidadeMochila -= v[i].peso;
        }

        //se algum item foi utilizado
        if (v[i].itensUtilizados != 0) {
            espaco.push_back(v[i]);
        }    
    }

    return espaco;
}

int main() {

    vector<Item> vectorItens;
    int utilidade, peso, numItens, capacidadeMochila;
    int counter = 0; //índice do item

    while(true) {

        cin >> utilidade >> peso >> numItens;

        if (utilidade == -1 && peso == -1 && numItens == -1) {
            break;
        }

        Item item = Item(counter, utilidade, peso, numItens); //instancia tipo de item
        vectorItens.push_back(item);

        counter++;
    }

    cin >> capacidadeMochila;

    insertionSort(vectorItens);

    vector<Item> espaco = inserirItens(vectorItens, capacidadeMochila);

    for (int i = 0; i < espaco.size(); i++) {
        cout << espaco[i].tipo << ' ' << espaco[i].itensUtilizados << endl;
    }
}