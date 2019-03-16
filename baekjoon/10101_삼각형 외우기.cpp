#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <functional>
using namespace std;

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int sum = 0, temp;
	set<int> s;
	for (int i = 0; i < 3; i++) cin >> temp, sum += temp, s.insert(temp);
	if (sum != 180) cout << "Error";
	else if (s.size() == 1) cout << "Equilateral";
	else if (s.size() == 2) cout << "Isosceles";
	else if (s.size() == 3) cout << "Scalene";
}