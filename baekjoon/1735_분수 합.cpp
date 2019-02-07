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
typedef signed long long LL;

#define FOR(x,to) for(int x=0;x<(to);x++)
#define ITR(x, arr) for(auto x = arr.begin(); x!= arr.end(); x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,-1,sizeof(a))
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//-------------------------------------------------------
//��Ŭ���� ȣ���� (�ִ�����, �ּҰ���� ���ϱ� ������ ����)

int gcd(int a, int b) //�ִ����� ��ͷ� ��Ŭ���� ȣ���� ����
{
	if (b == 0)
		return a;
	gcd(b, a%b);
}

int lcm(int a, int b) //�ּҰ����
{
	return (a*b) / gcd(a, b);
}

int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int numer = a * d + b * c, denom = b*d;
	int mod = gcd(numer, denom);
	numer /= mod;
	denom /= mod;
	cout << numer << " " << denom;
	return 0;
}