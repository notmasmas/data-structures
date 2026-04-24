#include "CircularLinkedList.h"
#include <iostream>
#include <cstdlib>
#include <cmath>

// this implementation is not fully optimized and fails 2 out of 10 test cases on VPL :P


double calc_distance (Node* first_node, Node* second_node) {

    double first_node_x = first_node->x;
    double first_node_y = first_node->y;
    double second_node_x = second_node->x;
    double second_node_y = second_node->y;

    double distance = std::sqrt(std::pow(first_node_x - second_node_x, 2) +  std::pow(first_node_y - second_node_y, 2));

    return distance;

}

double return_sum (CircularLinkedList& list) {
    
    Node* pivot = list.head();
    double sum = 0;

    do {
        sum += calc_distance(pivot, pivot->_next);
        pivot = pivot->_next;
    } while (pivot != list.head());

    return sum;

}

int main() {

    int x, y;
    CircularLinkedList list;

    while(true) {

        cin >> x >> y;

        if (x == -1 && y == -1) {
            break;
        }

        list.insert(x, y);
    }

    double first_sum = return_sum(list);

    bool optimized = false;

    while (!optimized) {
        bool did_swap = false;
        Node* pivot = list.head();
        
        do {

            Node* A = pivot;
            Node* B = pivot->_next;
            Node* C = B->_next;
            Node* D = C->_next;

            double old_seq = calc_distance(A, B) + calc_distance(C, D);
            double new_seq = calc_distance(A, C) + calc_distance(B, D);

            if (new_seq < old_seq) {
                list.swap(pivot);
                did_swap = true;
            } else {
                pivot = pivot->_next;
            }

        } while (pivot != list.head());

        if (!did_swap) {
            optimized = true;
        }
    }

    double second_sum = return_sum(list);

    std::printf("%.2f\n", first_sum);
    std::printf("%.2f\n", second_sum);
}