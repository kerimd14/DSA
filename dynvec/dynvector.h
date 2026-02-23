
class Dynvector {
    private:
        int* data; // pointer to the dynamic array
        int size; // size of the vector
        int capacity; // capacity of the container where the elements are stored

        void resize(int new_capacity);

    public:

        // default constructor
        Dynvector();
        // default destructor
        ~Dynvector();


        int getSize() const;

        int getCapacity() const;

        bool empty() const;

        void push_back(int value);

        void pop_back();

        int& operator[](int index); // non-const version for modifying elements
        // returns a reference to the element at the specified index, allowing modification of the element`

        const int& operator[](int index) const;
        
};

