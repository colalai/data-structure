#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
	int arr[5] = {};
	float total = 0;
	for (int i = 0; i < 5; i++)
		cin >> arr[i];
	for (int i = 0; i < 5; i++)
		total += arr[i];
	cout << total / 5 << endl;
}
