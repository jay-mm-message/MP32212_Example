// bubble sort
#include <iostream>
using namespace std;

void show(int arr[], int size);
void swap_data(int &a, int &b);
void bubble_sort(int arr[], int size);

int main() {

    int data[] = {55, 23, 87, 62, 16};

    show(data, 5);
    bubble_sort(data, 5);
    show(data, 5);
    return 0;
}

void show(int arr[], int size) {
    for (int i = 0 ; i < size ; ++i) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

void swap_data(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;

    //cout << "swap" << endl;
}

void bubble_sort(int arr[], int size) {
    for (size_t j = 0; j < size; j++)
    {
        cout << "Round " << j + 1 << endl; 
        /* code */
        for (size_t i = 1; i < size; i++)
        {
            /* code */
            if (arr[i-1] > arr[i])
            {
                /* code */
                swap_data(arr[i-1], arr[i]);
                // int tmp = arr[i-1];
                // arr[i-1] = arr[i];
                // arr[i] = tmp;
            }
            show(arr, size);
        }
    }   
}