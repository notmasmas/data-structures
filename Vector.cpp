#include <cstdlib>
#include <iostream>

class Vector {

    private:
        std::size_t _size = 0; //espaços utilizados no vetor
        std::size_t capacity; //capacidade total do vetor (utilizados + vazios)
        int* v; //ponteiro. Endereço de memória do primeiro valor guardado no vetor
        void resize_vector();

    public:
        Vector();
        std::size_t size();
        void append(int value);
        void insert(int value, int index);
        void pop();
        void remove(int value);
        int find(int value);
        void print();
        ~Vector();
};

//Vector:: é utilizado para indicar que este método pertence à classe Vector, mesmo sendo implementado fora da definição da classe

Vector::Vector() {
    capacity = 20;
    v = new int[capacity]; //new reserva um espaço na memória para 20 valores inteiros
}

std::size_t Vector::size() {
    return _size;
}

void Vector::append(int value) {
    if (size() == capacity) {
        resize_vector();
    }

    v[_size] = value;
    _size++;
}

void Vector::insert(int value, int index) {
    if (size() == capacity) { //vetor está cheio
        resize_vector();
    }

    for (int i = size() - 1; i >= index; i--) {
        v[i+1] = v[i]; //movendo todos os valores até o index para a direita
    }
    
    v[index] = value;
    _size++; //atualiza o valor de slots utilizados no vetor
}

void Vector::pop() {
    _size--;
}

void Vector::remove(int value) {
    int index = find(value);

    for (int i = index+1; i < size(); i++) {
        v[i-1] = v[i]; //movendo todos os valores até o index para a esquerda
    }

    _size--; //atualiza o valor de slots utilizados no vetor
}

int Vector::find(int value) {
    for(int i = 0; i < size(); i++) {
        if (v[i] == value) {
            return i; //retorna index do valor no vetor
        }
    }
    return -1;
}

void Vector::print() {
    for (int i = 0; i < size(); i++) {
        std::cout << v[i] << ' ';
    }
    std::cout << std::endl;
}

void Vector::resize_vector() {
    capacity = capacity * 2 + 1; //dobra a capacidade do vetor + 1
    int* u = new int[capacity]; //alocando um novo espaço de memória com a nova capacidade

    for (int i = 0; i < size(); i++) { //copiando todos os valores para o novo espaço de memória
        u[i] = v[i];
    }

    delete [] v; //dealoca todos os espaços do setor de memória antigo
    v = u;
}

Vector::~Vector() {
    //destructor de classe deve ser implementado pois estamos lidando com memória alocada dinamicamente
    std::cout << "Vetor destruído\n";
    delete [] v;
}

int main () {
    Vector my_vector;

    my_vector.append(1);
    my_vector.append(2);
    my_vector.append(3);

    my_vector.print();

    my_vector.pop();

    my_vector.print(); 
    
    // :) super legal hehe
}
