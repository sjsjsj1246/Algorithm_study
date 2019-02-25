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
using namespace std;
typedef long long int ll;
// input
#define ALL(a) (a).begin(),(a).end()
#define ZERO(a) memset(aa,0,sizeof(a))
#define MINUS(a) memset(aa,-1,sizeof(a))
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
//----------------------------------------------------------

int count9(string s)
{
	int cnt = 0;
	for (auto c : s) if (c == '9') cnt++;
	return cnt;
}

int main()
{
	int n, m, ans = 0;
	cin >> n >> m;
	vector<int> row(n,0), col(m,0);
	string s;
	FOR(i, 0, n)
	{
		FOR(j, 0, m)
		{
			cin >> s;
			row[i] += count9(s);
			col[j] += count9(s);
		}
	}
	int row_max = *max_element(ALL(row));
	int col_max = *max_element(ALL(col));
	if (row_max < col_max)
	{
		for (auto x : col) ans += x;
		ans -= col_max;
	}
	else
	{
		for (auto x : row) ans += x;
		ans -= row_max;
	}
	cout << ans;
}

//------------------------
//cubelover님 풀이
#pragma GCC optimize("Ofast")
#include <cstdio>
#include <algorithm>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>

using namespace std;

char *p;

inline int readInt() {
	int t, r;
	for (r = *p++ - 48; (t = *p++ - 48) >= 0; r = r * 10 + t);
	return r;
}

short a[505], b[505];

int main() {
	struct stat buf;
	fstat(0, &buf);
	p = (char *)mmap(0, buf.st_size, PROT_READ, MAP_SHARED, 0, 0);

	int i, j, n, m, t, r = 0;
	n = readInt(); m = readInt();
	for (i = 0; i < n; i++) for (j = 0; j < m; j++) {
		while ((t = *p++) > 40) if (t == 57) {
			a[i]++;
			b[j]++;
			r++;
		}
	}
	printf("%d\n", r - max(*max_element(a, a + n), *max_element(b, b + m)));
	return 0;
}
