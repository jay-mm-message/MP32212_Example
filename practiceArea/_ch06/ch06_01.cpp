// char data[] = {'D', 'B', 'F', 'A', 'C', 'E', 'G'};
#include <iostream>
using namespace std;

void create_bt(char bt[], char data[], int count);
void show_bt(char bt[], int count);
int main() {

    char data[] = {'D', 'B', 'F', 'A', 'C', 'E', 'G'};
    int size = sizeof(data) / sizeof(char);

    char bt[50] = {'\0'};
    create_bt(bt, data, size);
    show_bt(bt, size);

    return 0;
}

void create_bt(char bt[], char data[], int count) {

    int level;
    for (size_t i = 0; i < count; i++)
    {
        /* code */
        for (level = 1; bt[level] != '\0';)
        {
            /* code */
            if (data[i] > bt[level])
            {
                /* code */
                // right node
                level = level * 2 + 1;
            }
            else
            {
                // left node
                level = level * 2;
            }
        }   
        bt[level] = data[i];
    }
    
}

void show_bt(char bt[], int count) {
    cout << "BTree: ";
    for (size_t i = 1; i < count + 1; i++)
    {
        /* code */
        cout << i << ":" << bt[i] << ' ';
    }
    
    cout << endl;
}