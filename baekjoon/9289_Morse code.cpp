#include <iostream>
#include <cstring>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <cmath>
#include <string>
using namespace std;
typedef signed long long LL;

#define FOR(x,to) for(int x=0;x<(to);x++)
#define ITR(x, arr) for(auto x = arr.begin(); x!= arr.end(); x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,-1,sizeof(a))
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//----------------------------------------------------------

map<string, char> m;

int main()
{
	FAST;

	m[".-"] = 'A';
	m["-..."] = 'B';
	m["-.-."] = 'C';
	m["-.."] = 'D';
	m["."] = 'E';
	m["..-."] = 'F';
	m["--."] = 'G';
	m["...."] = 'H';
	m[".."] = 'I';
	m[".---"] = 'J';
	m["-.-"] = 'K';
	m[".-.."] = 'L';
	m["--"] = 'M';
	m["-."] = 'N';
	m["---"] = 'O';
	m[".--."] = 'P';
	m["--.-"] = 'Q';
	m[".-."] = 'R';
	m["..."] = 'S';
	m["-"] = 'T';
	m["..-"] = 'U';
	m["...-"] = 'V';
	m[".--"] = 'W';
	m["-..-"] = 'X';
	m["-.--"] = 'Y';
	m["--.."] = 'Z';

	int t, cnt = 0;
	cin >> t;
	while (t--)
	{
		cnt++;
		string s, ans;
		for (int i = 0; i < 5; i++)
		{
			cin >> s;
			ans += m[s];
		}
		cout << "Case " << cnt << ": " << ans << "\n";
	}
}