#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(ww, aa, nn) for(int ww=(aa);ww<(nn);++ww)
#define ALL(aa) (aa).begin(),(aa).end()
#define CASES(tt) int aa; cin >> aa; for(int tt=1;tt<=aa;tt++)
#define MOD 1000000007
#define INF 987654321
typedef long long ll;
using namespace std;

int main()
{
	FAST;
	int n;
	cin >> n;
	vector<ll> last;
	vector<pair<int, ll>> ans(1000001);
	last.push_back(-1000000001);
	ans[0].first = 0;
	ans[0].second = -1000000001;
	for (int i = 0; i < n; i++)
	{
		ll cur;
		cin >> cur;
		if (last.back() < cur) 
		{
			last.push_back(cur);
			ans[i].first = last.size() - 2;
			ans[i].second = cur;
		}
		else
		{
			auto pos = lower_bound(last.begin(), last.end(), cur);
			*pos = cur;
			ans[i].first = pos - last.begin() - 1;
			ans[i].second = cur;
		}
	}
	cout << last.size() - 1 << "\n";
	stack<int> s;
	int temp = last.size() - 2;
	for (int i = n - 1; i >= 0; i--)
	{
		if (ans[i].first == temp)
		{
			s.push(ans[i].second);
			temp--;
		}
	}
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
}

/* 
    1 6 2 5 7 3 5 6인 경우
    ans배열에는 다음과 같이 들어간다.

    first ::  0 1 1 2 3 2 3 4
    second :: 1 6 2 5 7 3 5 6

    이 값을 first를 기준으로 뒤에서 부터 조사해오면
    first가 4일때 (6) - > first가 3일때 (5) -> first가 2일때 (3) 
    -> first가 1일때 (2) -> first가 0일때(1)이다.
    이것을 스택에 담아 역출력하면 1,2,3,5,6이라는 실제 배열을 구할 수 있다.
*/
