#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string c;
int L, C;

void func(string s, int i, int a)
{
	if (s.length() == L)
	{
		if(i >= 1 && a >= 2)
			cout << s << "\n";
		return;
	}
	for (char x : c)
	{
		if (s.length() >= 1 && s.back() >= x) continue;
		int tempi = 0, tempa = 0;
		if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') tempi++;
		else tempa++;
		func(s + x, i + tempi, a + tempa);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> L >> C;
	for (int i = 0; i < C; i++)
	{
		char temp;
		cin >> temp;
		c.push_back(temp);
	}
	sort(c.begin(), c.end());
	func("", 0, 0);
	return 0;
}