#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	string s;
	cin >> s;
	map<string, double> map;
	map.insert(make_pair("A+", 4.3));
	map.insert(make_pair("A0", 4.0));
	map.insert(make_pair("A-", 3.7));
	map.insert(make_pair("B+", 3.3));
	map.insert(make_pair("B0", 3.0));
	map.insert(make_pair("B-", 2.7));
	map.insert(make_pair("C+", 2.3));
	map.insert(make_pair("C0", 2.0));
	map.insert(make_pair("C-", 1.7));
	map.insert(make_pair("D+", 1.3));
	map.insert(make_pair("D0", 1.0));
	map.insert(make_pair("D-", 0.7));
	map.insert(make_pair("F", 0.0));
	printf("%.1f", map.find(s)->second);
}