#pragma region preset_for_PS
// need
#include <iostream>
#include <algorithm>
// data structure
#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <deque>
#include <array>
// stream
#include <istream>
#include <sstream>
#include <ostream>
// etc
#include <cstdlib>
#include <cmath>
#include <functional>
#include <chrono>
#include <random>
#include <cstring>
using namespace std;
typedef long long int ll;
// input
#define ALL(a) (a).begin(),(a).end()
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,-1,sizeof(a))
#define CASES(t) int t; cin >> t; while(t--)
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD 1000000007
#define INF 987654321
#define SUB(a) cout << a << "\n";
// output
#define SP << " "
#define BR << "\n"
#define SPBR(i, n) <<(i + 1 == n ? '\n' : ' ');
#define SHOWVECTOR(v) {std::cerr << #v << "\t:";for(const auto& xxx : v){std::cerr << xxx << " ";}std::cerr << "\n";}
#define SHOWVECTOR2(v) {std::cerr << #v << "\t:\n";for(const auto& xxx : v){for(const auto& yyy : xxx){std::cerr << yyy << " ";}std::cerr << "\n";}}
#define SHOWQUEUE(a) {auto tmp(a);std::cerr << #a << "\t:";while(!tmp.empty()){std::cerr << tmp.front() << " ";tmp.pop();}std::cerr << "\n";}
// utility
#define FOR(w, a, n) for(int w=(a);w<(n);++w)
#define RFOR(w, a, n) for(int w=(n)-1;w>=(a);--w)
#define ITR(it, vec) for(auto it = vec.begin(); it!= vec.end(); it++)
#define RITR(it, vec) for(auto it = vec.rbegin(); it!= vec.rend(); it++)
template<typename S, typename T>
std::ostream& operator<<(std::ostream& os, std::pair<S, T> p) {
	os << "(" << p.first << ", " << p.second << ")"; return os;
}
#pragma endregion

int dp[11][10];

bool is_dec(int num) 
{
	int temp = num % 10;
	num /= 10;

	while(num > 0)
	{	
		if (temp >= num % 10) return false;
		temp = num % 10;
		num /= 10;
	}
	return true;
}

int main() 
{
	FAST;
	int i, j, N, k = 0, temp = 0, tempN = 10;
	cin >> N;
	if (N == 1022)
	{
		cout << 9876543210;
		return 0;
	}
	for (i = 0; i < 10; i++) dp[1][i] = 1;
	for (i = 2; i <= 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			for (int m = 0; m <= j - 1; m++) temp += dp[i - 1][m];
			dp[i][j] = temp;
			tempN += temp;
			if (tempN > N) goto exit;
			temp = 0;
		}
	}
exit:
	if (tempN == 1023)
	{
		puts("-1");
		return 0;
	}
	k = (j + 1) * pow(10, i - 1) - 1;
	for (; tempN != N; k--) is_dec(k) ? tempN-- : tempN;
	cout << k + 1;
}