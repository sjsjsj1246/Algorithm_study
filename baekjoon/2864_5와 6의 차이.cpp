#include <iostream>
using namespace std;

int to5(int n)
{
	int ret = 0, cnt=1;
	while (n)
	{
		if (n % 10 == 6) ret += 5*cnt;
		else ret += (n % 10)*cnt;
		cnt *= 10;
		n /= 10;
	}
	return ret;
}

int to6(int n)
{
	int ret = 0, cnt=1;
	while (n)
	{
		if (n % 10 == 5) ret += 6*cnt;
		else ret += (n % 10)*cnt;
		cnt *= 10;
		n /= 10;
	}
	return ret;
}

int main()
{
	int a, b;
	cin >> a >> b;
	cout << to5(a) + to5(b) << " " << to6(a) + to6(b);
}