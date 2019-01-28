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
한줄씩 내려가면서 퀸을 넣었다 뺐다 하면서 조합을 만듬
*/

int n;
bool vertical[14]; //수직축의 퀸의 존재여부, 가로축은 탐색 구조상 필요하지 않음
bool d1[27]; 
//오른쪽 위 방향의 대각선에 퀸의 존재여부 일차원 배열로도 표현할 수 있다 총크기 2n-1
//대각선을 구분가능함 x+y로 인덱싱
bool d2[27]; // 오른쪽 아래 방향의 대각선에 퀸의 존재여부 (n-1)+(y-x)로 인덱싱

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