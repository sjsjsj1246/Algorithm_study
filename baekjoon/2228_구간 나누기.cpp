#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
부분합으로 구간합을 구하면서 dp
dp[현재 위치][현재 구간 수] = 최대값
값에 -도 있음 주의
for 
ret = max(ret, segSum(start, start + i) + solve(start + i + 2, cnt + 1));
*/

const int MINF = -987654321;
int n, m;
vector<int> parSum;
vector<vector<int>> cache(101, vector<int>(51, MINF));

int segSum(int a, int b)
{
	return parSum[b] - parSum[a - 1];
}

int solve(int start, int cnt)
{
	if (cnt == m) return 0;
	if (start > n) return MINF * 10;
	// cnt != m 즉 구간이 다 선택되지 않았는데 n이 초과했다는 것은 이 경로로 오면 안된다는 뜻이다.
	// 이전의 segsum의 합으로 인해 MINF만 반환할 경우 제대로 처리가 안될수 있으니 10을 곱해준다.
	int& ret = cache[start][cnt];
	if (ret != MINF) return ret;
	ret = solve(start + 1, cnt); //구간 시작 안하고 넘어가는 경우
	for (int i = 0; i <= n - start; i++)
	{
		ret = max(ret, segSum(start, start + i) + solve(start + i + 2, cnt + 1));
		// 현재 위치에서 i만큼 구간의 합 + 두칸 떨어진 뒤에 다시 탐색
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	parSum.resize(n + 1);
	for (int i = 1; i <= n; i++) cin >> parSum[i], parSum[i] += parSum[i - 1];
	cout << solve(1, 0);
}