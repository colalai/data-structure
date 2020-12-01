#include <iostream>
using namespace std;
int Fib(int n)
{
    if(n<=2)
        return 1;
    else
        return Fib(n-1)+Fib(n-2);
}
int main(int argc, char *argv[]) {
	int a,t;
	cin>>a;
	t=Fib(a);
	cout<<t;
}
