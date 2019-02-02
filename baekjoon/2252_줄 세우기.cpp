#include <iostream>
#include <cstring>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <string>
using namespace std;
typedef signed long long LL;

#define FOR(x,to) for(int x=0;x<(to);x++)
#define ITR(x, arr) for(auto x = arr.begin(); x!= arr.end(); x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,-1,sizeof(a))
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//-------------------------------------------------------
/*
��ǥ���� �������� ����

1. ���� ������ 0�� ����(��, ������ ������ ���� 0)�� ����
	- ���� ������ 0�� ������ ���� �� ������ ��� ��� ������ �����ص� �����ϴ�.
	- �ʱ⿡ ������ ���� 0�� ��� ������ ť�� ����
2. ���õ� ������ ���⿡ �μӵ� ��� ������ ����
	- ���õ� ������ ť���� ����
	- ���õ� ������ �μӵ� ��� ������ ���� ������ ���� ����
3. ���� ������ �ݺ��ؼ� ��� ������ ����, �����Ǹ� �˰��� ����

ť �Ǵ� �켱���� ť ���
*/

int main() 
{
	int n, m, a, b;
	cin >> n >> m;
	vector<int> cntOfLink(n+1);
	vector<vector<int>> adj;
	vector<int> temp;
	queue<int> q;

	FOR(i, n+1) adj.push_back(temp);
	FOR(i, m)
	{
		cin >> a >> b;
		adj[a].push_back(b);
		cntOfLink[b]++;
	}

	for (int i = 1; i < n+1; i++)
	{
		if (cntOfLink[i] == 0)
		{
			q.push(i);
		}
	}

	for (int i = 0; i < n; i++)
	{
		int v = q.front();
		q.pop();
		cout << v << " ";

		for (int nv : adj[v])
		{
			cntOfLink[nv]--;

			if (cntOfLink[nv] == 0)
				q.push(nv);
		}
	}
}