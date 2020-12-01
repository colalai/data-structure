#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
	int Array_Data[3][5], arr[15], k = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 5; j++)
			cin >> Array_Data[i][j];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 5; j++)
		{
			k = j + i * 5;
			arr[k] = Array_Data[i][j];
		}
	for (int k = 0; k < 15; k++)
		cout << arr[k] << " ";
	cout << endl;
}
//1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
