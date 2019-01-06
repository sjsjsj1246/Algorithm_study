#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> T(n + 2);
    vector<int> W(n + 1, -1);
    T[1] = 1;
    int t;
    cin >> t;
    while (t--)
    {
        int q;
        cin >> q;
        if (W[q] != -1)
            cout << W[q] << "\n";
        for (int k = 1; k <= n; k++)
        {
            
        }
    }
}