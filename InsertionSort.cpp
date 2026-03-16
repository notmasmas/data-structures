#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& v){ 
    
    //o & é utilizado para que a função não faça uma cópia do vetor, mas sim modifique o vetor original

    int i = 1;

    while (i < v.size()) { //passa por todos os números do vetor (exceto índice 0)
        int pivot = v[i]; // índice inicial do pivot
        int j = i; // índice onde está o pivot atualmente

        while (j > 0 && v[j-1] > pivot) { // compara o pivot com o número atrás dele (se j = 0 quer dizer que o pivot está no começo do vetor. Não há número atrás dele)
            v[j] = v[j-1]; // envia o número de trás para o endereço atual do pivot
            j--; // desloca o pivot para a esquerda (não realmente. Pivot está guardando em uma variável)
        }
        v[j] = pivot; // quando o pivot for maior que o número de trás ou chegar no começo do vetor, salva ele nessa posição
        i++; // próximo número
    }
}

void printVector (std::vector<int>& v) {
    for (int number:v) {
        std::cout << number << "\n";
    }
}

int main() {
    std::vector<int> v = {10, 5, 4, 2, 9};

    insertionSort(v);
    
    printVector(v);
}