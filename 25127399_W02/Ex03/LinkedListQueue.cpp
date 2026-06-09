#include "LinkedListQueue.h"

using namespace std;

LinkedListQueue :: LinkedListQueue(){
    head = nullptr;
    tail = nullptr;
    capacity = 0;
    num = 0;
}

LinkedListQueue :: LinkedListQueue(Node* head, Node* tail, int capacity, int num){
    this->head = head;
    this->tail = tail;
    this->capacity = capacity;
    this->num = num;
}

void LinkedListQueue :: init(int capacity){
    this->capacity = capacity;
}

void LinkedListQueue :: enqueue(int x){
    if(isFull()) return;

    Node* tmp = new Node();
    tmp->val = x;
    tmp->next = nullptr;

    if(isEmpty()){
        head = tmp;
        tail = tmp;
    }
    else{
        tail->next = tmp;
        tail = tmp;
    }
    ++num;
}


int LinkedListQueue :: dequeue(){
    if(isEmpty()) return -1;

    int ans = head->val;
    Node* tmp = head;
    head = head->next;
    delete tmp;
    --num;

    if(head == nullptr){
        tail = nullptr;
    }
    return ans;
}


int LinkedListQueue :: peek(){
    if(isEmpty()) return -1;
    return head->val;    
}

bool LinkedListQueue :: isEmpty(){
    if(head == nullptr) return true;
    return false;
}


bool LinkedListQueue :: isFull(){
    if(num == capacity) return true;
    return false;
}

void LinkedListQueue :: clear(){
    while(!isEmpty()){
            dequeue();
        }
}
