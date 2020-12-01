#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
	int value1, value2, avg = 0;
	cin >> value1 >> value2;
	avg = (value1 + value2) / 2;
	if (avg >= 60)
		cout << "及格" << endl;
	else
		cout << "不及格" << endl;
}
