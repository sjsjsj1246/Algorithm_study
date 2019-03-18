#include <iostram>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Segment Tree : 구간 트리
 * 
 * 저장된 자료들을 적절히 전처리해 그들에 대한 질의들을 빠르게 대답할 수 있도록 합니다.
 * 구간 트리는 일차원 배열의 특정 구간에 대한 질문을 빠르게 대답하는 데 사용된다.
 * 
 * 구간트리의 기본적인 아이디어는 주어진 배열의 구간들을 표현하는 이진 트리륾 만드는 것이다.
 * 루트 노드는 구간의 전체를 표현하며, 한 트리의 왼쪽 자식과 오른쪽 자식은 해당 구간의 왼쪽 반과 오른쪽 반을 표현한다.
 * 길이가 1인 구간을 표현하는 노드들을 구간트리의 리프가 된다.
 * 
 * 비교적 꽉 찬 이진트리, 이는 포인터로 연결된 객체로 표현하기 보다 배열로 구현하는 것이 더 메모리를 절약할 수 있다. 
 * 검색 logn
 * 
 * 
 * - 구간 트리의 표현
 * 루트 노드를 배열의 1번 원소로, 노드 i의 왼쪽 자손 = 2*i, 오른쪽 자손 = 2*i+1
 * 부모의 인덱스 i/2
 * 
 * 배열의 크기는 n을 2의 거듭제곱으로 올림한 뒤 2를 곱하면 된다. n=6이면 크기는 8*2=16
 * 귀찮으면 그냥 4*n
 * 
 * - 구간 트리의 초기화
 * 배열 arry가 주어질 때, 각 노드마다 해당 구간의 최소치를 계산하는 init() 구현
 * 
 * - 구간 트리의 질의 처리
 * query() 함수 정의
 * query(left, right, node, nodeLeft, nodeRight)
 * node가 표현하는 범위 [nodeLeft, nodeRight]와 우리가 최소치를 찾기 원하는 구간 [left, right]
 * 의 교집합의 최소 원소를 반환한다.
 * 
 * 루트 1번 노드는 배열 전체 범위인 [0, n-1]을 표현하기 때문에, [i, j]구간의 최소치는
 * query(i, j, 1, 0, n-1)로 구할 수 있다.
 * 
 * -- 교집합이 공집합인 경우 : 반환값이 무시되도록 아주 큰 값을 반환하도록 한다.
 * -- 교집합이 [nodeLeft, nodeRight]인 경운 : [left, right]가 노드가 표현하는 집합을
 * 완전히 포함하는 경우이다. 미리 계산해둔 최소치륿 반환하면 된다.
 * -- 이 외의 모든 경우 : 두개의 자손 노드에 대해 query()를 재귀호출 한 뒤, 이 두 값중 더 작은
 * 값을 택해 반환한다.
 * 
 * - 구간트리의 갱신
 * 하나의 값이 바뀌었을 때 해당 위치를 포함하는 구간은 트리에 logn개 있다. 따라서 O(logn)에 가능
 * 
 */

struct RMQ
{
	int n;
	vector<int> rangeMin;

	RMQ(const vector<int> &array)
	{
		n = array.size();
		rangeMin.resize(n * 4);
		init(array, 0, n - 1, 1);
	}

	//O(n)
	int init(const vector<int> &array, int left, int right, int node)
	{
		if (left == right)
			return rangeMin[node] = array[left];
		int mid = (left + right) / 2;
		int leftMin = init(array, left, mid, node * 2);
		int rightMin = init(array, mid + 1, right, node * 2 + 1);
		return rangeMin[node] = min(leftMin, rightMin);
	}

	int query(int left, int right, int node, int nodeLeft, int nodeRight)
	{
		if (right < nodeLeft || nodeRight < left) return INT_MAX;
		if (left <= nodeLeft && nodeRight <= right) return rangeMin[node];
		int mid = (nodeLeft + nodeRight) / 2;
		return min(query(left, right, node * 2, nodeLeft, mid),
			query(left, right, node * 2 + 1, mid + 1, nodeRight));
	}
	//query()를 외부에서 호출하기 위한 인터페이스
	int query(int left, int right)
	{
		return query(left, right, 1, 0, n - 1);
	}

	int update(int index, int newValue, int node, int nodeLeft, int nodeRight)
	{
		//index가 노드가 표현하는 구간과 상관없는 경우엔 무시한다.
		if (index < nodeLeft || nodeRight < index) return rangeMin[node];
		//트리의 리프까지 내려온 경우
		if (nodeLeft == nodeRight) return rangeMin[node] = newValue;
		int mid = (nodeLeft + nodeRight) / 2;
		return min(update(index, newValue, node * 2, nodeLeft, mid),
			update(index, newValue, node * 2 + 1, mid + 1, nodeRight));
	}

	int update(int index, int newValue)
	{
		return update(index, newValue, 1, 0, n - 1);
	}
};



/*
 * 응용 -> 구간에 대해 원하는 값을 저장한다.
 *      구간에 속한 원소들의 곱, 합, 구간 원소들 중 최댓값, 구간 원소들 중 최솟값, 등등 
 */


/**
 * 펜윅 트리 : 빠르고 간단한 구간합
 * 구간 트리의 궁극적인 진화 형태 펜윅트리or이진 인덱스 트리
 * 부분합만을 이용
 * 
 */

// 펜윅 트리의 구현. 가상의 배열 A[] 의 부분 합을
// 빠르게 구현할 수 있도록 한다. 초기화시에는 A[] 의
// 원소가 전부 0 이라고 생각한다.
struct FenwickTree {
	vector<int> tree;
	FenwickTree(int n) : tree(n+1) {}

	// A[0..pos] 의 부분 합을 구한다
	int sum(int pos) {
		// 인덱스를 1 부터 시작하는 것이라고 생각하자
		++pos;
		int ret = 0;
		while(pos > 0) {
			ret += tree[pos];
			// 다음 구간을 찾기 위해 최종 비트를 지운다
			// 최종 1 비트를 0비트로 바꾸면 이전 구간이 된다.
			pos &= (pos-1);
		}
		return ret;
	}

	// A[pos] 에 val 을 더한다
	void add(int pos, int val) {
		++pos;
		while(pos < tree.size()) {
			tree[pos] += val;
			pos += (pos & -pos);
		}
	}
};