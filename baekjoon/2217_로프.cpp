#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> Rope(n);

    for (int i = 0; i < n; i++)
        cin >> Rope[i];

    int max = 0;
    sort(Rope.begin(), Rope.end(), greater<int>());

    for (int i = 0; i < n; i++)
    {
        if (max < Rope[i] * (i + 1))
            max = Rope[i] * (i + 1);
    }

    cout << max;
}