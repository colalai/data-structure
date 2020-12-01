#include <iostream>
#include <iomanip>
using namespace std;
int main(int argc, char *argv[]) {
	int Score[4][5];
	float student[4];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 5; j++)
			cin >> Score[i][j];
	for (int k = 0; k < 4; k++)
		student[k] = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 5; j++)
			student[i] += Score[i][j];
		

	for (int i = 0; i < 4; i++)
	{
		cout << setprecision(1) << fixed << student[i] / 5 << " ";
	}
	cout << endl;
}
//65 85 78 75 69 66 55 52 92 47 75 99 63 73 86 77 88 99 91 100
