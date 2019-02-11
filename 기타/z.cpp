#include <iostream>
#include <cstdio>
#include <functional>
#include <set>
#include <queue>
#include <ctime>
using namespace std;
#define FOR(x,to) for(int x=0;x<(to);x++)
const int N = 1000;

int main()
{
	int cnt = 0;
	srand(time(NULL));
	clock_t begin, end;

	// 우선순위큐 동작시간
	begin = clock();
	priority_queue<int> pq;
	FOR(i, N) pq.push(-(rand() % N));
	while (!pq.empty()) cout << -pq.top() << " ", pq.pop();
	end = clock();
	cout << "\n" << N << "번 반복 수행시간 : " << end - begin << "\n\n";

	// multiset 동작시간
	begin = clock();
	multiset<int> s;
	FOR(i, N) s.insert(rand() % N);
	for(auto i = s.begin();i!=s.end();) cout << *i << " ", i = s.erase(i);
	end = clock();
	cout << "\n" << N << "번 반복 수행시간 : " << end - begin << "\n\n";
}