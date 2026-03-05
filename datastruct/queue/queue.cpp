#include <iostream>
#include <stdexcept>
#include "ringbuffer.h"
#include "queue.h"

Queue::Queue() : data() {} // data() calls the default constructor


Queue::~Queue() {}

void Queue::enqueue(int value) {
    data.push_back(value); // add an element to the end of the queue
}

void Queue::dequeue() {
    if (empty()) {
        throw std::out_of_range("Queue is empty");
    }
    data.pop_front(); // remove an element from the front of the queue
}

int Queue::front() const {
    if (empty()) {
        throw std::out_of_range("Queue is empty");
    }
    return data.front(); // get the element at the front of the queue
}

int Queue::back() const {
    if (empty()) {
        throw std::out_of_range("Queue is empty");
    }
    return data.back(); // get the element at the back of the queue
}

bool Queue::empty() const {
    return data.empty(); // check if the queue is empty
}



