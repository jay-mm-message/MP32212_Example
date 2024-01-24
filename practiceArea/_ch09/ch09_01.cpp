#include <iostream>
using namespace std;

void init_vec(vector<int> &vec, int count);
void show(vector<int> &vec);

int main() {
    vector<int> vec(0);
    init_vec(vec, 80);
    show(vec);

    int foundNum = 1;
    bool isFound = false;
    int searchCount = 1;

    for (size_t i = 0; i < 80; i++)
    {
        /* code */
        if (vec[i] == foundNum)
        {
            /* code */
            isFound = true;
            break;
        }
        /* code */
        ++searchCount;
    }

    if (isFound)
    {
        /* code */
        cout << "Found number: " << foundNum << ", search cost: " << searchCount << endl;
    }
    else
    {
         cout << "Not found number: " << foundNum << ", search cost: " << searchCount << endl;
    }
    
    return 0;
}

void show(vector<int> &vec) {
    cout << "vec: ";
    for (size_t i = 0 ; i < vec.size() ; i++)
    {
        /* code */
        cout << vec[i] << ' ';
    }
    cout << endl;
}

void init_vec(vector<int> &vec, int count) {
    for (size_t i = 0; i < count; i++)
    {
        /* code */
        vec.push_back(rand() % 150 + 1);
    }
    
}