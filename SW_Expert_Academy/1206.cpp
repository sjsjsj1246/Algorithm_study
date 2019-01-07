#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cstring>
#define INF 987654321
#define fast ios::sync_with_stdio(false); cin.tie(0);
typedef long long int LL;
using namespace std;
 
int dx[] = { -2,-1,1,2 };
 
int main()
{
    fast;
    int t = 10;
    while (t--)
    {
        int n, sum = 0;
        cin >> n;
        vector<int> buildings(n);
        for (int i = 0; i < n; i++) cin >> buildings[i];
        for (int i = 0; i < n; i++)
        {
            int min = 255;
            bool flag = 1;
            for (int j = 0; j < 4; j++)
            {
                if (i + dx[j] < 0 || i + dx[j] >= n) continue;
                if (buildings[i + dx[j]] >= buildings[i])
                {
                    flag = 0;
                    break;
                }
                int ans = buildings[i] - buildings[i + dx[j]];
                if (min > ans) min = ans;
            }
            if (flag) sum += min;
        }
        cout << "#" << 10 - t << " " << sum << "\n";
    }
}