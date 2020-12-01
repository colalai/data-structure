#include <iostream>
using namespace std;
int GCD(int a, int b)
{
    int c;
    c=a%b;
    if(c==0)
        return b;
    else
        return GCD(b,c);
}
int main(int argc, char *argv[]) {
	int a,b,c;
	cin>>a>>b;
	c=GCD(a,b);
	cout<<c;
}
