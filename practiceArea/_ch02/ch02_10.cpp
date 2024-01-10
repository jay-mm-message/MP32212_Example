#include <iostream>
using namespace std;

void polySum(int mA[], int mB[], int mC[], int m) {

    for (size_t i = 1; i < 6; i++)
    {
        /* code */
        mC[i] = mA[i] + mB[i];
    }

}

void show_poly_matrix(int m[], int num) {
    
    int poly_num = m[0];
    for (size_t i = 1; i < num - 1; i++)
    {
        /* code */
        cout << m[i] << "X^" << poly_num << " + ";
        --poly_num;
    }
    cout << m[num-1] << endl;
    cout << endl;

}

int main() {

    int mA[] = {4, 3, 7, 0, 6, 2};
    int mB[] = {4, 1, 5, 2, 0, 9};
    int mC[] = {4, 0, 0, 0, 0, 0};

    polySum(mA, mB, mC, 6);
    show_poly_matrix(mC, 6);
    
    return 0;
}