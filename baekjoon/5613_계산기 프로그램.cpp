#include <iostream>
using namespace std;

int main()
{
	int res = 0, temp = 0;
	char c;
	cin >> res;
	getchar();
	c = getchar();
	while (c != '=')
	{
		if (c == '+')
		{
			getchar();
			cin >> temp;
			res += temp;
		}
		else if (c == '-') 
		{
			getchar();
			cin >> temp;
			res -= temp;
		}
		else if (c == '*')
		{
			getchar();
			cin >> temp;
			res *= temp;
		}
		else if (c == '/') 
		{
			getchar();
			cin >> temp;
			res /= temp;
		}
		getchar();
		c = getchar();
	}
	cout << res;
}