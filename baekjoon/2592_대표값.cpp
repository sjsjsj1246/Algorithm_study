#include <iostream>
#include <cstring>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//-------------------------------------------------------

int arr[10], check[10], sum = 0, Max = 0, pos = 0;

int main(int argc, char** argv) 
{
	memset(check, 1, sizeof(check));
	for (int i = 0; i < 10; i++) cin >> arr[i], sum += arr[i];
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < i; j++)
			if (arr[j] == arr[i]) check[i]++, check[j]++;
	for (int i = 0; i < 10; i++) if (Max < check[i]) Max = check[i], pos = i;
	cout << sum / 10 << "\n" << arr[pos];
}