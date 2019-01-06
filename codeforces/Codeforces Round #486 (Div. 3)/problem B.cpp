#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	char S[100][101];
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> S[i];
	for (int i = 0; i < n - 1; i++)
	{
		char temp[101];
		for (int j = i + 1; j < n; j++)
		{
			if (strlen(S[i]) > strlen(S[j]))
			{
				strcpy(temp, S[i]);
				strcpy(S[i], S[j]);
				strcpy(S[j], temp);
			}
		}
	}
	bool flag = 1;
	for (int i = 0; i < n - 1; i++)
	{
		string s1 = S[i];
		string s2 = S[i + 1];
		if (!strstr(s2.c_str(), s1.c_str()))
		{
			printf("NO");
			return 0;
		}
	}
	printf("YES\n");
	for (int i = 0; i < n; i++)
		cout << S[i] << "\n";
}