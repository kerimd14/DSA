#include <iostream>
#include <stdexcept>
#include "dynarray.h"

int run_dynarray_tests() {
    Dynarray v;

    std::cout << "Initially: size=" << v.getSize()
              << " cap=" << v.getCapacity()
              << " empty=" << v.empty() << "\n";

    for (int i = 0; i < 10; ++i) {
        v.push_back(i * 10);
        std::cout << "push " << i * 10
                  << " -> size=" << v.getSize()
                  << " cap=" << v.getCapacity() << "\n";
    }

    for (int i = 0; i < v.getSize(); ++i) {
        std::cout << "v[" << i << "]=" << v[i] << "\n";
    }

    v[0] = 999;
    std::cout << "after modify: v[0]=" << v[0] << "\n";

    v.pop_back();
    v.pop_back();
    std::cout << "After 2 pops: size=" << v.getSize()
              << " cap=" << v.getCapacity() << "\n";

    try {
        std::cout << v[999] << "\n";
        std::cout << "Bounds test failed: expected exception\n";
        return 1;
    } catch (const std::out_of_range& e) {
        std::cout << "Caught expected exception: " << e.what() << "\n";
    }

    return 0;
}
