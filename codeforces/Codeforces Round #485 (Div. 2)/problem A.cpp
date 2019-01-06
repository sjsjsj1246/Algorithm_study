#include <iostream>
#include <cstring>
using namespace std;

char stone[6][10] = { "Power","Time","Space","Soul","Reality","Mind" };
char color[6][10] = { "purple","green","blue","orange","red","yellow" };
bool check[6];

int main()
{
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		char temp[10]; cin >> temp;
		for (int j = 0; j < 6; j++)
		{	
			if (!strcmp(temp, color[j])) check[j] = 1;
		}
	}
	int count = 0;
	for (int i = 0; i < 6; i++)
	{
		if (!check[i])
			count++;
	}
	cout << count << "\n";
	for (int i = 0; i < 6; i++)
	{
		if (!check[i])
			cout << stone[i] << "\n";
	}
}