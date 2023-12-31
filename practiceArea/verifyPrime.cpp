#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    while (n > 1)
    {
        int divisor = 0;

        int isPrimeNum = 0;
        for(int i = 2 ; i <= n ; ++i) {
            if ((n % i) == 0) {
                // record divisor
                isPrimeNum = i;
                ++divisor;
            }
        }
        // Verify it's a prime number, then read out the records.
        if (divisor == 1) {
            cout << isPrimeNum << " is prime number." << endl;
        }
        divisor = 0;
        isPrimeNum = 0;
        /* code */
        --n;
    }
    
    return 0;
}