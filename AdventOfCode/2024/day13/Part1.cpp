#include<iostream>
#include <string>
#include <sstream>

using namespace std;

// Given:
// A: X+xa, Y+ya
// B: X+xb, Y+yb
// nA + mB = x, y
// n*xa + m*xb = x
// n*ya + m*yb = y
// Write n and m in terms of other given variables
// (x-m*xb)*ya/xa + m*yb = y
// x*ya/xa + m*(yb - xb*ya/xa) = y
// m = (xa*y - ya*x)/(xa*yb - xb*ya)
// n = (-xb*y + yb*x)/(xa*yb - xb*ya)

// if (xa*yb - xb*ya) = 0 -> Infinite solutions 
// Otherwise unique solutions
// If inifinite solutions, then we optimize
// Obj Function: Minimize Cost = 3*n + m
// Where 0<=N<=100 and 0<=M<=100 

int main() {
    int tC = 320;
    int token1 = 0, token2 = 0;
    while(tC--)
    {
        string input1, input2, input3;

        // Read inputs
        // Read input for Button A
        do {
            getline(cin, input1);
            if (cin.eof()) return 0; // Exit on EOF
        } while (input1.empty()); // Skip empty lines
        getline(cin, input2); // Button B: X+98, Y+36
        getline(cin, input3); // Prize: X=6697, Y=10467

        // Variables to store the extracted values
        int xa, ya, xb, yb, x, y;

        // Parse Button A
        size_t pos = input1.find("X+");
        xa = stoi(input1.substr(pos + 2));
        pos = input1.find("Y+");
        ya = stoi(input1.substr(pos + 2));

        // Parse Button B
        pos = input2.find("X+");
        xb = stoi(input2.substr(pos + 2));
        pos = input2.find("Y+");
        yb = stoi(input2.substr(pos + 2));

        // Parse Prize
        pos = input3.find("X=");
        x = stoi(input3.substr(pos + 2)); 
        pos = input3.find("Y=");
        y = stoi(input3.substr(pos + 2));

        // Output the extracted values
        cout << "xa = " << xa << ", ya = " << ya << endl;
        cout << "xb = " << xb << ", yb = " << yb << endl;
        cout << "x = " << x << ", y = " << y << endl;

        // Optional: Separate test case outputs for clarity
        cout << "------" << endl;

        float frac1 = float(xa)/ya;
        float frac2 = float(xb)/yb;
        float frac3 = float(x)/y;
        // Unique soln
        if(x>0 && y>0)
        {
            if(frac1 != frac2)
            {
                float m = float(xa*y - ya*x)/(xa*yb - xb*ya);
                float n = float(-xb*y + yb*x)/(xa*yb - xb*ya);

                // n and m should be integers
                if((m - (int)m) == 0 && (n - (int)n) == 0)
                {
                    // n and m should be in the specified range
                    if(n>=0 && n<101 && m>=0 && m<101)
                    {
                        cout<<"yes"<<endl;
                        cout<<"n "<<n<<" m "<<m<<endl;
                        token1 += n; token2 += m;
                    }
                    else continue;
                }   
                else continue;
            }
        }
    }
    cout<<(3*token1+token2);
    return 0;
}