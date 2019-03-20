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
#define MOD 1000000009
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

int main()
{
	FAST;
	deque<int> dq;
	CASES(t)
	{
		int n;
		string s;
		cin >> s;
		if (s == "push_front")
		{
			cin >> n;
			dq.push_front(n);
		}
		else if (s == "push_back")
		{
			cin >> n;
			dq.push_back(n);
		}
		else if (s == "pop_front")
		{
			if (dq.empty()) cout << -1 << "\n";
			else
			{
				cout << dq.front() << "\n";
				dq.pop_front();
			}
		}
		else if (s == "pop_back")
		{
			if (dq.empty()) cout << -1 << "\n";
			else
			{
				cout << dq.back() << "\n";
				dq.pop_back();
			}
		}
		else if (s == "size")
		{
			cout << dq.size() << "\n";
		}
		else if (s == "empty")
		{
			cout << dq.empty() << "\n";
		}
		else if (s == "front")
		{
			if (dq.empty()) cout << -1 << "\n";
			else cout << dq.front() << "\n";
		}
		else if (s == "back")
		{
			if (dq.empty()) cout << -1 << "\n";
			else cout << dq.back() << "\n";
		}
	}
}