#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
	int Score[6], sum = 0;
	for (int i = 0; i < 6; i++)
		cin >> Score[i];
	for (int i = 0; i < 6; i++)
		sum += Score[i];
	cout << sum << endl;
}
