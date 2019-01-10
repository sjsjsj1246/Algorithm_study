#include <iostream>
#include <set>
#include <functional>
using namespace std;

int main(){

    set<int> s;

    s.insert(40);
    s.insert(30);
    s.insert(50);
    s.insert(80);
    s.insert(10);
    s.insert(90); 
    s.insert(70);

    set<int>::iterator iter;
    for (iter = s.begin(); iter != s.end(); ++iter)
        cout << *iter << " ";
    cout << endl;

    // count�� �ش� ������ ������ ��ȯ�Ѵ�. set�� �ߺ��� ������� �����Ƿ� 1 �Ǵ� 0�̴�.
    cout << "���� 50�� ���� : " << s.count(50) << endl;
    cout << "���� 100�� ���� : " << s.count(100) << endl;

    // find�� �ش� ���Ҹ� ã�´�. ���Ұ� ������ end() �� ��ȯ�Ѵ�.
    iter = s.find(30);
    if (iter != s.end())
        cout << *iter << "�� s�� �ִ�" << endl;
    else
        cout << "30�� s�� ����." << endl;

    
    set<int>::iterator iter_lower;
    set<int>::iterator iter_upper;

    iter_lower = s.lower_bound(30);        // 30 ������ ù��°
    iter_upper = s.upper_bound(30);        // 30 ���� �������� ���� ����
    cout << *iter_lower << endl;
    cout << *iter_upper << endl;

    iter_lower = s.lower_bound(55);
    iter_upper = s.upper_bound(55);
    
    // 55�� ù��° ���ҿ� �������Ҹ� ����Ű�� iter�� ������ ���� ����
    if (iter_lower != iter_upper)        
        cout << "55�� s�� �ִ�" << endl;
    else
        cout << "55�� s�� ����" << endl;


    // equal_range�� �ش� ������ ������ pair�� ��ȯ�Ѵ�.
    pair<set<int>::iterator, set<int>::iterator> iter_pair;
    
    iter_pair = s.equal_range(30);
    cout << *iter_pair.first << endl;
    cout << *iter_pair.second << endl;

    iter_pair = s.equal_range(55);
    if (iter_pair.first != iter_pair.second)
        cout << "55�� s�� �ִ� " << endl;
    else
        cout << "55�� s�� ���� " << endl;

    return 0;
}


//��ó: http://hyeonstorage.tistory.com/327 [������ �ϰ� �;��]