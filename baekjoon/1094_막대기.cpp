#include <iostream>
using namespace std;

int main()
{
    int x, res = 0;
    cin >> x;
    for (int i = 64; i > 0 && x > 0; i /= 2)
    {
        if (i <= x)
        {
            res++;
            x = x - i;
        }
    }
    cout << res;
}