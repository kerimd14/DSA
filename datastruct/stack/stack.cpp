#include "stack.h"
#include <stdexcept> // for std::out_of_range exception

Stack::Stack() : arr(){}

Stack::~Stack() {
    // No need for explicit cleanup since Dynarray's destructor will handle it
}

void Stack::push(int value) {
    arr.push_back(value);
}

void Stack::pop() {
    if (empty()) {
        throw std::out_of_range("Stack is empty");
    }
    arr.pop_back();
}   

int Stack::top() const {
    if (empty()) {
        throw std::out_of_range("Stack is empty");
    }
    return arr[arr.getSize() - 1]; // return the last element in the dynamic array
}

bool Stack::empty() const {
    return arr.empty();
}
