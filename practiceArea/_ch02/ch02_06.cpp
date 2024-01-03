#include <iostream>
using namespace std;
// Matrix transpose

void matrix_transpose(int *a_m, int *ta_m, int m, int n)
{
    for (size_t i = 0; i < m; i++)
    {
        /* code */
        for (size_t j = 0; j < n; j++)
        {
            /* code */
            ta_m[j * m + i] = a_m[i * n + j];
        }
        cout << endl;
    }
}

void show_matrix(int *a_m, int m, int n)
{
    for (size_t i = 0; i < m; i++)
    {
        /* code */
        for (size_t j = 0; j < n; j++)
        {
            /* code */
            cout << a_m[i * n + j] << ' ';
        }
        cout << endl;
    }
    
}

void init_matrix(int *arr, int m, int n)
{
    int num = 1;
    for (size_t i = 0; i < m; i++)
    {
        /* code */
        for (size_t j = 0; j < n; j++)
        {
            /* code */
            arr[i * n + j] = num;
            ++num;
        }
        
    }
    
}

int main()
{
    int m, n;
    cout << "Entry the dimension of matrix m: ";
    cin >> m;
    cout << "Entry the dimension of matrx n: ";
    cin >> n;

    int *a_m = new int[m*n];
    init_matrix(a_m, m, n);
    show_matrix(a_m, m, n);

    int *ta_m = new int[n*m];
    matrix_transpose(a_m, ta_m, m, n);
    show_matrix(ta_m, n, m);

    cout << endl;
    return 0;
}