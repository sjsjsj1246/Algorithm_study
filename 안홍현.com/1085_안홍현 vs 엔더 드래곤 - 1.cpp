#include <stdio.h>

int main()
{
	int n, s;
	scanf("%d%d", &n, &s);

	int arr[10001];
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (arr[i] > arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	int l = 0, r = n - 1, ans = 0;
	while (l <= r)
	{
		int sum = arr[l] + arr[r];
		if (sum == s) ans += 2, l++, r--;
		else if (sum < s) l++;
		else if (sum > s) r--;
	}
	printf("%d", ans);
}