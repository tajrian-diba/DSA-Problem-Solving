/*
Problem: Singly Linked List Implementation
Concept: Basic Linked List Operations
Time Complexity:
    Insert at End: O(n)
    Display: O(n)
Space Complexity: O(n)
*/

#include<iostream>
using namespace std;

struct node
{
    int data;
    node* next;

    node(int value)
    {
        data=value;
        next=NULL;
    }
};

node *head=NULL;

void insert_first(int value)
{
    node* newItem =new node(value);
    newItem->next=head;
    head=newItem;
}

void printList()
{
    if(head==NULL)
    {
        cout<<"Linked List is Empty"<<endl;
        return;
    }

    node* current=head;
    while(current!=NULL)
    {
        cout<<current->data<<" ";
        current=current->next;
    }

    cout<<endl;
}

void insert_last(int value)
{
    node* newItem= new node(value);

    if(head==NULL)
    {
        newItem=head;
        return;
    }

    node* current= head;

    while(current->next!=NULL)
    {
        current=current->next;
    }

    current->next=newItem;


}

void insert_middle(int target, int value)
{
    node* newItem = new node(value);

    node* current=head;

    while(current->data!=target)
    {
        current=current->next;
    }

    newItem->next=current->next;
    current->next=newItem;
}

void delete_first()
{
    if(head==NULL)
    {
        cout<<"Linked List is empty"<<endl;
        return;
    }

    node* current=head;
    head=head->next;

    delete current;
}

void delete_last()
{
    if(head==NULL)
    {
        cout<<"Linked List is empty"<<endl;
        return;
    }

    node* current=head;
    node* prev=NULL;

    while(current->next!=NULL)
    {
        prev=current;
        current=current->next;
    }

    if(prev==NULL)
    {
        head=NULL;
    }

    else{
        prev->next=NULL;
    }
    delete current;

}


void delete_any(int target)
{
    if(head==NULL)
    {
        cout<<"Linked List is empty"<<endl;
        return;
    }

    node* current=head;
    node* prev=NULL;

    while(current->data!=target)
    {
        prev=current;
        current=current->next;
    }

    if(prev==NULL)
    {
        head=NULL;
    }

    else{
        prev->next=current->next;
    }
    delete current;

}


int main()
{

    insert_first(10);
    insert_first(20);
    insert_first(30);

    insert_last(40);
    insert_last(50);

    insert_middle(10,60);
    printList();

    delete_first();
    printList();
    delete_last();

    printList();

    delete_any(60);
    printList();

}
