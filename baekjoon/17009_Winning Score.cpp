#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int sum1 = 0, sum2 = 0, temp;
	for (int i = 0; i < 3; i++) cin >> temp, sum1 += temp * (3 - i);
	for (int i = 0; i < 3; i++) cin >> temp, sum2 += temp * (3 - i);
	if (sum1 > sum2) cout << 'A';
	else if (sum1 < sum2) cout << 'B';
	else cout << 'T';
}