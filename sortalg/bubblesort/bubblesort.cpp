
void BubbleSort(int arr[], int size) {
    for (int i=0; i < size - 1; i++) {
        // add possible a swapped flag to optimize it so if there is no swap in the inner loop then we can break out of the loop since the array is already sorted
        
        bool swapped = false;
        for (int j=0; j < (size - i - 1) ;  j++) {

            if (arr[j] > arr[j+1]) {
                int temp =  arr[j+1];
                arr[j+1] =  arr[j];
                arr[j] = temp;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }

    }

};