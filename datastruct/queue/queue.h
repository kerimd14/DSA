# include "ringbuffer.h"

/*
just classical queue but implemented using 
*/

class Queue {

    public:

    Queue();
    ~Queue();

    void enqueue(int value); //push to back (enter from back of line)
    void dequeue(); //remove from front
    int front() const; // see front value
    int back() const; // see back value
    bool empty() const; 



    private:
    RingBuffer data; // this is COMPOSITION

};

// Composition is a HAS-A relationship, meaning we have something from another class. For example object Car and Engine
// A Car has an Eningen.
// it is not an enignen.
//COMPOSITIOn is a prefered desgin choice 
// (because from what i understand you can interface between objects as seperate objects without influencing each other)
// with inheritance you can use class Queue to also carry out methods of class Ringbuffer
// but if we want to keep it seperate as most of the time then only use Composition, since then we cant acsses methods and attributes of RIngbuffer unless we explicitly make it like that