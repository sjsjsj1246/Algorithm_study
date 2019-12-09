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
    int n, key=0;
    cin >> n;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            key = i;
            break;
        }
    }
    if(key==0) cout << n-1;
    else cout << n - n/key;
}