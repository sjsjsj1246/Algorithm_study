#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); j++)
		{
			string substring = s.substr(j, s.length());
			if (substring == "a") { s = s.substr(0, j) + "as"; break; }
			else if (substring == "i" || substring == "y") { s = s.substr(0, j) + "ios"; break; }
			else if (substring == "l") { s = s.substr(0, j) + "les"; break; }
			else if (substring == "n" || substring == "ne") { s = s.substr(0, j) + "anes"; break; }
			else if (substring == "o") { s = s.substr(0, j) + "os"; break; }
			else if (substring == "r") { s = s.substr(0, j) + "res"; break; }
			else if (substring == "t") { s = s.substr(0, j) + "tas"; break; }
			else if (substring == "u") { s = s.substr(0, j) + "us"; break; }
			else if (substring == "v") { s = s.substr(0, j) + "ves"; break; }
			else if (substring == "w") { s = s.substr(0, j) + "was"; break; }
			if (j == s.length() - 1) { s += "us"; break; }
		}
		cout << s << "\n";
	}
}