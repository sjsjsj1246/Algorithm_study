#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		string temp; cin >> temp;
		cout << ((temp.back() - '0') % 2 ? "odd\n" : "even\n");
	}
}