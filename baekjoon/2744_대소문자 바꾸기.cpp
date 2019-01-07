#include <iostream>
#include <string>
using namespace std;
char A[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char a[] = "abcdefghijklmnopqrstuvwxyz";

int main()
{
	string s;
	cin >> s;
	int len = s.size();
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (s[i] == A[j]) s[i] = a[j];
			else if (s[i] == a[j]) s[i] = A[j];
		}
	}
	cout << s;
}