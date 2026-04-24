#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
    int x;
    int y;
    Node* _next;
};

class CircularLinkedList {
    private:
        Node* _tail;
        size_t _size;
    
    public:
        CircularLinkedList();
        size_t size();
        Node* head();
        bool is_empty();
        bool is_singular();
        Node* find(int x, int y);
        void insert(int x, int y);
        void remove(int x, int y);
        void swap(Node* node); // swaps node->_next with node->_next->_next
        void print();
        void clear();
        ~CircularLinkedList();
};

using namespace std;

CircularLinkedList::CircularLinkedList() {
    _tail = nullptr;
    _size = 0;
}

size_t CircularLinkedList::size() {
    return _size;
}

Node* CircularLinkedList::head() {
    if (_tail == nullptr) { return nullptr; }
    return _tail->_next;
}

bool CircularLinkedList::is_empty() {
    return size() == 0;
}

bool CircularLinkedList::is_singular() {
    return _tail != nullptr && _tail->_next == _tail;
}

Node* CircularLinkedList::find(int x, int y) {
    if (is_empty()) {
        return nullptr;
    }

    Node* pivot = _tail->_next; // head

    while (pivot != _tail && (pivot->x != x && pivot->y != y)) {
        pivot = pivot->_next;
    }

    if (pivot->x == x && pivot->y == y) {
        return pivot; 
    } else {
        return nullptr;
    }
}

void CircularLinkedList::insert(int x, int y) {
    Node* new_node = new Node;
    new_node->x = x;
    new_node->y = y;

    if (is_empty()) {
        _tail = new_node;
        new_node->_next = new_node;
    } else {
        new_node->_next = _tail->_next;
        _tail->_next = new_node;
        _tail = new_node;
    }

    _size++;
} 

void CircularLinkedList::remove(int x, int y) {
    if (is_empty()) {
        return;
    }

    Node* to_delete = nullptr;
    Node* pivot = _tail;

    while (pivot->_next != _tail && (pivot->_next->x != x && pivot->_next->y != y)) { //começa checando head
        pivot = pivot->_next;
    }

    if (pivot->_next->x == x && pivot->_next->y == y) {
        to_delete = pivot->_next;
        pivot->_next = pivot->_next->_next;

        if (is_singular()) {
            _tail = nullptr;
        } else if (to_delete == _tail) {
            _tail = pivot;
        }

        delete to_delete;
        _size--;
    }
}

void CircularLinkedList::swap(Node* node) {
    Node* A = node;
    Node* B = A->_next;
    Node* C = B->_next;

    A->_next = C;
    B->_next = C->_next;
    C->_next = B;

    if (B == _tail) {
        _tail = C;
    } else if (C == _tail) {
        _tail = B;
    }
    
}

void CircularLinkedList::print() {

    if (is_empty()) { return; }

    Node* pivot = _tail->_next; //head

    do {
    cout << "(" << pivot->x << ", " << pivot->y << ") ";
        pivot = pivot->_next;
    } while (pivot != _tail->_next);

    cout << endl;
}

void CircularLinkedList::clear() {
    if (_tail == nullptr) { return; }

    Node* to_delete = _tail->_next; //head

    while (to_delete != _tail) {
        auto aux = to_delete->_next;
        delete to_delete;
        to_delete = aux;
    }

    delete to_delete;
    
    _tail = nullptr;
    _size = 0;
}

CircularLinkedList::~CircularLinkedList() {
    if (_tail == nullptr) { return; }

    Node* to_delete = _tail->_next; //head

    while (to_delete != _tail) {
        auto aux = to_delete->_next;
        delete to_delete;
        to_delete = aux; 
    }

    delete to_delete;
    
    _tail = nullptr;
    _size = 0;
}