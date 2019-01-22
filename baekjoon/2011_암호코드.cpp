#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD 1000000
using namespace std;

int dp[5001] = { 1, 1, };

int main()
{
	string s;
	cin >> s;
	int len = s.length();
	for (int i = 2; i <= len; i++)
	{
		if(s[i-1] > '0')
			dp[i] = dp[i - 1];
		int temp = (s[i - 2]-'0') * 10 + (s[i - 1]-'0');
		if (temp>=10 && temp <= 26)
			dp[i] = (dp[i] + dp[i - 2]) % MOD;
	}
	cout << (s == "0" ? 0 : dp[len]);
}