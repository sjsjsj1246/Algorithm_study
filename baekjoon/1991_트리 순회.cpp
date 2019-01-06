#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
int Left[27];
int Right[27];
int parent[27];

void preorder(int r)
{
	printf("%c", r + 'A');
	if (Left[r] != -1)preorder(Left[r]);
	if (Right[r] != -1)preorder(Right[r]);
}
void inorder(int r)
{
	if (Left[r] != -1)inorder(Left[r]);
	printf("%c", r + 'A');
	if (Right[r] != -1)inorder(Right[r]);
}
void postorder(int r)
{
	if (Left[r] != -1)postorder(Left[r]);
	if (Right[r] != -1)postorder(Right[r]);
	printf("%c", r + 'A');
}
int main()
{
	scanf("%d", &n);
	memset(Left, -1, sizeof(Left));
	memset(Right, -1, sizeof(Right));
	for (int i = 0; i<n; ++i) {
		parent[i] = i;
		char a, b, c;
		scanf(" %c %c %c", &a, &b, &c);
		if (b != '.') {
			Left[a - 'A'] = b - 'A';
			parent[b - 'A'] = a - 'A';
		}
		if (c != '.') {
			Right[a - 'A'] = c - 'A';
			parent[c - 'A'] = a - 'A';
		}
	}
	int root = -1;
	for (int i = 0; i<n; ++i) {
		if (parent[i] == i) {
			root = i;
			break;
		}
	}
	preorder(root);
	printf("\n");
	inorder(root);
	printf("\n");
	postorder(root);
}