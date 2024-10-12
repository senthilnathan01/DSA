#include <iostream>
#include <algorithm>

using namespace std;

// Finds the largest element in an array.
int find_largest_element(int arr[], int size) {
    return *max_element(arr, arr + size);
}

int main() {
    int numbers[] = {1, 10, 9, 54, 2, 2};

    // Calculate the size of the array dynamically.
    int array_size = sizeof(numbers) / sizeof(numbers[0]);

    cout << "The largest element is: " << find_largest_element(numbers, array_size) << endl;

    return 0;
}