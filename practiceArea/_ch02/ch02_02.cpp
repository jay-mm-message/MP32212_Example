#include <iostream>
using namespace std;

// 2x2 determinant

int main()
{
    int detm[2][2] = {{2, 3}, {4, 5}};

    int determinant = detm[0][0] * detm[1][1] - detm[0][1] * detm[1][0];

    cout << "------------------" << endl;
    for (size_t i = 0; i < 2; i++)
    {
        cout << '|' << ' ';
        /* code */
        for (size_t j = 0; j < 2; j++)
        {
            /* code */
            cout << detm[i][j] << ' ';
        }
        cout << '|';
        cout << endl;
    }
    
    cout << "------------------" << endl;
    cout << "2x2 determinant: " << determinant << endl;
    
    cout << endl;
    return 0;
}