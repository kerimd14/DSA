# include <iostream>
# include "slkdlist.h"


SinglyLinkedList::SinglyLinkedList() : head(nullptr), size(0) {}


SinglyLinkedList::~SinglyLinkedList() {
    Node* current = head; // make a pointer to the head of the list, so we can traverse it and delete each node
    while (current) {
        Node* nextNode = current->next; // store the pointer to the next node before deleting the current node, so we don't lose access to the rest of the list
        // If you have a pointer to an object, and you want to access that object’s members, you use ->.
        delete current;
        current = nextNode;
    }
}


void SinglyLinkedList::append(int value) {


    Node* newnode = new Node(value);

    if (head == nullptr) {
        head = newnode;
        return;
    }

    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = newnode;
    // Go to the node pointed to by current,
    // and set its next pointer to point to newnode.
    // current --> A --> nullptr
    // newnode --> B --> nullptr
    // current --> A --> B --> nullptr

    // newnode = current->next; 
    // Make newnode point to whatever current->next points to.
    // current --> A --> B --> nullptr
    // newnode --> X (some new node)
    // newnode --> B --> nullptr

    size++;
}

void SinglyLinkedList::insert(int value) {
    Node* newnode = new Node(value);
    newnode->next = head; // Make the new node point to the current head of the list.
    head = newnode; // Update the head of the list to be the new node.

    size++;
}


void SinglyLinkedList::display() const {
    Node* current = head; 

    while (current != nullptr) { 
        std::cout << current->data << " "; 
        current = current->next; 
    }

        std::cout << std::endl;
    }

void SinglyLinkedList::remove(int value) {
    if (head == nullptr) {
        return; // List is empty, nothing to remove
    }


    // Case 1: remove head
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
        return;
    }

    Node* current = head; // make a pointer to the head of the list, so we can traverse it and delete each node
    while (current->next != nullptr) { // traverse the list until we reach the end (current->next == nullptr)
        if (current->next->data == value) { 
            Node* temp = current->next; 
            current->next = temp->next; 
            delete temp; // delete temporary node, which is the node we want to remove

            size--;
            return; // exit the function after removing the node
        } 
        current = current->next; // move to the next node
    }

}

void SinglyLinkedList::removeAll(int value) {
    if (head == nullptr) {
        return; // List is empty, nothing to remove
    }


    // Case 1: remove head
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
        return;
    }

    Node* current = head; // make a pointer to the head of the list, so we can traverse it and delete each node
    while (current->next != nullptr) { // traverse the list until we reach the end (current->next == nullptr)
        if (current->next->data == value) { 
            Node* temp = current->next; 
            current->next = temp->next; 
            delete temp; // delete temporary node, which is the node we want to remove
            size--;
        } 
        else {
            current = current->next; // move to the next node
        }
    }

}


void SinglyLinkedList::removeAtindex(int index) {
    
    if (head == nullptr || index < 0)
        return;

    // remove head if index is 0
    if (index == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
        return;
    }
    
    
    Node* current = head;
    int i = 0;

    // Stop at node BEFORE the one we want to remove
    while (current != nullptr && i < index - 1) {
        current = current->next;
        ++i;
    }

    // If index is out of bounds
    if (current == nullptr || current->next == nullptr)
        return;

    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
    size--;
}


