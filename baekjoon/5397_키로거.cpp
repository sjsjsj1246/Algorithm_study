#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#define CASES(t) int t; cin >> t; while(t--)
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD 1000000007
#define INF 987654321
#define FOR(x,to) for(int x=0;x<(to);x++)
#define ALL(a) (a.begin()),(a.end())
using namespace std;

int main()
{
	FAST;
	CASES(t)
	{
		string L; cin >> L;
        list<char> ans;
        list<char>::iterator ans_iter = ans.begin();
        int L_len = L.size(), L_idx = 0;
 
        while (L_idx < L_len) {
            switch (L[L_idx]) {
            case '<':
                if (ans_iter != ans.begin()) ans_iter--;
                break;
            case '>':
                if (ans_iter != ans.end()) ans_iter++;
                break;
            case '-':
                if (ans_iter != ans.begin())  ans.erase((--ans_iter)++);
                break;
            default:
                ans.insert(ans_iter, L[L_idx]);
                break;
            }
            L_idx++;
        }
        for (auto x : ans) cout << x;
        cout << "\n";
	}
}