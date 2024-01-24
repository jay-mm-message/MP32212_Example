#include <iostream>
using namespace std;

void init_vec(vector<int> &vec, int count);
void show(vector<int> &vec);
void selection_sort(vector<int> &vec);
void linear_search(vector<int> &vec, int foundNum);
void binary_search(vector<int> &vec, int foundNum);

const int BSR = 1;
const int LSR = 2;

int main() {
    vector<int> vec(0);
    init_vec(vec, 80);
    show(vec);
    //linear_search(vec, 8);


    int search_mode = 0, search_number = 0;
    cout << "Please enter search mode: (1) binary search, (2) linear search ";
    cin >> search_mode;
    cout << "Please enter search number: ";
    cin >> search_number;

    switch (search_mode)
    {
    case BSR:
        selection_sort(vec);
        show(vec);
        binary_search(vec, search_number);
        break;
    case LSR:
        linear_search(vec, search_number);
        break;
    default:
        break;
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
    cout << endl << endl;
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
    cout << __FUNCTION__ << ":" << ' ';
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

void binary_search(vector<int> &vec, int foundNum) {

    cout << __FUNCTION__ << ":" << ' ';
    int search_cost = 1;
    int l = 0;
    int r = vec.size();
    int mid = (l + r) / 2;

    bool isFound = false;
    while (l <= r && foundNum != -1)
    {
        /* code */
        if (foundNum > vec[mid])
        {
            /* code */
            l = mid + 1;
            search_cost++;
        }
        else if (foundNum < vec[mid])
        {
            r = mid - 1;
            search_cost++;
        }
        else
        {
            isFound = true;
            break;
        }
        mid = (l + r) / 2;
    }
    if (isFound)
    {
        /* code */
        cout << "Found num: " << foundNum << ", search cost: " << search_cost << endl;
    }
    else
    {
        cout << "Not found num: " << foundNum << endl;
    }
    
}