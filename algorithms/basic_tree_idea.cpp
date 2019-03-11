#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

/*
21.1 도입
트리: 계층 구조를 갖는 자료구조, 탐색형 자료구조임

트리는 자료가 저장된 노드(node)들이 간선(edge)로 연결되어 있다.
상위 노드를 부모(parent), 하위 노드를 자식(child), 부모가 같은 노드들을 형제(sibling),
부모노드와 그의 부모들을 통틀어 선조(ancestor), 자식 노드와 그의 자식들을 통틀어
자손(descendant)노드 라고 부른다. 부모가 없는 노드를 루트(root) 자식이 없는 노드를 리프(leaf)
노드라고 한다.

트리의 깊이 = 루트에서 어떤 노드에 도달하기 위해 거쳐야 하는 간선의 수
트리의 높이 = 가장 깊숙히 있는 노드의 깊이

트리의 재귀적 속성 = 트리의 부분을 잘라내도 그래도 트리기 때문에 재귀적인 성질을 가진다.

트리의 표현 :
트리는 굉장히 다양한 방법으로 구현항 수 있다. 가장 일반적인 형태는 각 노드를 하나의 구조체/객체
로 표현하고, 이들을 서로의 포인터로 연결하는 것이다. 이때 각 노드들은 자신의 부모와 모든 자손들에
대한 포인터를 가지고 있다.
*/

// 트리의 노드를 표현하는 객체의 구현
struct TreeNode
{
    string label;                // 저장할 자료, 꼭 문자열일 필요는 없다
    TreeNode *parent;            // 부모 노드를 가리키는 포인터
    vector<TreeNode *> children; // 자손 노드들을 가리키는 포인터의 배열
};

//트리의 특성에 따라 구조는 조금씩 바뀔 수 있다.

/*
21.2 트리의 순회

트리는 그 구조가 일정하지 않기 때문에 재귀적 속성을 이용하여 순회해야 한다.
O(N)
*/

// 주어진 트리의 각 노드에 저장된 값을 모두 출력한다.
void printLabels(TreeNode *root)
{
    // 전위 탐색 : cout << root->num << endl;
    //각 자손들을 루트로 하는 서브트리에 포함된 값들을 재귀적으로 출력한다.
    for (int i = 0; i < root->children.size(); i++)
    {
        printLabels(root->children[i]);
        // 중위탐색은 이진 트리에서나 하는거라서..
    }
    /*
	중위 탐색
	printLabels(root->left);
	cout << root->num << endl;
	printLabels(root->right);
	*/
    //후위 탐색 : cout << root->num << endl;
}

// 레벨 순회 그냥 BFS임
void levelOrderTraversal(TreeNode *node)
{
    queue<TreeNode *> q;
    q.push(node);
    while (!q.empty()) // iteration
    {
        node = q.front();
        q.pop();
        for (int i = 0; i < node->children.size(); i++)
        {
            int nextNode = node->children[i];
            if (!visit[nextNode])
            {
                visit[nextNode] = 1;
                q.push(node)
            }
        }
    }
}

// 순회를 이용해 트리의 높이를 계산
int height(TreeNode *root)
{
    int h = 0;
    for (int i = 0; i < root->children.size(); i++)
        h = max(h, height(root->children[i]) + 1);
    return h;
}

/*
다음에 공부할 것
- 이진 검색 트리
- 힙
- 구간 트리
- 상호 배타적 집합
- 트라이
*/