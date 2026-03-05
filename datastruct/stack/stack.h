#pragma once

#include "dynarray/dynarray.h"

class Stack {
public:
    Stack();
    ~Stack();

    void push(int value);
    void pop();
    int top() const;
    bool empty() const;

private:
    Dynarray arr;
};
