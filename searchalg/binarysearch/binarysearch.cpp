#include "binarysearch.h"
#include <stdexcept>

int BinarySearch(int arr[], int size, int target) {

    int low = 0;
    int high = size -1;
    int mid = 0;

    while (low <= high) {

        mid = (high + low)/2; // since its integer i think it should round down

        if (arr[mid] == target) {
            return arr[mid];
        }

        else if (target > arr[mid]) {
            low = mid + 1;
        }

        else if (target < arr[mid])
        {
            high = mid -1;
        }

        else {
            throw std::logic_error("Unexpected condition in binary search");
        }
        
    }


    return -1;
}