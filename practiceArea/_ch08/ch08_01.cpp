// select sort
#include <iostream>
using namespace std;

void show(int arr[], int size);
void swap_data(int &a, int &b);
void min_selection_sort(int arr[], int size);
void max_selection_sort(int arr[], int size);

int main() {

    int data[] = {55, 23, 87, 62, 16};

    cout << "origin: ";
    show(data, 5);
    
    cout << "min selection sort: ";
    min_selection_sort(data, 5);
    show(data, 5);

    cout << "max selection sort: ";
    max_selection_sort(data, 5);
    show(data, 5);
    return 0;
}

void show(int arr[], int size) {
    for (int i = 0 ; i < size ; ++i) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void min_selection_sort(int arr[], int size) {
    for (size_t i = 0; i < size; i++)
    {
        /* code */
        int min = arr[i];
        for (size_t j = 0; j < size; j++)
        {
            /* code */
            if (min < arr[j])
            {
                /* code */
                swap(arr[i], arr[j]);
            }
        }  
    } 
}

void max_selection_sort(int arr[], int size) {
    for (size_t i = 0; i < size; i++)
    {
        int max = arr[i];
        for (size_t j = 0; j < size; j++)
        {
            /* code */
            if (max > arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}