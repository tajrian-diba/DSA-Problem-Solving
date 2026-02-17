/*
Problem: Detect Cycle in Linked List
Algorithm: Floyd’s Cycle Detection (Tortoise & Hare)
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

bool hasCycle(Node* head) {
    if (head == NULL)
        return false;

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          // move 1 step
        fast = fast->next->next;    // move 2 steps

        if (slow == fast)
            return true;            // cycle detected
    }

    return false;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    // Creating a cycle manually
    head->next->next->next->next = head->next;

    if (hasCycle(head))
        cout << "Cycle Detected";
    else
        cout << "No Cycle";

    return 0;
}
