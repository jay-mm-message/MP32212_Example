#include <iostream>
using namespace std;
// Calculate the sum of two 3x3 matrices

void show_matrix(int arr[][3], int size)
{
    cout << "----------------------" << endl;
    for (size_t i = 0; i < size; i++)
    {
        cout << "| ";
        /* code */
        for (size_t j = 0; j < size; j++)
        {
            /* code */
            cout << arr[i][j] << ' ';
        }
        cout << '|';
        cout << endl;
    }
    cout << "----------------------" << endl;
} 

int main()
{
    int a_mtx[3][3] = { {1, 3, 5}, 
                        {7, 9, 11}, 
                        {13, 15, 17}};
    int b_mtx[3][3] = { {9, 8, 7},
                        {6, 5, 4},
                        {3, 2, 1}};
    int c_mtx[3][3] = {{}};

    cout << "matrix a:" << endl;
    show_matrix(a_mtx, 3);
    cout << "matrix b:" << endl;
    show_matrix(b_mtx, 3);

    for (size_t i = 0; i < 3; i++)
    {
        /* code */
        for (size_t j = 0; j < 3; j++)
        {
            /* code */
            c_mtx[i][j] = a_mtx[i][j] + b_mtx[i][j];
        }
        
    }

    // The answer is {{10, 11, 12}, {13, 14, 15}, {16, 17, 18}}
    cout << "The result of adding matrix a and matrix b: " << endl;
    show_matrix(c_mtx, 3);
    

    cout << endl;
    return 0;
}