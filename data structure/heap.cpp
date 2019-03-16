#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 힙(heap)
 * 우선순위 큐를 위하여 만들어진 자료구조
 * 삽입 logn, 삽입 logn 구현 가능
 * 
 * 힙이란
 * - 완전 이진 트리의 일종
 * - 여러개의 값들 중에서 최댓값이나 최솟값을 빠르게 찾아내도록 만들어진 자료구조이다.
 * - 힙은 일종의 반정렬(느슨한 정렬 상태)를 유지한다.
 *      - 큰 값이 상위 레벨에 있고 작은 값이 하위 레벨에 있음
 * - 힙은 중복된 값을 허용한다.
 * 
 * 종류
 * - 최대 힙 : 부모 >= 자식
 * - 최소 힙 : 부모 <= 자식
 * 
 * 구현방법 
 * - 배열사용, 인덱스는 1부터 사용하는 것이 구현에 편리함
 * - 왼쪽 자식의 인덱스 = 부모의 인덱스*2
 * - 오른쪽 자식의 인덱스 = 부모의 인덱스*2 + 1
 * - 부모의 인덱스 = 자식의 인덱스/2
 */

/**
 * 힙의 삽입
 * 1. 힙에 새로운 요소가 들어오면 일단 힙의 마지막에 상빙한다.
 * 2. 새로운 노드를 부모와 비교해서 조건에 맞게 swap한다.
 */

/**
 * 힙의 삭제
 * - 최대 힙에서 삭제 연산은 최댓값(루트 노드)를 삭제하는 것이다
 * - 루트 노드를 삭제한 후 힙의 마지막 노드를 루트로 이동시킨다.
 * - 자식노드중 큰 값과 swap해서 내려간다
 */


// heap 구현해보기!

template<typename T>
class MaxHeap
{
public:
	vector<T> heap;
	int heap_size;
	MaxHeap() { heap.resize(1); heap_size = 0; }
	void insert(T item);
	T delete_item();
	bool empty()
	{
		return heap_size == 0;
	}
	void print()
	{
		for (int i = 1; i <= heap_size; i++)
			cout << heap[i] << " ";
		cout << "\n";
	}
};

template <typename T>
void MaxHeap<T>::insert(T item)
{
	heap.push_back(item);
	heap_size++;

	for (int i = heap_size; i > 1; i /= 2)
	{
		if (heap[i / 2] < heap[i]) swap(heap[i / 2], heap[i]);
		else break;
	}
}

template <typename T>
T MaxHeap<T>::delete_item()
{
	if (heap_size == 0) return -1;

	T res = heap[1];
	heap[1] = heap[heap_size];
	heap.pop_back();
	heap_size--;

	for (int i = 1; i * 2 <= heap_size;)
	{
		if (heap[i] > heap[i * 2] && heap[i] > heap[i*2 + 1])
		{
			break;
		}
		else if (heap[i*2] > heap[i*2 + 1])
		{
			swap(heap[i], heap[i * 2]);
			i *= 2;
		}
		else
		{
			swap(heap[i], heap[i*2 + 1]);
			i = i * 2 + 1;
		}
	}

	return res;
}

int main()
{
	MaxHeap<int> h;
	h.insert(3);
	h.insert(5);
	h.insert(1);
	h.insert(6);
	h.insert(7);
	while (!h.empty()) cout << h.delete_item() << " ";
}

//와.. 힘들었다;;