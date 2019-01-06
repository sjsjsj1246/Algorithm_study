#include <iostream>
using namespace std;
 
int main() {
    int n,r=0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = i; i*j <= n; j++)
            r++;
    cout << r;
    return 0;
}