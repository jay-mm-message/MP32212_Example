#include <iostream>
using namespace std;

void init_matrix(int *matrix, int rows, int cols) {
    for (size_t i = 0; i < rows; i++)
    {
        /* code */
        for (size_t j = 0; j < cols; j++)
        {
            /* code */
            matrix[i * cols + j] = 0;
        }
        
    }
    
}

void create_sparse_matrix(int *matrix, int rows, int cols, int num) {
    
    srand(time(NULL));

    for (size_t i = 0; i < num; i++)
    {
        /* code */
        int rrows = rand() % rows;
        int rcols = rand() % cols;

        while(rrows == 0 || rcols == 0) {
            rrows = rand() % rows;
            rcols = rand() % cols;
        }

        if (matrix[rrows * cols + rcols] == 0)
        {
            /* code */
            int value = rand() % num;
            while (value == 0) {
                value = rand() % num;
            }
            matrix[rrows * cols + rcols] = value;
        }
        
    }
}

void show_matrix(int *matrix, int rows, int cols) {

    cout << endl;
    cout << "-------sparese matrix ----" << endl;
    for (size_t i = 0; i < rows; i++)
    {
        /* code */
        for (size_t j = 0; j < cols; j++)
        {
            /* code */
            cout << matrix[i * cols + j] << ' ';
        }
        cout << endl;
    }
    cout << "-------------------------" << endl;
}

void create_compress_matrix(int *sparse_matrix,
     int rows, int cols, int elment_num, 
     int *compress_matrix, int cm_rows, int cm_cols) {

    int current_rows = 0;
    compress_matrix[current_rows * cm_cols + 0] = rows;
    compress_matrix[current_rows * cm_cols + 1] = cols;
    compress_matrix[current_rows * cm_cols + 2] = elment_num;

    current_rows++;
    for (size_t i = 0; i < rows; i++)
    {
        /* code */
        for (size_t j = 0; j < cols; j++)
        {
            /* code */
            if (sparse_matrix[i * cols + j] != 0)
            {
                /* code */
                compress_matrix[current_rows * cm_cols + 0] = i;
                compress_matrix[current_rows * cm_cols + 1] = j;
                compress_matrix[current_rows * cm_cols + 2] = sparse_matrix[i * cols + j];
                current_rows++;
            }
            
        }
        
    }
}

int main() {

// 3 - tuple
// 8 * 9 sparse matrix
// compress matrix 9 * 3

    int rows = 8, cols = 9;
    int sparse_m[rows][cols];
    int elemet_num = 8;

    init_matrix(&sparse_m[0][0], rows, cols);
    create_sparse_matrix(&sparse_m[0][0], rows, cols, elemet_num);
    show_matrix(&sparse_m[0][0], rows, cols);

    int cm_rows = 9, cm_cols = 3;
    int compress_m[9][3];
    init_matrix(&compress_m[0][0], cm_rows, cm_cols);
    create_compress_matrix(&sparse_m[0][0], rows, cols, elemet_num, &compress_m[0][0], cm_rows, cm_cols);
    show_matrix(&compress_m[0][0], cm_rows, cm_cols);    

    cout << endl;
    return 0;
}