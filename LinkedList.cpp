#include <cstdlib>
#include <iostream>

struct Node {
    int value;
    struct Node* _next;
};

class LinkedList {

    private:
        Node* _head;
        std::size_t _size;

    public:
        LinkedList();
        std::size_t size();
        bool is_empty();
        Node* find(int value);
        void insert(int value, std::size_t pos);
        void append(int value);
        void remove(int value);
        void pop();
        void print();
        ~LinkedList();
};

LinkedList::LinkedList() {
    _head = nullptr;
    _size = 0;
}

std::size_t LinkedList::size() {
    return _size;
}

bool LinkedList::is_empty() {
    return _size == 0;
}

Node* LinkedList::find(int value) {
    auto pivot = _head;

    while (pivot->_next != nullptr && pivot->value != value) {
        pivot = pivot->_next;
    }
    return pivot;
}

void LinkedList::insert(int value, std::size_t pos) {
    Node* new_node = new Node;
    new_node->value = value;
    new_node->_next = nullptr;

    if (is_empty()) {
        _head = new_node;
    }
    else {
        if (pos == 0) {
            new_node->_next = _head;
            _head = new_node;
        }
        else {
            auto pivot = _head;

            for (std::size_t i = 1; i < pos-1; i++) {
                pivot = pivot->_next;
            }
            new_node = pivot->_next;
            pivot->_next = new_node;
        }
    }

    _size++;
}

void LinkedList::append(int value) {
    Node* new_node = new Node;
    new_node->value = value;
    new_node->_next = nullptr;

    if (is_empty()) {
        _head = new_node;
    } 
    else {
        Node* pivot = _head;

        for (std::size_t i = 1; i < size(); i++) {
            pivot = pivot->_next;
        }
        pivot->_next = new_node;
    }
    _size++;
}

void LinkedList::remove(int value) {
    if (is_empty()) {
        return;
    }

    Node* to_delete = nullptr;
    auto pivot = _head;

    if (_head->value == value) {
        to_delete = _head;
        _head = _head->_next;
        delete to_delete;
        _size--;
    }
    else {
        while (pivot->_next != nullptr && pivot->_next->value != value) {
            pivot = pivot->_next;
        }
        to_delete = pivot->_next;

        if (to_delete != nullptr) {
            pivot->_next = to_delete->_next;
            delete to_delete;
            _size--;
        }
    }
}

void LinkedList::pop() {
    Node* to_delete;

    if (is_empty()) {
        return;
    } 

    if (size() == 1) {
        to_delete = _head;
        _head = nullptr;
    }
    else {
        Node* pivot = _head;
        for (std::size_t i = 1; i < size()- 1; i++) {
            pivot = pivot->_next;
        }
        to_delete = pivot->_next;
        pivot->_next = nullptr;
    }

    delete to_delete;
    _size--;
}

void LinkedList::print() {
    if (is_empty()) {
        std::cout << "List is Empty" << std::endl;
    }

    else {
        Node* pivot = _head;
        for (std::size_t i = 0; i < size(); i++) {
            int value = pivot->value;
            std::cout << value << ' ';
            pivot = pivot->_next;
        }
        std::cout << std::endl;
    }
}

LinkedList::~LinkedList() {

    Node* to_delete = _head;

    while (to_delete->_next != nullptr) {
        auto aux = to_delete->_next;
        delete to_delete;
        to_delete = aux;
    }
    delete to_delete;
}

int main() {
    LinkedList myList;

    myList.append(1);
    myList.append(2);
    myList.append(3);

    myList.print();

    myList.pop();

    myList.print();

    myList.pop();

    myList.print();
}