#include <iostream>
#include <unordered_map>
#include <string>

#define ll long long int
using namespace std;

// Function to split a number into two parts
pair<ll, ll> split_number(ll n) {
    string n_str = to_string(n);
    size_t mid = n_str.size() / 2;
    ll left = stoll(n_str.substr(0, mid));
    ll right = stoll(n_str.substr(mid));
    return {left, right};
}

// Function to process stones using a frequency map
unordered_map<ll, ll> process_stones(const unordered_map<ll, ll>& stones) {
    unordered_map<ll, ll> new_stones;

    for (const auto& p : stones) {
        if (p.first == 0) {
            new_stones[1] += p.second; // Replace 0 with 1
        } 
        else if (to_string(p.first).size() % 2 == 0) {
            // Split into two stones
            pair<ll,ll> lr = split_number(p.first);
            ll left = lr.first;
            ll right = lr.second;
            new_stones[left] += p.second;
            new_stones[right] += p.second;
        } 
        else {
            // Replace stone with stone * 2024
            new_stones[p.first * 2024] += p.second;
        }
    }

    return new_stones;
}

// Function to simulate blinking
ll simulate_blinking(const unordered_map<ll, ll>& initial_stones, int steps) {
    unordered_map<ll, ll> stones = initial_stones;

    for (int step = 0; step < steps; ++step) {
        stones = process_stones(stones); // Update stones after each blink
    }

    // Calculate the total number of stones
    ll total_stones = 0;
    for (const auto& p : stones) {
        total_stones += p.second;
    }

    return total_stones;
}

int main() {
    // Initialize stones with their frequencies
    unordered_map<ll, ll> initial_stones;
    // Given Input
    initial_stones[8435] = 1;
    initial_stones[234] = 1;
    initial_stones[928434] = 1;
    initial_stones[14] = 1; 
    initial_stones[0] = 1;
    initial_stones[7] = 1;
    initial_stones[92446] = 1;
    initial_stones[8992692] = 1;
          
    // Number of steps to simulate
    int steps = 75;

    // Simulate blinking
    ll total_stones = simulate_blinking(initial_stones, steps);

    // Output the total number of stones
    std::cout << "Total stones after " << steps << " blinks: " << total_stones << std::endl;

    return 0;
}
