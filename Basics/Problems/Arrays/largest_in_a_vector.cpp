#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Finds the largest element in a vector.
int find_largest_element(const vector<int>& arr) {
    return *max_element(arr.begin(), arr.end());
}

int main() {
    vector<int> numbers = {1, 10, 9, 54, 2, 2};

    cout << "The largest element is: " << find_largest_element(numbers) << endl;

    return 0;
}