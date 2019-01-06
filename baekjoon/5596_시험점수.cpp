#include <iostream>
using namespace std;

int main()
{
    int arr[4];
    int sum1 = 0, sum2 = 0;
    for(int i=0;i<4;i++) 
    {
        cin >> arr[i];
        sum1 += arr[i];
    }
    for(int i=0;i<4;i++) 
    {
        cin >> arr[i];
        sum2 += arr[i];
    }
    cout << ((sum1 >= sum2) ? sum1 : sum2);
}