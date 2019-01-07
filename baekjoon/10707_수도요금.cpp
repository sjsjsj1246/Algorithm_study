#include <iostream>
using namespace std;

int main()
{
    int arr[5];
    for(int i=0;i<5;i++) cin >> arr[i];
    int x, y;
    x = arr[0]*arr[4];
    if(arr[4]>arr[2]) y = arr[1] + (arr[4]-arr[2])*arr[3];
    else y = arr[1];
    cout << ((x < y) ? x : y);
}