#include <iostream>
using namespace std;

//#define HARD_CODIN_TEST

#ifdef HARD_CODIN_TEST
void MatrixMultiply(int *, int *, int *, int, int, int);
#else
void TMatrixMultiply(int *, int *, int *, int, int, int);
bool VerifyResult(int in_arrC[][2]);
#endif

int main()
{
	int M, N, P;
	int i, j;

#ifdef HARD_CODIN_TEST
	// // 痻皚A场だ
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
	// // 痻皚B场だ
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
#else
	M = 2;
	N = 3;
	int A[2][3] = {{5, 4, 3}, {6, 7, 8}};
	N = 3;
	P = 2;
	int B[3][2] = {{3, 4}, {6, 7}, {3, 6}};
#endif

#ifdef HARD_CODIN_TEST
	int *C = new int[M * P];
	MatrixMultiply(A, B, C, M, N, P); // ㊣ㄧ计
	cout << "[The result of A x B is]" << endl;
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < P; j++)
			cout << C[i * P + j] << "\t";
		cout << endl;
	}
#else
	int C[2][2] = {{0, 0}, {0, 0}};
	TMatrixMultiply(&A[0][0], &B[0][0], &C[0][0], M, N, P); // ㊣ㄧ计
	cout << "Test case: [The result of A x B is]" << endl;
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < P; j++)
			cout << C[i][j] << "\t";
		cout << endl;
	}
	if (VerifyResult(C)) {
		cout << "Test case is pass" << endl;
	} else {
		cout << "Test case is fail" << endl;
	}
#endif

}

bool VerifyResult(int in_arrC[][2]) {

	int arr_ans[2][2] = {{48, 66}, {84, 121}};
	for (size_t i = 0; i < 2; i++)
	{
		/* code */
		for (size_t j = 0; j < 2; j++)
		{
			/* code */
			if (in_arrC[i][j] != arr_ans[i][j])
			{
				/* code */
				return false;
			}
			
		}
		
	}
	return true;
}
void TMatrixMultiply(int *in_arrA, int *in_arrB, int *out_arrC, int M, int N, int P) {
	//f(i < M)
		// f(j < P)
			// tmp
			// f (k < N)
	for (size_t i = 0; i < M; i++)
	{
		/* code */
		for (size_t j = 0; j < P; j++)
		{
			/* code */
			int tmp = 0;
			for (size_t k = 0; k < N; k++)
			{
				/* code */
				tmp = tmp + in_arrA[i * N + k] * in_arrB[k * P + j];
			}
			out_arrC[i * P + j] = tmp;
		}
		
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
