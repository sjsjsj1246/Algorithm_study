#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <cstring>
using namespace std;

int prize_1[] = { 0,500,300,300,200,200,200,50,50,50,50,30,30,30,30,30,10,10,10,10,10,10 };
int prize_2[] = { 0,512,256,256,128,128,128,128,64,64,64,64,64,64,64,64,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32, };

int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int a, b, prize_sum = 0;
		cin >> a >> b;
		if (a <= 21) prize_sum += prize_1[a];
		if (b <= 31) prize_sum += prize_2[b];
		cout << prize_sum * 10000 << "\n";
	}
}