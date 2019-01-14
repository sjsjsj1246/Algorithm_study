#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <functional>
#include <algorithm>
#define MOD 1000000000
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int compare(const void * a, const void * b) {
	return *(int *)b - *(int *)a;
}

int main() 
{
	int i = 0, arr[100001], j, zeroflag = 0, sum = 0, n2;
	char n;
	n = getchar();
	while (n != '\n' && n != EOF) 
	{
		n2 = n - '0';
		arr[i] = n2;
		i++;
		n = getchar();
	}
	for (j = 0; j<i; j++) if (arr[j] == 0) zeroflag = 1;
	if (zeroflag == 0) printf("-1");
	else 
	{
		for (j = 0; j<i; j++) sum += arr[j];
		if (sum % 3 != 0) printf("-1");
		else 
		{
			qsort(arr, i, sizeof(arr[0]), compare);
			for (j = 0; j<i; j++) 
			{
				printf("%d", arr[j]);
			}
		}
	}
	return 0;
}