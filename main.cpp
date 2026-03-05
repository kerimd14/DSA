#include <iostream>
#include "datastruct/dynarray/dynarray_tests.h"
#include "datastruct/stack/stack_tests.h"

int main() {
    const int dynarray_status = run_dynarray_tests();
    const int stack_status = run_stack_tests();

    if (dynarray_status != 0 || stack_status != 0) {
        std::cout << "One or more tests failed\n";
        return 1;
    }

    std::cout << "All tests passed\n";
    return 0;
}



