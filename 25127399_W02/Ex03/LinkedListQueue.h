#ifndef LINKEDLISTQUEUE_H
#define LINKEDLISTQUEUE_H

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;


struct Node{
    int val;
    Node* next;
};

class LinkedListQueue{
    private:
        Node* head;
        Node* tail;
        int capacity;
        int num;

    public:
        LinkedListQueue();
        LinkedListQueue(Node* head, Node* tail, int capacity, int num);

        void init(int capacity);

        void enqueue(int x);
        int dequeue();
        int peek();

        bool isEmpty();
        bool isFull();

        void clear();
};

#endif