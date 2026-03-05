#include <iostream>
#include <stdexcept>
#include "stack.h"

int run_stack_tests() {
    Stack s;

    std::cout << "Stack initially empty=" << s.empty() << "\n";

    s.push(10);
    s.push(20);
    s.push(30);

    std::cout << "Top after pushes: " << s.top() << "\n";
    if (s.top() != 30) {
        std::cout << "Top test failed\n";
        return 1;
    }

    s.pop();
    if (s.top() != 20) {
        std::cout << "Pop test failed\n";
        return 1;
    }

    s.pop();
    s.pop();
    if (!s.empty()) {
        std::cout << "Empty test failed\n";
        return 1;
    }

    try {
        s.top();
        std::cout << "Expected exception for top() on empty stack\n";
        return 1;
    } catch (const std::out_of_range& e) {
        std::cout << "Caught expected top() exception: " << e.what() << "\n";
    }

    try {
        s.pop();
        std::cout << "Expected exception for pop() on empty stack\n";
        return 1;
    } catch (const std::out_of_range& e) {
        std::cout << "Caught expected pop() exception: " << e.what() << "\n";
    }

    return 0;
}
