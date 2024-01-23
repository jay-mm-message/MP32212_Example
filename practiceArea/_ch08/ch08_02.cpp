#include <iostream>

using namespace std;

void swap(int &a, int &b);
void selection_sort(vector<int> &vec);
void show(vector<int> vec);
void init_vec(vector<int> &vec, int count);
void insertion_sort(vector<int> &vec);

int main() {
   
    vector<int> vec;
    init_vec(vec, 5);
    cout << "origin: ";
    show(vec);
    
    selection_sort(vec);
    show(vec);

    insertion_sort(vec);
    show(vec);
    

    return 0;
}

void init_vec(vector<int> &vec, int count) {
    for (size_t i = 0; i < count; i++)
    {
        /* code */
        vec.push_back(count - i);
    }
    
}

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}
void selection_sort(vector<int> &vec) {
    // selection vec for all - 1
    for (size_t j = 0; j < vec.size() - 1; j++)
    {
        /* code */
        // scan index for all - 1 find out min
        int index_min = j;
        for (size_t i = j + 1; i < vec.size(); i++)
        {
            /* code */
            if (vec[index_min] > vec[i])
            {
                /* code */
                index_min = i;
            }

        }
        // swap
        swap(vec[index_min], vec[j]);
    }

    cout << "selection sort finish";
}

void show(vector<int> vec) {
    for (size_t i = 0; i < vec.size(); i++)
    {
        /* code */
        cout << vec[i] << ' ';
    }
    cout << endl;
}

void insertion_sort(vector<int> &vec) {
    for (size_t i = 1; i < vec.size(); i++)
    {
        /* code */
        // move backward
        int key = vec[i];
        int bk = i - 1;
        while (bk >= 0 && vec[bk] < key)
        {
            /* code */
            vec[bk+1] = vec[bk];
            --bk;
        }
        vec[bk + 1] = key;
    }
    cout << "insertion sort finish";
}