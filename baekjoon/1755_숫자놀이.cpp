#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MOD 1000000
using namespace std;

map<char, string> cs;

bool cmp(char &a, char &b)
{

}

int main()
{
	FAST;
	int a, b;
	cin >> a >> b;

	cs['1'] = "one";
	cs['2'] = "two";
	cs['3'] = "three";
	cs['4'] = "four";
	cs['5'] = "five";
	cs['6'] = "six";
	cs['7'] = "seven";
	cs['8'] = "eight";
	cs['9'] = "nine";
	cs['0'] = "zero";

	vector<pair<string,int>> arr;
	for (int i = a; i <= b; i++)
	{
		string s, res;
		s = to_string(i);
		for (auto c : s)
		{
			res += cs[c];
		}
		arr.push_back({ res,i });
	}

	sort(arr.begin(), arr.end());
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i].second << " ";
		if (i != 0 && (i + 1) % 10 == 0) cout << "\n";
	}
}