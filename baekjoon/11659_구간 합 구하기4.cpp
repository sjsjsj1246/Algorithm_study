#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	vector<int> arr(n+1);
	arr[0] = 0;
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		int temp; scanf("%d", &temp);
		sum += temp;
		arr[i] = sum;
	}
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", arr[b] - arr[a - 1]);
	}
}
