#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(ww, aa, nn) for(int ww=(aa);ww<(nn);++ww)
#define ALL(aa) (aa).begin(),(aa).end()
#define CASES(tt) int aa; cin >> aa; for(int tt=1;tt<=aa;tt++)
#define MOD 1000000007
#define INF 987654321
typedef long long ll;
using namespace std;

struct State{
	int value;
	char color;
};

int n, ans;
int efficacy[10][4][4][4];
char element[10][4][4][4];
bool visited[10];

vector<vector<State>> Map(5, vector<State>(5));

// 입력 배열을 90도로 3번 회전하여 각각을 저장하는 함수
void rotateArr(int type, int dir) {
	// 90 도 회전
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			efficacy[type][dir][i][j] = efficacy[type][dir - 1][3 - j][i];
			element[type][dir][i][j] = element[type][dir - 1][3 - j][i];
		}
	}
}

// 폭탄의 최대 품질을 구하는 함수
int getQuality(vector<vector<State>> v) {
	int ret = 0;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			State temp = v[i][j];
			if (temp.color == 'R') ret += 7 * temp.value;
			else if (temp.color == 'B') ret += 5 * temp.value;
			else if (temp.color == 'G') ret += 3 * temp.value;
			else if (temp.color == 'Y') ret += 2 * temp.value;
		}
	}

	return ret;
}

// 가마에 재료의 종류, 방향에 따라 재료를 놓는 함수
vector<vector<State>> putMaterial(vector<vector<State>> v, int row, int col, int type, int dir) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			// 효능
			v[row + i][col + j].value += efficacy[type][dir][i][j];

			if (v[row + i][col + j].value < 0)
				v[row + i][col + j].value = 0;
			else if (v[row + i][col + j].value > 9)
				v[row + i][col + j].value = 9;

			// 원소
			if (element[type][dir][i][j] != 'W') {
				v[row + i][col + j].color = element[type][dir][i][j];
			}
		}
	}

	return v;
}

void dfs(vector<vector<State>> v, int cnt) {
	// 재료 3개를 모두 선택한 경우
	if (cnt == 3) {
		ans = max(ans, getQuality(v));
		return;
	}

	// dfs
	for (int t = 0; t < n; t++) {
		if (!visited[t]) {
			visited[t] = true;

			// (0,0) (0,1) (1,0) (1,1)
			// 4 좌표에 대해 재료 배치 가능
			for (int i = 0; i <= 1; i++) {
				for (int j = 0; j <= 1; j++) {
					// 원래방향, 시계방향, 반시계방향
					for (int d = 0; d < 4; d++) {
						vector<vector<State>> tmp = putMaterial(v, i, j, t, d);

						dfs(tmp, cnt + 1);
					}
				}
			}

			visited[t] = false;
		}
	}
}

int main() {
	FAST;

	cin >> n;
	for (int t = 0; t < n; t++) {
		// 효능 입력
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cin >> efficacy[t][0][i][j];
			}
		}

		// 원소 입력
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cin >> element[t][0][i][j];
			}
		}

		// 입력받은 효능, 원소 회전
		for (int d = 1; d <= 3; d++) {
			rotateArr(t, d);
		}
	}

	// 초기화
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			Map[i][j] = { 0, 'W' };
		}
	}
	ans = -INF;

	dfs(Map, 0);

	cout << ans;
}