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

	// �켱����ť ���۽ð�
	begin = clock();
	priority_queue<int> pq;
	FOR(i, N) pq.push(-(rand() % N));
	while (!pq.empty()) cout << -pq.top() << " ", pq.pop();
	end = clock();
	cout << "\n" << N << "�� �ݺ� ����ð� : " << end - begin << "\n\n";

	// multiset ���۽ð�
	begin = clock();
	multiset<int> s;
	FOR(i, N) s.insert(rand() % N);
	for(auto i = s.begin();i!=s.end();) cout << *i << " ", i = s.erase(i);
	end = clock();
	cout << "\n" << N << "�� �ݺ� ����ð� : " << end - begin << "\n\n";
}