#include <cstdio>
#include <cstring>
using namespace std;
int main() {
	char str[3];
	while (fgets(str, 3, stdin) != NULL) {
		str[strlen(str) - 1] = '\0';
		printf("%s\n", str);//fgets�� ������ ����.
	}
	return 0;
}
