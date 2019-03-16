#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <functional>
using namespace std;

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int n1, m1;
	cin >> n1 >> m1;
	vector<vector<int>> mat1(n1, vector<int>(m1));
	for (int i = 0; i < n1; i++) for (int j = 0; j < m1; j++) cin >> mat1[i][j];

	int n2, m2;
	cin >> n2 >> m2;
	vector<vector<int>> mat2(n2, vector<int>(m2));
	for (int i = 0; i < n2; i++) for (int j = 0; j < m2; j++) cin >> mat2[i][j];

	vector<vector<int>> mat3(n1, vector<int>(m2));
	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < m2; j++)
		{
			int sum = 0;
			for (int k = 0; k < m1; k++)
			{
				sum += mat1[i][k] * mat2[k][j];
			}
			mat3[i][j] = sum;
		}
	}
	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < m2; j++)
		{
			cout << mat3[i][j] << " ";
		}
		cout << "\n";
	}
}