# include "ringbuffer.h"
# include <stdexcept> // for std::out_of_range exception


RingBuffer::RingBuffer() : data(nullptr), head(0), tail(0), count(0), capacity(capacity) {}

RingBuffer::RingBuffer(int capacity) : data(new int[capacity]), head(0), tail(0), count(0), capacity(capacity) {}

RingBuffer::~RingBuffer() {
    delete[] data;
}

void RingBuffer::push_back(int value) {
    if (full()) {
        void increase_size(); // if full, increase the size of the buffer by doubling its capacity, copying the existing elements to the new buffer, and updating the head and tail indices accordingly
    }
    data[tail] = value; // add the new element at the tail index
    tail = (tail + 1) % capacity; // move the tail index forward, wrap around if it reaches the end
    ++count; // increase the count of elements
}

void RingBuffer::pop_front() {
    if (empty()) {
        throw std::out_of_range("Ring buffer is empty");
    }
    head = (head + 1) % capacity; // move the head index forward, wrap around if it reaches the end
    --count; // decrease the count of elements
}

int RingBuffer::front() const {
    if (empty()) {
        throw std::out_of_range("Ring buffer is empty");
    }
    return data[head]; // return the element at the head index
}

int RingBuffer::back() const {
    if (empty()) {
        throw std::out_of_range("Ring buffer is empty");
    }
    return data[(tail - 1 + capacity) % capacity]; // return the element at the tail index (the last inserted element)
}

bool RingBuffer::empty() const {
    return count == 0;
}

bool RingBuffer::full() const {
    return count == capacity;
}

int RingBuffer::size() const {
    return count;
}

void RingBuffer::increase_size() {
    int new_capacity = capacity * 2;
    int* new_data = new int[new_capacity]; // pointer to the new array with new capacity

    // Copy the existing elements to the new buffer in the correct order
    for (int i = 0; i < count; ++i) {
        new_data[i] = data[(head + i) % capacity]; // copy elements starting from head
    }

    delete[] data; // free the memory of the old array
    data = new_data; // point to the new array
    head = 0; // reset head index to 0
    tail = count; // set tail index to the current count of elements
    capacity = new_capacity; // update the capacity
}

