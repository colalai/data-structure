#include <iostream>
using namespace std;
int fact(int n)
{
    int result;
    if(n==0)
        result=1;
    else
        result=n*fact(n-1);
    return result;
}
int main(int argc, char *argv[]) {
	int a,total;
	cin>>a;
	total=fact(a);
	cout<<total;
}
