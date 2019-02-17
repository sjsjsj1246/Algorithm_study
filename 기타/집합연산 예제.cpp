#include <iostream>

#include <vector>

#include <algorithm>

using namespace std;



int main() 
{

	int a[] = { 1, 4, 5, 6, 8 };
	int b[] = { 2, 3, 4, 5, 9 };
	vector<int> resultU(10), resultI(10), resultD1(10), resultD2(10), resultS(10);
	vector<int>::iterator iter;

	cout << "a:";
	for (int i = 0; i < 5; i++)
		cout << ' ' << a[i];
	cout << endl;
	cout << "b:";

	for (int i = 0; i < 5; i++)
		cout << ' ' << b[i];
	cout << endl;

	iter = set_union(a, a + 5, b, b + 5, resultU.begin());
	resultU.resize(iter - resultU.begin());
	cout << "A ∪ B:";
	for (int i = 0; i < resultU.size(); i++)
		cout << ' ' << resultU[i];

	cout << endl;

	iter = set_intersection(a, a + 5, b, b + 5, resultI.begin());
	resultI.resize(iter - resultI.begin());
	cout << "A ∩ B:";

	for (int i = 0; i < resultI.size(); i++)
		cout << ' ' << resultI[i];

	cout << endl;

	iter = set_difference(a, a + 5, b, b + 5, resultD1.begin());
	resultD1.resize(iter - resultD1.begin());
	cout << "A － B:";

	for (int i = 0; i < resultD1.size(); i++)
		cout << ' ' << resultD1[i];

	cout << endl;

	iter = set_difference(b, b + 5, a, a + 5, resultD2.begin());
	resultD2.resize(iter - resultD2.begin());
	cout << "B － A:";

	for (int i = 0; i < resultD2.size(); i++)
		cout << ' ' << resultD2[i];

	cout << endl;

	iter = set_symmetric_difference(a, a + 5, b, b + 5, resultS.begin());
	resultS.resize(iter - resultS.begin());
	cout << "A △ B:";

	for (int i = 0; i < resultS.size(); i++)
		cout << ' ' << resultS[i];
	cout << endl;
}