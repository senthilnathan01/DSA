/*
PROBLEM:

Diwali Discount
Chef is trying to buy a Diwali gift for Rs.A, and he has a voucher for Rs. B. 
Chef will have to pay the remaining amount after applying the voucher. 
If the voucher's value exceeds the gift's value, Chef will not have to pay anything.

Find the amount that Chef will pay for buying the gift.

Input Format
The first and only line of input contains 2 integers - A and B.

Output Format
For each test case, output on a new line the amount paid by Chef.

*/

#include <iostream>
using namespace std;

int main() {
	int A, B;
	cin>>A>>B;
	cout<<max(A-B, 0);
}

// INPUT:
// 3000 1000

// OUTPUT:
// 2000

// INPUT:
// 0