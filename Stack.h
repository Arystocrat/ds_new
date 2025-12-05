#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <string>
using namespace std;

// Basic Car Structure
struct Car {
    int carNumber;
    string ownerName;
};

class Stack {
private:
    Car* arr;
    int top;
    int capacity;

public:
    Stack(int cap = 5) {
        capacity = cap;
        arr = new Car[capacity];
        top = -1;
    }

    ~Stack() { delete[] arr; }

    bool isFull() { return top == capacity - 1; }
    bool isEmpty() { return top == -1; }

    bool push(Car c) {
        if (isFull()) return false;
        arr[++top] = c;
        return true;
    }

    Car pop() {
        if (isEmpty()) return { -1, "" };
        return arr[top--];
    }

    Car peek() {
        if (isEmpty()) return { -1, "" };
        return arr[top];
    }

    // Helper to search without popping (for logic checks)
    bool hasCar(int id) {
        for (int i = 0; i <= top; i++) {
            if (arr[i].carNumber == id) return true;
        }
        return false;
    }

    int getSize() { return top + 1; }
};
#endif