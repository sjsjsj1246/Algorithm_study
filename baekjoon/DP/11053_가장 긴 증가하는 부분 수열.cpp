#include <iostream>
using namespace std;
typedef long long int LL;

int main()
{
    LL dp[110] = {0, 1, 1, 1};
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int a = 3; a <= n; a++)
        {
            dp[a] = dp[a - 2] + dp[a - 3];
        }
        cout << dp[n] << "\n";
    }
}