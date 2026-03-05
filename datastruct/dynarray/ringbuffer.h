

/*
Implementing a dynamic ring buffer (circular buffer) in C++. 
A ring buffer is a fixed-size data structure that uses a single, contiguous block of memory as if it were connected end-to-end. 
Going to make this to make a more efficient queue implementation that can be used in the queue data structures.
Apparently queue semantics are:
- Enqueue (push_back): Add an element to the end of the queue.
- Dequeue (pop_front): Remove an element from the front of the queue.

so the front of the line is the head
             O                 O                 
[Lemonade]  - -               - -
  [Stand]    |                 |
            / \  next person  / \  next person ... and so on so we join back of the line and 
                                                   person at the front leaves (can order lemonade) when called pop_front()
*/


#pragma once

class RingBuffer {

public:
    
    RingBuffer();

    RingBuffer(int capacity);

    ~RingBuffer();

    void push_back(int value); // add an element to the end of the buffer
    void pop_front(); // remove an element from the front of the buffer
    void increase_size(); // if full, increase the size of the buffer by doubling its capacity, copying the existing elements to the new buffer, and updating the head and tail indices accordingly
    int front() const; // get the element at the front of the buffer
    int back() const; // get the element at the back of the buffer  
    bool empty() const; // check if the buffer is empty
    bool full() const; // check if the buffer is full
    int size() const; // get the current number of elements in the buffer

private:
    int* data; // pointer to the buffer array
    int head; // index of the front element
    int tail; // index of the next position to insert an element
    int count; // current number of elements in the buffer
    int capacity; // maximum capacity of the buffer

};