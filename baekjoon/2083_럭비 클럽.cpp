#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	while (1)
	{
		string s;
		int a, b;
		cin >> s >> a >> b;
		if (s == "#"&&a == 0 && b == 0) return 0;
		if (a > 17 || b >= 80) cout << s << " " << "Senior\n";
		else cout << s << " " << "Junior\n";
	}
}