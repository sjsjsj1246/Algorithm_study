#pragma region preset_for_PS
// need
#include <iostream>
#include <algorithm>
// data structure
#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <deque>
#include <array>
// stream
#include <istream>
#include <sstream>
#include <ostream>
// etc
#include <cstdlib>
#include <cmath>
#include <functional>
#include <chrono>
#include <random>
#include <cstring>
using namespace std;
typedef long long int ll;
// input
#define ALL(a) (a).begin(),(a).end()
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,-1,sizeof(a))
#define CASES(t) int t; cin >> t; while(t--)
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD 1000000007
#define INF 987654321
#define SUB(a) cout << a << "\n";
// output
#define SP << " "
#define BR << "\n"
#define SPBR(i, n) <<(i + 1 == n ? '\n' : ' ');
#define SHOWVECTOR(v) {std::cerr << #v << "\t:";for(const auto& xxx : v){std::cerr << xxx << " ";}std::cerr << "\n";}
#define SHOWVECTOR2(v) {std::cerr << #v << "\t:\n";for(const auto& xxx : v){for(const auto& yyy : xxx){std::cerr << yyy << " ";}std::cerr << "\n";}}
#define SHOWQUEUE(a) {auto tmp(a);std::cerr << #a << "\t:";while(!tmp.empty()){std::cerr << tmp.front() << " ";tmp.pop();}std::cerr << "\n";}
// utility
#define FOR(w, a, n) for(int w=(a);w<(n);++w)
#define RFOR(w, a, n) for(int w=(n)-1;w>=(a);--w)
#define ITR(it, vec) for(auto it = vec.begin(); it!= vec.end(); it++)
#define RITR(it, vec) for(auto it = vec.rbegin(); it!= vec.rend(); it++)
template<typename S, typename T>
std::ostream& operator<<(std::ostream& os, std::pair<S, T> p) {
	os << "(" << p.first << ", " << p.second << ")"; return os;
}
#pragma endregion

#define MAX_NM 500
int N, M;
int answer = -1;

vector<vector<int>> matrix(MAX_NM);
vector<pair<int, int>> shape_1 = { { 0,1 },{ 0,2 },{ 0,3 } };
vector<pair<int, int>> shape_2 = { { 0,1 },{ 1,0 },{ 1,1 } };
vector<pair<int, int>> shape_3 = { { 1,0 },{ 2,0 },{ 2,1 } };
vector<pair<int, int>> shape_4 = { { 1,0 },{ 1,1 },{ 2,1 } };
vector<pair<int, int>> shape_5 = { { 0,1 },{ 0,2 },{ 1,1 } };
vector<vector<pair<int, int>>> shape_vec = { shape_1 , shape_2 , shape_3 , shape_4 , shape_5 };


// 도형 회전 
vector<pair<int, int>> rotate(int degree, vector<pair<int, int>> shape) {
	vector<pair<int, int>> _shape = shape;
	int shape_size = _shape.size();

	switch (degree) {
	case 0:
		break;
	case 90:
		for (int shp_idx = 0; shp_idx < shape_size; shp_idx++)
			_shape.at(shp_idx) = { ((0)*_shape.at(shp_idx).first + (-1)* _shape.at(shp_idx).second),
											((1)*_shape.at(shp_idx).first + (0)* _shape.at(shp_idx).second) };
		break;
	case 180:
		for (int shp_idx = 0; shp_idx < shape_size; shp_idx++)
			_shape.at(shp_idx) = { ((-1)*_shape.at(shp_idx).first + (0)*_shape.at(shp_idx).second),
											((0)*_shape.at(shp_idx).first + (-1)*_shape.at(shp_idx).second) };
		break;
	case 270:
		for (int shp_idx = 0; shp_idx < shape_size; shp_idx++)
			_shape.at(shp_idx) = { ((0)*_shape.at(shp_idx).first + (1)*_shape.at(shp_idx).second),
											((-1)*_shape.at(shp_idx).first + (0)* _shape.at(shp_idx).second) };
		break;
	default:
		printf("error");
		exit(9);
		break;
	}

	return _shape;
}

// 도형 뒤집기 
vector<pair<int, int>> flip(vector<pair<int, int>> shape) {
	vector<pair<int, int>> _shape = shape;
	int shape_size = _shape.size();

	for (int shp_idx = 0; shp_idx < shape_size; shp_idx++)
		_shape.at(shp_idx) = { -(_shape.at(shp_idx).first), (_shape.at(shp_idx).second) };

	return _shape;
}

// 합 구하기
void shape_sum(vector<pair<int, int>> shape, int row, int col) {
	int sum = matrix.at(row).at(col);
	int shape_size = shape.size();

	for (int shp_idx = 0; shp_idx < shape_size; shp_idx++) {
		int now_row = row + shape.at(shp_idx).first;
		int now_col = col + shape.at(shp_idx).second;

		// 인덱스 범위 체크한다. 
		if (now_row < 0 || now_row > N - 1)  return;
		if (now_col < 0 || now_col > M - 1) return;

		// sum 에 추가 
		sum += matrix.at(now_row).at(now_col);
	}

	if (sum > answer) answer = sum;
}

int main() {
	cin >> N >> M;

	// 값 입력받기 
	for (int row_idx = 0; row_idx < N; row_idx++) {
		for (int col_idx = 0; col_idx < M; col_idx++) {
			int sub;
			scanf("%d", &sub);
			matrix.at(row_idx).push_back(sub);
		}
	}

	// 도형 하나하나 비교해가면서 확인해보기 
	for (int row_idx = 0; row_idx < N; row_idx++) {
		for (int col_idx = 0; col_idx < M; col_idx++) {

			// 한 위치에서 5개의 도형을 확인해야 한다. 
			int shape_vec_size = shape_vec.size();
			for (int shp_idx = 0; shp_idx < shape_vec_size; shp_idx++) {

				// flip 하기 전 
				for (int chg_idx = 0; chg_idx < 4; chg_idx++) {
					vector<pair<int, int>> _shape = rotate(chg_idx * 90, shape_vec.at(shp_idx));
					shape_sum(_shape, row_idx, col_idx);
				}

				// flip 한 후  
				for (int chg_idx = 0; chg_idx < 4; chg_idx++) {
					vector<pair<int, int>> _shape = flip(shape_vec.at(shp_idx));
					_shape = rotate(chg_idx * 90, _shape);
					shape_sum(_shape, row_idx, col_idx);
				}

			}

		}
	}

	cout << answer;

	return 0;
}
