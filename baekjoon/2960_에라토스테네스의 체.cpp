#include <iostream>

using namespace std;

bool check[1001] = {1,1,}; //0�϶� �Ҽ�

int main(void)
{
	int n, k, cnt=0;
	cin >> n >> k;
	for (int i = 2; i < n+1; i++) 
	{
		if (check[i] == 0)
		{
			cnt++;
			if (cnt == k)
			{
				cout << i;
				return 0;
			}
			for (int j = 2; i*j <n+1; j++)
			{
				if (check[i*j] == 0) cnt++;
				check[i*j] = 1; 
				if (cnt == k)
				{
					cout << i*j;
					return 0;
				}
			}
		}
	}

}