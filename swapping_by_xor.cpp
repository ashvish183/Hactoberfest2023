#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a, b;
	cout <<"a and b:";
	cin >> a >> b;
	a ^= b;
	b ^= a;
	a ^= b;
	cout << "a=" << a << " "
		 << "b=" << b << endl;
	 return 0;
}