#include <iostream>

using namespace std;

void swap(int &a, int &b);
void selection_sort(vector<int> &vec, int sort_mode);
void show(vector<int> vec);
void init_vec(vector<int> &vec, int count);
void insertion_sort(vector<int> &vec, int sort_mode);
void merge_sort(vector<int> &vec, int l, int r, int sort_mode);
void merge(vector<int> &vec, int l, int m, int r, int sort_mode);

const int sort_from_small_to_large = 1;
const int sort_from_large_to_smal  = 2;
const int no_sort = 3;

int main() {
   
    vector<int> vec;
    init_vec(vec, 5);
    show(vec);
    
    selection_sort(vec, sort_from_small_to_large);
    show(vec);

    insertion_sort(vec, sort_from_large_to_smal);
    show(vec);

    cout << "merge sort" << endl;
    merge_sort(vec, 0, vec.size() - 1, sort_from_small_to_large);
    show(vec);
    

    selection_sort(vec, sort_from_large_to_smal);
    show(vec);

    insertion_sort(vec, sort_from_small_to_large);
    show(vec);

    cout << "merge sort" << endl;
    merge_sort(vec, 0, vec.size() - 1, sort_from_large_to_smal);
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
    string log_msg = "";
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
                log_msg = "sort_from_small_to_large";
                /* code */
                if (vec[index] > vec[i])
                {
                    /* code */
                    index = i;
                }
            }

            if (sort_from_large_to_smal == sort_mode)
            {
                log_msg = "sort_from_large_to_smal";
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

    cout << "selection sort finish: " << log_msg << endl;
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

    string log_msg = "";
    for (size_t i = 1; i < vec.size(); i++)
    {
        /* code */
        // move backward
        int key = vec[i];
        int bk = i - 1;

        if (sort_from_large_to_smal == sort_mode)
        {
            log_msg = "sort_from_large_to_smal";
            while (bk >= 0 && key > vec[bk])
            {
                /* code */
                vec[bk+1] = vec[bk];
                --bk;
            }
        }

        if (sort_from_small_to_large == sort_mode)
        {
            log_msg = "sort_from_small_to_large";
            while (bk >= 0 && key < vec[bk])
            {
                /* code */
                vec[bk+1] = vec[bk];
                --bk;
            }
        }
        
        

        vec[bk + 1] = key;
    }
    cout << "insertion sort finish: " << log_msg << endl;
}

void merge_sort(vector<int> &vec, int l, int r, int sort_mode) {
    if (l < r)
    {
        int middle = l + (r - l) / 2;
        merge_sort(vec, l, middle, sort_mode);
        merge_sort(vec, middle + 1, r, sort_mode);

        merge(vec, l, middle, r, sort_mode);
    }
    
}
void merge(vector<int> &vec, int l, int m, int r, int sort_mode) {

    int l_size = m - l + 1;
    int r_size = r - m;

    vector<int> l_vec;
    vector<int> r_vec;

    for (size_t i = 0; i < l_size; i++)
    {
        /* code */
        l_vec.push_back(vec[ l + i ]);
    }

    for (size_t i = 0; i < r_size; i++)
    {
        /* code */
        r_vec.push_back(vec[ m + 1 + i]);
    }
    
    int i = 0;
    int j = 0;
    int k = l;

    if (sort_from_large_to_smal == sort_mode)
    {
        while (i < l_size && j < r_size)
        {
            if (l_vec[i] >= r_vec[j])
            {
                /* code */
                vec[k] = l_vec[i];
                ++k;
                ++i;
            }
            else
            {
                vec[k] = r_vec[j];
                ++k;
                ++j;
            }  
        }
    }

    if (sort_from_small_to_large == sort_mode)
    {
        while (i < l_size && j < r_size)
        {
            if (l_vec[i] <= r_vec[j])
            {
                /* code */
                vec[k] = l_vec[i];
                ++k;
                ++i;
            }
            else
            {
                vec[k] = r_vec[j];
                ++k;
                ++j;
            }  
        }
    }

    while (i < l_size)
    {
        /* code */
        vec[k] = l_vec[i];
        ++k;
        ++i;
    }

    while (j < r_size)
    {
        /* code */
        vec[k] = r_vec[j];
        ++k;
        ++j;
    }

}