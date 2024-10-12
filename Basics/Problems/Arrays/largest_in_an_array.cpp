#include <iostream>
#include <algorithm>

using namespace std;

// Brute force approach will be to sort the array and return the last element in the array as the largest element
// Time complexity = O(nlogn)

// Optimal Approach
// Just traverse the array and keep updating the largest element if you find any element larger than the one we assume
// Time complexity = O(n)

// Here I used a STL for a much faster solution
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
