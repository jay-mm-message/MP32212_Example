#include <iostream>
using namespace std;

void MatrixMultiply(int *, int *, int *, int, int, int);
int main()
{
	int M, N, P;
	int i, j;
	// 痻皚A场だ
	cout << "Please enter the dimensions of matrix A(M,N): " << endl;
	cout << "M= ";
	cin >> M;
	cout << "N= ";
	cin >> N;
	int *A = new int[M * N];
	cout << "[Please enter the individual elements of matrix A]" << endl;
	for (i = 0; i < M; i++)
		for (j = 0; j < N; j++)
		{
			cout << "a" << i << j << "=";
			cin >> A[i * N + j];
		}
	// 痻皚B场だ
	cout << "Please enter the dimensions of matrix B(N,P): " << endl;
	cout << "N= ";
	cin >> N;
	cout << "P= ";
	cin >> P;
	int *B = new int[N * P];
	cout << "[Please enter the individual elements of Matrix B]" << endl;
	for (i = 0; i < N; i++)
		for (j = 0; j < P; j++)
		{
			cout << "b" << i << j << "=";
			cin >> B[i * P + j];
		}
	// M = 2;
	// N = 3;
	// int A[2][3] = {{5, 4, 3}, {6, 7, 8}};
	// N = 3;
	// P = 2;
	// int B[3][2] = {{3, 4}, {6, 7}, {3, 6}};

	int *C = new int[M * P];
	MatrixMultiply(A, B, C, M, N, P); // ㊣ㄧ计
	//TMatrixMultiply(&A[0][0], &B[0][0], C, M, N, P); // ㊣ㄧ计
	cout << "[The result of A x B is]" << endl;
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < P; j++)
			cout << C[i * P + j] << "\t";
		cout << endl;
	}
}
// 秈︽痻皚
void MatrixMultiply(int *arrA, int *arrB, int *arrC, int M, int N, int P)
{
	if (M <= 0 || N <= 0 || P <= 0)
	{
		cout << "[Error: Dimensions M, N, P must be greater than 0]" << endl;
		return;
	}
	for (int i = 0; i < M; i++)
		for (int j = 0; j < P; j++)
		{
			int Temp;
			Temp = 0;
			for (int k = 0; k < N; k++)
				Temp = Temp + arrA[i * N + k] * arrB[k * P + j];
			arrC[i * P + j] = Temp;
		}
}
