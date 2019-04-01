#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() 
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> f(n+1, 0);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		f[a]++;
		f[b]++;
	}
	for (int i = 1; i < f.size();i++) cout << f[i] << "\n";
}