#include <iostream>
using namespace std;

int main()
{
	int n; cin >> n;
	char ins[11]; cin >> ins;
	int w = 0;
	bool p = 0;
	int kill = 5;
	for (int i = 0; i < n; i++)
	{
		if (ins[i] == 'P')
		{
			p ^= 1;
			if (w == 0)
			{
				if (p == 1) kill = 1;
				if (p == 0) kill = 5;
			}
			if (w == 1)
				kill = 6;
		}
		if (ins[i] == 'W') w++;
	}
	if (w >= 2) cout << kill;
	else cout << 0;
}