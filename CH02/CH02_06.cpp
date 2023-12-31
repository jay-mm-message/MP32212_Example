#include <iostream>
using namespace std;

int main()
{
	int M, N, row, col;
	cout << "[Enter the dimensions of the MxN matrix]" << endl;
	cout << "Please enter the dimension M: ";
	cin >> M;
	cout << "Please enter the dimension N: ";
	cin >> N;

	int *arrA = new int[M * N]; // 宣告動態陣列
	int *arrB = new int[M * N];
	cout << "[Please enter the matrix content]" << endl;
	for (row = 1; row <= M; row++)
	{
		for (col = 1; col <= N; col++)
		{
			cout << "a" << row << col << "=";
			cin >> arrA[(row - 1) * N + (col - 1)];
		}
	}
	cout << "[Enter the matrix content as]" << endl;
	for (row = 1; row <= M; row++)
	{
		for (col = 1; col <= N; col++)
		{
			cout << arrA[(row - 1) * N + (col - 1)] << "\t";
		}
		cout << endl;
	}
	// 進行矩陣轉置的動作
	for (row = 1; row <= N; row++)
		for (col = 1; col <= M; col++)
			arrB[(col - 1) * N + (row - 1)] = arrA[(row - 1) + (col - 1) * N];

	cout << "[Transpose the matrix content as]" << endl;
	for (row = 1; row <= N; row++)
	{
		for (col = 1; col <= M; col++)
		{
			cout << arrB[(col - 1) * N + (row - 1)] << "\t";
		}
		cout << endl;
	}
}
