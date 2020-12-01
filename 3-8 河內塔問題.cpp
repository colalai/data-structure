#include <iostream>
using namespace std;
void Towers(int n, char a, char b, char c)
{
    if(n>0)
    {
        Towers(n-1,a,c,b);
        cout<<"Move disk "<<n<<" from "<<a<<" to "<<c<<'\n';
        Towers(n-1,b,a,c);
    }
}
int main(int argc, char *argv[]) {
	int a;
	cin>>a;
	Towers(a,'A','B','C');
}
