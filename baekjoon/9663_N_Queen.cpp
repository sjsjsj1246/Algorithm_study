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
typedef signed long long ll;

#define FOR(x,to) for(x=0;x<(to);x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,-1,sizeof(a))
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//-------------------------------------------------------

/*
���پ� �������鼭 ���� �־��� ���� �ϸ鼭 ������ ����
*/

int n;
bool vertical[14]; //�������� ���� ���翩��, �������� Ž�� ������ �ʿ����� ����
bool d1[27]; 
//������ �� ������ �밢���� ���� ���翩�� ������ �迭�ε� ǥ���� �� �ִ� ��ũ�� 2n-1
//�밢���� ���а����� x+y�� �ε���
bool d2[27]; // ������ �Ʒ� ������ �밢���� ���� ���翩�� (n-1)+(y-x)�� �ε���

int N_Queen(int y)
{
	if (y == n) return 1;
	int sum = 0;
	for (int x = 0; x < n; x++)
	{
		if (vertical[x]) continue;
		if (d1[x + y] || d2[(n - 1) + (y - x)]) continue;

		vertical[x] = d1[x + y] = d2[(n - 1) + (y - x)] = 1;
		sum += N_Queen(y + 1);
		vertical[x] = d1[x + y] = d2[(n - 1) + (y - x)] = 0;
	}
	return sum;
}

int main()
{
	cin >> n;
	cout << N_Queen(0);
}