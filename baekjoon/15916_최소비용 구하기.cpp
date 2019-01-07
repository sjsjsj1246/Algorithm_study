#include <iostream>
#include <vector>
using namespace std;

int main()
{
	double n, k; cin >> n;
	vector<double> arr(n+1);
	for (int i = 1; i <= n; i++) cin >> arr[i];
	cin >> k;
	int up = 0, down = 0;
	for (int i = 1; i <= n; i++)
	{
		if (arr[i] / i > k) up++;
		else if (arr[i] / i < k) down++;
		else
		{
			cout << "T";
			return 0;
		}
		if (up > 0 && down > 0)
		{
			cout << "T";
			return 0;
		}
	}
	cout << "F";
	return 0;
}