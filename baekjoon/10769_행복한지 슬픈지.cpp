#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MOD 1000000
#define CASES(t) int t;cin>>t;while(t--)
typedef long long ll;
using namespace std;

int main()
{
	FAST;
	string s;
	getline(cin, s);

	int happy = 0, unhappy = 0;
	
	string h = s;
	while(h.find(":-)") != string::npos)
	{
		happy++;
		h = h.substr(h.find(":-)") + 3, h.length());
	}

	string uh = s;
	while (uh.find(":-(") != string::npos)
	{
		unhappy++;
		uh = uh.substr(uh.find(":-(") + 3, uh.length());
	}
	
	if (happy == 0 && unhappy == 0) cout << "none";
	else if (happy > unhappy) cout << "happy";
	else if (happy < unhappy) cout << "sad";
	else if (happy == unhappy) cout << "unsure";

}