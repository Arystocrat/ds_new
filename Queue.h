#ifndef QUEUE_H
#define QUEUE_H
#include "Stack.h"

class Queue {
private:
    Car* arr;
    int front, rear, count, capacity;

public:
    Queue(int cap = 20) {
        capacity = cap;
        arr = new Car[capacity];
        front = 0;
        rear = -1;
        count = 0;
    }

    ~Queue() { delete[] arr; }

    bool isEmpty() { return count == 0; }
    bool isFull() { return count == capacity; }

    void enqueue(Car c) {
        if (isFull()) return;
        rear = (rear + 1) % capacity;
        arr[rear] = c;
        count++;
    }

    Car dequeue() {
        if (isEmpty()) return { -1, "" };
        Car c = arr[front];
        front = (front + 1) % capacity;
        count--;
        return c;
    }
};
#endif