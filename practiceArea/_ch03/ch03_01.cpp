#include <iostream>
using namespace std;

int main() {
    int m;
    cout << "Please enter the number of arrays: ";
    cin >> m;
    int *arr = new int[m];

    for (size_t i = 0; i < m; i++)
    {
        /* code */
        cout << "Enter ptr[" << i << "]: ";
        cin >> arr[i];
    }
    
    int sum = 0;
    for (size_t i = 0; i < m; i++)
    {
        /* code */
        sum = sum + arr[i];
    }
    
    cout << "The sum: " << sum << " of " << m << " numbers" << endl;

    delete [] arr;
    return 0;
}