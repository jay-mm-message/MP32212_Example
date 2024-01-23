#include <iostream>

using namespace std;

void swap(int &a, int &b);
void selection_sort(vector<int> &vec, int sort_mode);
void show(vector<int> vec);
void init_vec(vector<int> &vec, int count);
void insertion_sort(vector<int> &vec, int sort_mode);

const int sort_from_small_to_large = 1;
const int sort_from_large_to_smal  = 2; 

int main() {
   
    vector<int> vec;
    init_vec(vec, 5);
    show(vec);
    
    selection_sort(vec, sort_from_small_to_large);
    show(vec);

    insertion_sort(vec, sort_from_large_to_smal);
    show(vec);
    

    return 0;
}

void init_vec(vector<int> &vec, int count) {
    for (size_t i = 0; i < count; i++)
    {
        /* code */
        vec.push_back(count - i);
    }
    cout << "origin source" << endl;
}

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}
void selection_sort(vector<int> &vec, int sort_mode) {

    /*
    const int sort_from_small_to_large = 1;
    const int sort_from_large_to_smal  = 2; */
    // selection vec for all - 1
    for (size_t j = 0; j < vec.size() - 1; j++)
    {
        /* code */
        // scan index for all - 1 find out min
        int index = j;
        for (size_t i = j + 1; i < vec.size(); i++)
        {
            /* code */
            if (sort_from_small_to_large == sort_mode)
            {
                /* code */
                if (vec[index] > vec[i])
                {
                    /* code */
                    index = i;
                }
            }

            if (sort_from_large_to_smal == sort_mode)
            {
                /* code */
                if (vec[index] < vec[i])
                {
                    /* code */
                    index = i;
                }
            }
            

        }
        // swap
        swap(vec[index], vec[j]);
    }

    cout << "selection sort finish" << endl;
}

void show(vector<int> vec) {
    for (size_t i = 0; i < vec.size(); i++)
    {
        /* code */
        cout << vec[i] << ' ';
    }
    cout << endl;
}

void insertion_sort(vector<int> &vec, int sort_mode) {
    /*
    const int sort_from_small_to_large = 1;
    const int sort_from_large_to_smal  = 2; */
    for (size_t i = 1; i < vec.size(); i++)
    {
        /* code */
        // move backward
        int key = vec[i];
        int bk = i - 1;

        if (sort_from_large_to_smal == sort_mode)
        {
            while (bk >= 0 && vec[bk] < key)
            {
                /* code */
                vec[bk+1] = vec[bk];
                --bk;
            }
        }

        if (sort_from_small_to_large == sort_mode)
        {
            while (bk >= 0 && vec[bk] > key)
            {
                /* code */
                vec[bk+1] = vec[bk];
                --bk;
            }
        }
        
        

        vec[bk + 1] = key;
    }
    cout << "insertion sort finish" << endl;
}