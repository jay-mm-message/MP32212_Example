#include <iostream>
using namespace std;
// Calculate the product of two matrices

void in_matrix(int *a_m, int m, int n)
{
    for (size_t i = 0; i < m; i++)
    {
        /* code */
        for (size_t j = 0; j < n; j++)
        {
            /* code */
            cout << "a_m["<< i <<"]["<< j << "]:";
            cin >> a_m[i * n + j];
        }
        
    }
    
}

void show_matrix(int *matrix, int m, int n)
{
    cout << "----------------" << endl;
    for (size_t i = 0; i < m; i++)
    {
        /* code */
        for (size_t j = 0; j < n; j++)
        {
            /* code */
            cout << matrix[i * n + j] << ' ';
        }
        cout << endl;
    }
    cout << "----------------" << endl;
}

void product_maxtrices(int *a_m, int *b_m, int *out_m, int m, int n, int p)
{
    for (size_t i = 0; i < m; i++)
    {
        /* code */
        for (size_t j = 0; j < p; j++)
        {
            /* code */
            int tmp = 0;
            for (size_t k = 0; k < n; k++)
            {
                /* code */
                tmp = tmp + a_m[i * n + k] * b_m[k * p + j];
                out_m[i * p + j] = tmp;
            }
            
        }
        
    }
    
}

int main() {

    int m, n;
    
    cout << "matrix a: " << endl;
    cout << "Enter m: ";
    cin >> m;
    cout << "Enter n: ";
    cin >> n;

    // matrix a: {{5, 4, 3}, {6, 7, 8}}
    int *a_m = new int[m*n];
    in_matrix(a_m, m, n);
    show_matrix(a_m, m, n);

    int p;
    cout << "matrix b: " << endl;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter p: ";
    cin >> p;

    // matrix b: {{3, 4}, {6, 7}, {3, 6}}
    int *b_m = new int[n*p];
    in_matrix(b_m, n, p);
    show_matrix(b_m, n, p);

    // The answer is: {{48, 66}, {84, 121}};
    int *c_m = new int[m*p];
    product_maxtrices(a_m, b_m, c_m, m, n, p);
    show_matrix(c_m, m, p);

    delete [] a_m;
    delete [] b_m;
    delete [] c_m;
    
    return 0;
}