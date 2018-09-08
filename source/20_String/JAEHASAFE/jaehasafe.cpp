#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> getPartialMatch(const string& N)
{
	int m = N.size();
	vector<int> pi(m, 0);
	int begin = 1, matched = 0;
	while (begin + matched < m)
	{
		if (N[begin + matched] == N[matched])
		{
			matched++;
			pi[begin + matched - 1] = matched;
		}
		else
		{
			if (matched == 0) begin++;
			else
			{
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return pi;
}

vector<int> kmpSearch(const string& H, const string &N) {
	int n = H.size(), m = N.size();
	vector<int> ret;
	vector<int> pi = getPartialMatch(N);
	int begin = 0, matched = 0;
	while (begin <= n - m) {
		if (matched < m && H[begin + matched] == N[matched]) {
			++matched;
			if (matched == m)
				ret.push_back(begin);
		}
		else {
			if (matched == 0)
				++begin;
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return ret;
}

int main()
{
	int c; cin >> c;
	while (c--)
	{
		int n; cin >> n;
		int ret = 0;
		string base; cin >> base;
		int start = base.size();
		int size = base.size();
		base = base + base;
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			string input; cin >> input;
			vector<int> pos = kmpSearch(base, input);
			int  temp;
			int min = 987654321;
			int sub;
			for (vector<int>::iterator it = pos.begin(); it != pos.end(); it++)
			{
				temp = start - *it;
				if (cnt % 2) temp = -temp;
				if (temp < 0) temp += size;
				if (min>temp)
				{
					min = temp;
					sub = *it;
				}
			}
			cnt++;
			ret += min;
			start = sub;
		}
		cout << ret << "\n";
	}
}