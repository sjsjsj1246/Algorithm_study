#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void postPrint(vector<int> pre, vector<int> mid)
{
	if (pre.empty()) return;
	int root = pre[0];
	int leftSize = find(mid.begin(), mid.end(), root) - mid.begin();
	int rightSize = mid.size() - leftSize - 1;
	vector<int> nextLeftPre(pre.begin() + 1, pre.begin() + leftSize + 1);
	vector<int> nextLeftMid(mid.begin(), mid.begin() + leftSize);
	vector<int> nextRightPre(pre.begin() + leftSize + 1, pre.begin() + pre.size());
	vector<int> nextRightMid(mid.begin() + leftSize + 1, mid.begin() + mid.size());
	postPrint(nextLeftPre, nextLeftMid);
	postPrint(nextRightPre, nextRightMid);
	printf("%d ", root); //루트 출력
}

int main()
{
	int c; cin >> c;
	while (c--)
	{
		int n; cin >> n;
		vector<int> pre(n), mid(n);
		for (int i = 0; i < n; i++) cin >> pre[i];
		for (int i = 0; i < n; i++) cin >> mid[i];
		postPrint(pre, mid); puts("");
	}
}