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

//-----------------------
#include<stdio.h>
#define max(a,b) ((a)>=(b)?(a):(b))
int main()
{
    int a[1000];
    int i, j, k, n, m, t, cnt, ans, max, min, lmax, rmax;
    for (i = 0; i < 10; i++)
    {
        ans = 0;
        scanf("%d", &n);
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[j]);
        }
        for (j = 2; j < n - 2; j++)
        {
            lmax = 0;
            rmax = 0;
            for (k = 1; k < 3; k++)
            {
                if (lmax < a[j - k])
                    lmax = a[j - k];
                if (rmax < a[j + k])
                    rmax = a[j + k];
            }
            if (a[j] > max(lmax, rmax))
                ans += a[j] - max(lmax, rmax);
        }
        printf("#%d %d\n", i + 1, ans);
    }
}