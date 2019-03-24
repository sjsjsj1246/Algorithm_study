#include <bits/stdc++.h>
using namespace std;

int n, k;

struct Data
{
	int idx, g, s, b;
	bool operator<(Data op)
	{
		if (this->g > op.g) return 1;
		else if (this->g == op.g)
		{
			if (this->s > op.s) return 1;
			else if (this->s == op.s)
			{
				if (this->b > op.b) return 1;
				else if (this->b == op.b)
					return this->idx == k; //동일 점수에 대해 k가 제일 먼저 오도록
			}
		}
		return 0;
	}
};

int main() 
{
	cin >> n >> k;

	vector<Data> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].idx >> arr[i].g >> arr[i].s >> arr[i].b;
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < n; i++)
	{
		if (arr[i].idx == k)
		{
			cout << i + 1 << "\n";
			break;
		}
	}

	return 0;
}