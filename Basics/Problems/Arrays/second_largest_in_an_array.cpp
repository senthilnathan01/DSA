#include <iostream>
#include <algorithm>

using namespace std;

// Finds the largest element in an array.
int find_largest_element(int arr[], int size) {
    return *max_element(arr, arr + size);
}

// Finds the second largest element in an array.
int find_second_largest_element(int arr[], int size) {
    // Find the largest element.
    int largest = find_largest_element(arr, size);

    // Initialize the second largest as -1.
    int second_largest = -1;

    // Iterate through the array to find the second largest.
    for (int i = 0; i < size; i++) {
        // Update the second largest if the current element is greater than the current second largest
        // and not equal to the largest.
        if (second_largest < arr[i] && arr[i] != largest) {
            second_largest = arr[i];
        }
    }

    return second_largest;
}

int main() {
    int numbers[] = {1, 10, 9, 54, 2, 2};

    // Calculate the size of the array dynamically.
    int array_size = sizeof(numbers) / sizeof(numbers[0]);

    cout << "The second largest element is: " << find_second_largest_element(numbers, array_size) << endl;

    return 0;
}