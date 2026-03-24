#include <iostream>
#include <vector>

void bubbleSort(std::vector<int>& v) {

    /* O bubble sort é um algoritmo de ordenação estável em que cada iteração do laço externo leva o maior número não ordenado até sua posição no vetor. Portanto, o vetor ordena-se da direita para a esquerda.
    Ele compara números vizinhos no vetor e os troca de índice quando o número maior encontra-se à esquerda
    do número menor.
    
    Ex: v = {3, 6, 5, 2}
    
    após uma iteração do laço externo:

    v = {3, 5, 2, 6}

    */

    int comparisons = v.size() - 1; 
    /* Número original de comparações que o loop irá fazer. Vai diminuindo conforme o vector
    é ordenado, pois o número mais alto sempre é enviado para o fim do vetor (sobe como uma bolha).
    Portanto, não é necessário comparar o pivô atual com os números no fim do vetor, pois estes já
    estão ordenados */

    for (int i = 0; i < v.size(); i++) {

        for (int j = 0; j < comparisons; j++) {

            std::printf("Comparando com %d números\n", comparisons);

            int pivot = v[j]; // armazenando temporariamente o número que compararemos nesta iteração

            if (pivot > v[j+1]) { // se este número for maior que o próximo no vetor, trocam de lugar
                v[j] = v[j+1];
                v[j+1] = pivot;
            }
        }

        comparisons--; // diminui número de comparações a cada ordenação
    }
}

void printVector (std::vector<int>& v) {
    for (int number:v) {
        std::cout << number << "\n";
    }
}

int main () {

    std::vector<int> v = {37, 54, 12, 23, 34, 60};

    bubbleSort(v);

    printVector(v);
}