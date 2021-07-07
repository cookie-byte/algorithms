/*
Program to implement linked list.
*/
#include <iostream>
using namespace std;

//Define a structure for node.
struct Node {
    int data;
    Node* next;
};

Node* head = NULL; // empty list

//Functions to operate on the list.
void Insert(int value) {
    ///Function to inset a node at the beginning of the list.
    Node* temp = new Node;
    temp->data = value;
    temp->next = head;
    head = temp;
}

void Insert(int value, int pos) {
    ///Inserts a node at the n th position (1 based indexing).
    Node* new_node = new Node;
    new_node->data = value;

    if (pos == 1) {
        new_node->next = head;
        head = new_node;
        return;
    }

    Node* temp = head;
    for (int i = 0; i < pos-2 && temp != NULL; i++) {
        temp = temp->next;
        //cout<<"Currently at node "<<i<<endl;
    }
    if (temp != NULL) {
        new_node->next = temp->next;
        temp->next = new_node;
    }
    else {
        cout<<"Position out of bounds."<<endl;
    }
}

void Append(int value) {
    ///Function to insert the node at the end of the list.
    Node* new_node = new Node;
    new_node->data = value;

    if (head == NULL) {
        new_node->next = head;
        head = new_node;
        return;
    }
    // Go to the end of the list.
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    new_node->next = NULL;
    temp->next = new_node;
}

void Delete(int pos) {
    ///Function to delete the node at n th position (1 based indexing).
    Node* temp, *prev_node = head;

    if (pos == 1) {
        temp = head;
        head = head->next;
        delete temp;
        return;
    }

    for (int i = 0; i < pos-2 && prev_node != NULL; i++) {
        prev_node = prev_node->next;
    }

    if (prev_node == NULL || prev_node->next == NULL || pos <= 0) {
        cout<<"Entered index out of bounds."<<endl;
        return;
    }
    temp = prev_node->next;
    prev_node->next = temp->next;
    delete temp;
}

void Print() {
    ///Function to traverse the list & print it.
    Node* temp = head;
    cout<<"List is: ";
    while (temp != NULL) {
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void Print_recursive(Node* current) {
    cout<<current->data<<" -> ";
    if (current->next != NULL)
        Print_recursive(current->next);
}

void Print_recursive_reverse(Node* current) {
    if (current->next != NULL)
        Print_recursive_reverse(current->next);
    cout<<current->data<<" -> ";
}

void Reverse() {
    Node *current, *prev, *next;
    current = head;
    prev = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void Reverse_recursive(Node *current){
    if (current->next == NULL) {
        head = current;
        return;
    }
    Reverse_recursive(current->next);
    current->next->next = current;
    current->next = NULL;
}

void Clear_heap() {
    ///Function to clear the allocated memory.
    Node* temp = head;
    while (temp != NULL) {
        head = head->next;
        delete temp;
        temp = head;
    }
}

int main() {
    head = NULL; //empty list.

    //Create the list.
    Append(2);
    Append(4);
    Append(6);
    Append(5);
    Append(7);

    Print_recursive(head);      // HEAD -> 2 -> 4 -> 6 -> 5 -> 7 -> NULL
    cout<<endl;
    //Print_recursive_reverse(head);
    Reverse_recursive(head);
    Print();

    /*
    int pos;
    cout<<"Enter the position from where you want to delete: ";
    cin>>pos;
    Delete(pos);
    */

    Clear_heap(); // Clear the list.
    return 0;
}
