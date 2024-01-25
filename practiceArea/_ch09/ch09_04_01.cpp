#include <iostream>
#include <iomanip>
using namespace std;


int main(void) {
    int data[] = {323, 458, 25, 340, 28, 969, 77};
    vector<int> vec(data, data + sizeof(data)/ sizeof(int));
    int row = 11;
    int col = 2;
    vector<vector<int> > vec2(row, vector<int>(col, 0));

    for (size_t i = 0; i < row ; i++)
    {
        /* code */
        vec2[i][0] = i;
    }

    for (size_t j = 0; j < vec.size() ; j++)
    {
        /* code */
        int mod = vec[j] % 11;
        vec2[mod][1] = vec[j];
    }
    
    for (size_t i = 0; i < row; i++)
    {
        /* code */
        cout << setw(2) << vec2[i][0] << ' ' << setw(2) << vec2[i][1] << endl;
    }
    
    cout << endl;
    
    return 0;
}