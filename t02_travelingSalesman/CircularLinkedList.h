#include <iostream>
#include <cstdlib>
#pragma once

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