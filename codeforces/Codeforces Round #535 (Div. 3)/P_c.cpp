#include <iostream>
#include <cstring>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <string>
using namespace std;
typedef signed long long ll;

#define FOR(x,to) for(int x=0;x<(to);x++)
#define ITR(x, arr) for(auto x = arr.begin(); x!= arr.end(); x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,-1,sizeof(a))
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//-------------------------------------------------------

/**
 * 모든 가능한 문자열에 대해 BGRBGRBG...의 순서로 만들때 바꿔야 하는 램프의 최솟값을 구하려함
 * 그렇게 하면 자동으로 문제의 조건이 맞춰짐, GRB GBR.. 뭐로 하든 상관없음
 */

int main() 
{
	int n;
	string s;

	cin >> n >> s;
	string T = "BGR", R;
	int mi = 1 << 20;
	do {
		int dif = 0;
		FOR(i, n) {
			if (s[i] != T[i % 3]) dif++;
		}
		if (dif<mi) {
			mi = dif;
			R = "";
			FOR(i, n) R.push_back(T[i % 3]);
		}
	} while (next_permutation(ALL(T)));
	/*
	https://twpower.github.io/82-next_permutation-and-prev_permutation
	next_permutation : 주어진 배열의 순열을 다음 순서의 순열로 바꾸고 true 반환
	*/
	cout << mi << endl;
	cout << R << endl;

	return 0;
}