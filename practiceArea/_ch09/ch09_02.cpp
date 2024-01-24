#include <iostream>
using namespace std;

void init_vec(vector<int> &vec, int count);
void show(vector<int> &vec);
void selection_sort(vector<int> &vec);
void linear_search(vector<int> &vec, int foundNum);

int main() {
    vector<int> vec(0);
    init_vec(vec, 80);
    show(vec);
    linear_search(vec, 8);

    // selection_sort(vec);
    // show(vec);
    
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

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void selection_sort(vector<int> &vec) {
    for (size_t i = 0 ; i < vec.size() - 1; i++)
    {
        /* code */
        int min_index = i;
        for (size_t j = i + 1; j < vec.size(); j++)
        {
            /* code */
            if (vec[min_index] > vec[j])
            {
                /* code */
                min_index = j;
            }
            
        }
        swap(vec[min_index], vec[i]);
    }
    
}

void linear_search(vector<int> &vec, int foundNum) {
    //int foundNum = 1;
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
}