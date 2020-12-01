#include <iostream>
using namespace std;

const int rows = 4;
const int columns = 4;

void matrix_print(int arr[][columns])
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			cout << arr[i][j] << " ";
	cout << endl;
}

void matrix_transpose(int arr[][columns])
{
	int newArr[rows][columns] = { 0 };
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			newArr[j][i] = arr[i][j];
	matrix_print(newArr);
}

void matrix_init(int arr[][columns])
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			cin >> arr[i][j];
}

int main(int argc, char *argv[])
{
	int A[rows][columns];
	matrix_init(A);
	matrix_transpose(A);
}
