#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <functional>
using namespace std;

// 나는 굳이 어려운 길을 선택한 것 같다...

size_t split(const string &txt, map<string, int> &strs, char ch)
{
	size_t pos = txt.find(ch);
	size_t initialPos = 0;
	strs.clear();

	while (pos != std::string::npos) 
	{
		strs[txt.substr(initialPos, pos - initialPos)]++;
		initialPos = pos + 1;

		pos = txt.find(ch, initialPos);
	}

	strs[txt.substr(initialPos, std::min(pos, txt.size()) - initialPos + 1)]++;

	return strs.size();
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		string s;
		getline(cin, s);
		getline(cin, s);
		map<string, int> v;
		split(s, v, ' ');
		int max_score = 0;
		string max_pos = "";
		for (auto x : v)
		{
			if (max_score <= x.second)
			{
				max_score = x.second;
				max_pos = x.first;
			}
		}
		cout << "#" << n << " " << max_pos << "\n";
	}

}

//---------------------------------------------

// 문제의 입력이 이상해서 좀 돌아간것같다. 그런데 이사람의 입력 방법이 이상하다.. 뭐지

#include<stdio.h>
 
int main(void)
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int num, n, hold;
        scanf("%d", &num);
 
        int max = 0;
        int arr[101] = { 0 };
        for (int i = 0; i < 1000; i++)
        {
            scanf("%d", &n);
            arr[n]++;
            if (max <= arr[n])
            {
                max = arr[n];
                hold = n;
            }
        }
 
        printf("#%d %d\n", num, hold);
    }
}