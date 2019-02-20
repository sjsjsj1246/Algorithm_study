//bottom-up
#include <iostream>
#include <algorithm>
using namespace std;
int a[1001][3];//[인덱스][색]
int d[1001][3];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		d[i][0] = min(d[i - 1][1], d[i - 1][2]) + a[i][0];
		d[i][1] = min(d[i - 1][0], d[i - 1][2]) + a[i][1];
		d[i][2] = min(d[i - 1][0], d[i - 1][1]) + a[i][2];
        //이전 색과 겹치지 않게 하기 위함
	}
	cout << min({ d[n][0], d[n][1], d[n][2] }) << '\n';
	return 0;
}

//top-down으로 하기에는 너무 비효율적임, 이럴 때 바텀업을 쓰자