#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr1(10), arr2(10);
    for(int i=0;i<10;i++) cin >> arr1[i];
    for(int i=0;i<10;i++) cin >> arr2[i];
    sort(arr1.begin(),arr1.end(),greater<int>());
    sort(arr2.begin(),arr2.end(),greater<int>());
    cout << arr1[0]+arr1[1]+arr1[2] << " " << arr2[0]+arr2[1]+arr2[2];
}