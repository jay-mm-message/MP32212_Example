#include <iostream>
using namespace std;

// Triangular matrix to one-dimensional array
const int array_size = 5;
int m[array_size][array_size] = {
    {76, 0, 0, 0, 0},
    {54, 51, 0, 0, 0},
    {23, 8, 26, 0, 0},
    {43, 25, 18, 8, 0},
    {12, 9, 14, 35, 46}
};

int main() {

    for (size_t i = 0; i < array_size; i++)
    {
        /* code */
        for (size_t j = 0; j < array_size; j++)
        {
            /* code */
            if (i >= j)
            {
                /* code */
                cout << m[i][j] << ' ';
            }
            
        }
        
    }
    
    cout << endl;
    return 0;
}