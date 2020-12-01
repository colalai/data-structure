#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
	int Score[3][4][5], stu_sum[4] = { 0 }, 
		obj_sum[5] = { 0 };
	for (int k = 0; k < 3; k++)
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 5; j++)
				cin >> Score[k][i][j];

	for (int k = 0; k < 3; k++)
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 5; j++)
			{
				stu_sum[i] += Score[k][i][j];
				obj_sum[j] += Score[k][i][j];
			}
	cout << "同學總成績：";
	for (int i = 0; i < 4; i++)
		cout << stu_sum[i] << " ";
	cout << "科目總成績：";
	for (int i = 0; i < 5; i++)
		cout << obj_sum[i] << " ";
}
//65 85 78 75 69 66 55 52 92 47 75 99 63 73 86 77 88 99 91 99 77 88 66 77 66 65 66 88 55 77 70 88 56 88 88 80 90 95 99 99 55 67 56 98 67 66 69 76 66 78 77 89 88 77 77 88 89 99 97 88
