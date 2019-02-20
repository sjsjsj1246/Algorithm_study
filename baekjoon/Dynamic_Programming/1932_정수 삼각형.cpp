#include <iostream>
#include <algorithm>
using namespace std;

int arr[501][501];

int main() 
{
	int n, result = 0;
	cin >> n;
	

	for (int i = 1; i <= n; i++) 
	{
		for (int j = 1; j <= i; j++) 
		{
			cin >> arr[i][j];
			arr[i][j] += max(arr[i - 1][j - 1], arr[i - 1][j]); //바로 dp적용
			if (i == n) result = max(result, arr[i][j]);
		}
	}
	cout << result;
}