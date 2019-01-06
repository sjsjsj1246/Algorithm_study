#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int check[101];

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> list(n);
	for (int i = 0; i < n; i++)
		cin >> list[i];
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		bool key = 1;
		for (int j = 0; j < count; j++)
		{
			if (list[check[j]] == list[i]) key = 0;
		}
		if (key)
		{
			check[count] = i;
			count++;
		}
	}
	if (count >= k)
	{
		printf("YES\n");
		for (int i = 0; i < k; i++)
			printf("%d ", check[i] + 1);
	}
	else
		printf("NO");
}