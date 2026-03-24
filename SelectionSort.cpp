#include <vector>
#include <iostream>

void selectionSort(std::vector<int>& v) {

    /* O Selection Sort é um algoritmo de ordenação instável que percorre o vetor procurando pelo
    menor número não ordenado. Ele guarda este número e seu índice. Após terminar de percorrer o vetor,
    salva o valor do menor número no menor índice não ordenado, e o valor que se encontrava neste índice
    é salvo no antigo índice do menor número.
    
    Ex: v = {10, 5, 4, 2, 9}
    
    Após uma iteração:
    
    v = {2, 5, 4, 10, 9} 

    O loop só irá comparar o número com valores ainda não ordenados, evitando repetições. Assim, o vetor é
    ordenado da esquerda para a direita.

    */

    for (int i = 0; i < v.size(); i++) {
        
        int smallest = v[i];
        int smallest_index = i;

        for (int j = i+1; j < v.size(); j++) {

            if (v[j] < smallest) {

                smallest = v[j];
                smallest_index = j;
            }
        }

        v[smallest_index] = v[i];
        v[i] = smallest;
    }
}

void printVector (std::vector<int>& v) {
    for (int number:v) {
        std::cout << number << "\n";
    }
}

int main() {
    std::vector<int> v = {10, 5, 4, 2, 9};

    selectionSort(v);

    printVector(v);
}