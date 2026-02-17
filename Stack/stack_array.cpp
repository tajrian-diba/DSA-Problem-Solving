/*
Stack Implementation Using Array
Operations: Push, Pop, Peek, isEmpty, isFull
Time Complexity: O(1)
*/

#include <iostream>
#define SIZE 5
using namespace std;

class Stack {
    int arr[SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == SIZE - 1);
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = value;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }
        top--;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack Empty\n";
            return -1;
        }
        return arr[top];
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    cout << "Top: " << s.peek();
}
