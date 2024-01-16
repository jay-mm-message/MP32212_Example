#include <iostream>
using namespace std;

int factorial(int x) {
    if (x == 1)
    {
        /* code */
        return 1;
    }
    
    return x * factorial(x - 1);
}

int main() {

    cout << "Please enter factorial: ";
    int n = 0;
    cin >> n;
    cout << "Factorial(" << n << "): " << factorial(n);

    cout << endl;
    return 0;
}