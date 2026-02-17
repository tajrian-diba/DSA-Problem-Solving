/*
Stack Implementation Using Linked List
Time Complexity: O(1)
*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    bool isEmpty() {
        return (top == NULL);
    }

    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack Empty\n";
            return -1;
        }
        return top->data;
    }
};

int main() {
    Stack s;
    s.push(5);
    s.push(15);
    cout << "Top: " << s.peek();
}
