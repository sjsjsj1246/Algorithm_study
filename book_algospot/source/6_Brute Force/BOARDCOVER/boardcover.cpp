#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cstring>
#define INF 987654321
#define fast ios::sync_with_stdio(false); cin.tie(0);
typedef long long int LL;
using namespace std;

const int coverType[4][3][2] = 
{
	{{0,0},{1,0},{0,1}},
	{{0,0},{0,1},{1,1}},
	{{0,0},{1,0},{1,1}},
	{{0,0},{1,0},{1,-1}}
};

bool set(vector<vector<int>>& board, int y, int x, int type, int delta)
{
	bool ok = true;
	for (int i = 0; i < 3; i++)
	{
		const int ny = y + coverType[type][i][0];
		const int nx = x + coverType[type][i][1];
		if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board[0].size())
			ok = false;
		else if ((board[ny][nx] += delta) > 1)
			ok = false;
	}
	return ok;
}

int cover(vector<vector<int>>& board)
{
	int y = -1, x = -1;
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[i].size(); j++)
		{
			if (board[i][j] == 0)
			{
				y = i;
				x = j;
				break;
			}
		}
		if (y != -1) break;
	}
	if (y == -1) return 1;
	int ret = 0;
	for (int type = 0; type < 4; type++)
	{
		if (set(board, y, x, type, 1))
			ret += cover(board);
		set(board, y, x, type, -1);
	}
	return ret;
}

int main()
{
	fast;
	int t; cin >> t;
	while (t--)
	{
		int h, w;
		cin >> h >> w;
		vector<vector<int>> board;
		vector<int> temp(w);
		for (int i = 0; i < h; i++) board.push_back(temp);
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				char temp;
				cin >> temp;
				board[i][j] = (temp == '#' ? 1 : 0);
			}
		}
		cout << cover(board) << "\n";
	}
}