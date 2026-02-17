/*
Problem: Doubly Linked List Implementation
Concept: Forward and Backward Traversal
Time Complexity:
    Insert at End: O(n)
Space Complexity: O(n)
*/
#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
    node* prev;
    node(int value){
        data = value;
        next = NULL;
        prev = NULL;
    }
};

node* head = NULL;

// Insert at beginning
void insert_first(int value){
    node* newItem = new node(value);
    if(head == NULL){
        head = newItem;
        return;
    }
    newItem->next = head;
    head->prev = newItem;
    head = newItem;
}

// Insert at end
void insert_last(int value){
    node* newItem = new node(value);
    if(head == NULL){
        head = newItem;
        return;
    }
    node* current = head;
    while(current->next != NULL){
        current = current->next;
    }
    current->next = newItem;
    newItem->prev = current;
}

// Insert after key
void insert_middle(int key, int value){
    node* current = head;
    while(current != NULL && current->data != key){
        current = current->next;
    }
    if(current == NULL){
        cout << "Key not found\n";
        return;
    }
    node* newItem = new node(value);
    newItem->next = current->next;
    newItem->prev = current;
    if(current->next != NULL)
        current->next->prev = newItem;
    current->next = newItem;
}

// Delete first
void delete_first(){
    if(head == NULL){
        cout << "List empty\n";
        return;
    }
    if(head->next == NULL){
        delete head;
        head = NULL;
        return;
    }
    node* temp = head;
    head = head->next;
    head->prev = NULL;
    delete temp;
}

// Delete last
void delete_last(){
    if(head == NULL){
        cout << "List empty\n";
        return;
    }
    if(head->next == NULL){
        delete head;
        head = NULL;
        return;
    }
    node* current = head;
    while(current->next != NULL){
        current = current->next;
    }
    current->prev->next = NULL;
    delete current;
}

// Delete by key
void delete_any(int key){
    node* current = head;
    while(current != NULL && current->data != key){
        current = current->next;
    }
    if(current == NULL){
        cout << "Key not found\n";
        return;
    }
    if(current == head){
        delete_first();
        return;
    }
    if(current->next != NULL)
        current->next->prev = current->prev;
    current->prev->next = current->next;
    delete current;
}

// Print list
void print_list(){
    node* current = head;
    cout << "List: ";
    while(current != NULL){
        cout << current->data << " <-> ";
        current = current->next;
    }
    cout << "NULL\n";
}

void menu(){
    cout << "1.Insert First\n";
    cout << "2.Insert Last\n";
    cout << "3.Insert Middle\n";
    cout << "4.Delete First\n";
    cout << "5.Delete Last\n";
    cout << "6.Delete Any\n";
    cout << "7.Print List\n";
    cout << "0.Exit\n";
}

int main(){
    int choice = -1, value, key;
    menu();

    while(choice != 0){
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice){
            case 1: cin >> value; insert_first(value); break;
            case 2: cin >> value; insert_last(value); break;
            case 3: cin >> key >> value; insert_middle(key, value); break;
            case 4: delete_first(); break;
            case 5: delete_last(); break;
            case 6: cin >> key; delete_any(key); break;
            case 7: print_list(); break;
        }
    }
    return 0;
}
