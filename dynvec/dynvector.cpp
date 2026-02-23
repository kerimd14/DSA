# include "dynvector.h"
# include <stdexcept> // for std::out_of_range exception


Dynvector::Dynvector() : data(nullptr), size(0), capacity(0) {}

// decleare nullptr for data, so that if destructor is called before any push_back, it won't try to delete uninitialized memory


// Dynvector::Dynvector() : size(0), capacity(1) {
//     data = new int[capacity];
// }

Dynvector::~Dynvector() {
    delete[] data;
}

// because new_capacity is small in memory we dont use alias (int& new_capacity), but just copy it to a new loc variable
void Dynvector::resize(int new_capacity) {
            if (new_capacity <= capacity)
                return;  // no need to shrink or same size

            int* new_data = new int[new_capacity]; // pointer to the new array with new capacity
            for (int i = 0; i < size; ++i) {
                new_data[i] = data[i]; // copy the old element values to the new array 
                // (starts at adress of the beginning of the pointer and moves through it)
                // data is a pointer to the first element of the array, so data[i] gives us the value at index i
                // data[i] is equivalent to *(data + i), which dereferences the pointer at the position of the index i
            }
            delete[] data; // free the memory of the old array
            data = new_data; // point to the new array
            capacity = new_capacity; // update the capacity
        }

int Dynvector::getSize() const {
            return size;
        }

int Dynvector::getCapacity() const {
    return capacity;
}

bool Dynvector::empty() const {
    return size == 0;
}

void Dynvector::push_back(int value) {
    if (size >= capacity) {
        int new_capacity = 1;
        if (capacity > 0) {
            new_capacity = capacity * 2;
        }
        resize(new_capacity);
    }
    data[size] = value; // add the new element at the end of the vector
    ++size; // increase the size
}

void Dynvector::pop_back() {
    if (size > 0) {
        --size; // decrease the size
        // Optionally, we could shrink the capacity if size is much smaller than capacity
    }
}

int& Dynvector::operator[](int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index]; // return reference to the element at the given index
}

const int& Dynvector::operator[](int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index]; // return reference to the element at the given index
}




