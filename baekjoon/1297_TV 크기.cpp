#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double dia, wr, hr;
    cin >> dia >> wr >> hr;
    double ratio = sqrt(wr * wr + hr * hr);
    cout << (int)(dia * wr / ratio) << " " << (int)(dia * hr / ratio);
}