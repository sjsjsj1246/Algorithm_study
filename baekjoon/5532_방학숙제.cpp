#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int l, a, b, c, d;
	cin >> l >> a >> b >> c >> d;
	cout << l - max(a / c + (a%c ? 1 : 0) , b / d + (b%d ? 1 : 0));
}