#include <iostream>
using namespace std;

// Find the minimum value.

int main()
{
    int num[2][3][3] = {{   {33, 45, 67},
                            {23, 71, 56},
                            {55, 38, 66}},
                        {   {21, 9, 15},
                            {38, 69, 18},
                            {90, 101, 89}}};

    int minimum = -1;
    for (size_t k = 0; k < 2; k++)
    {
        /* code */
        for (size_t i = 0; i < 3; i++)
        {
            /* code */
            for (size_t j = 0; j < 3; j++)
            {
                /* code */
                if (minimum == -1)
                {
                    /* code */
                    minimum = num[k][i][j];
                }
                else
                {
                    if (minimum > num[k][i][j])
                    {
                        /* code */
                        minimum = num[k][i][j];
                    }
                    
                }
            }
            
        }
        
    }

    // The answer is 9
    cout << "minimum is " << minimum << endl;
    
    cout << endl;
    return 0;
}