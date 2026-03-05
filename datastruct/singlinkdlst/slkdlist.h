// implementingf a singly linked list in C++


class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}

    

};

class SinglyLinkedList {
private:
    Node* head;
    int size;
public:
    SinglyLinkedList() : head(nullptr) {}
    ~SinglyLinkedList();
    void insert(int value); // insert we add to the beginning of the list, so its O(1)
    void append(int value); // append we add to end of list but its O(n), have to traverse list
    void remove(int value); 
    void removeAll(int value); // remove all occurrences of a value in the list, also O(n)
    void removeAtindex(int index); // remove the node at the specified index, also O(n)
    void display() const; // const because we don't want to modify the list when displaying it, and it allows us to call display on const objects of SinglyLinkedList
    int getSize() const;
};

