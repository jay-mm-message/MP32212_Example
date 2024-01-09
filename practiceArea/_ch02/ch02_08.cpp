#include <iostream>
using namespace std;

// Triangular matrix to one-dimensional array
int main() {

    const int array_size = 5;
    int matrix_a[array_size][array_size] = {
        {7, 8, 12, 21, 9},
        {0, 5, 14, 17, 6},
        {0, 0, 7, 23, 24},
        {0, 0, 0, 32, 19},
        {0, 0, 0, 0, 8}
    };

    for (size_t i = 0; i < array_size; i++)
    {
        /* code */
        for (size_t j = 0; j < array_size; j++)
        {
            /* code */
            if (i <= j)
            {
                /* code */
                cout << matrix_a[i][j] << ' ';
            }
            
        }
        
    }
    

    cout << endl;
    return 0;
}