#include <iostream>
#include <queue>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	map<string, pair<int,long long>> i;
	i["black"] = { 0,1 };
	i["brown"] = { 1,10 };
	i["red"] = { 2,100 };
	i["orange"] = { 3,1000 };
	i["yellow"] = { 4,10000 };
	i["green"] = { 5,100000 };
	i["blue"] = { 6,1000000 };
	i["violet"] = { 7,10000000 };
	i["grey"] = { 8,100000000 };
	i["white"] = { 9,1000000000 };
	string a, b, c;
	cin >> a >> b >> c;
	cout << (i[a].first * 10 + i[b].first)*i[c].second;
}