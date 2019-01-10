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

    // count는 해당 원소의 개수를 반환한다. set은 중복을 허용하지 않으므로 1 또는 0이다.
    cout << "원소 50의 개수 : " << s.count(50) << endl;
    cout << "원소 100의 개수 : " << s.count(100) << endl;

    // find는 해당 원소를 찾는다. 원소가 없으면 end() 를 반환한다.
    iter = s.find(30);
    if (iter != s.end())
        cout << *iter << "가 s에 있다" << endl;
    else
        cout << "30이 s에 없다." << endl;

    
    set<int>::iterator iter_lower;
    set<int>::iterator iter_upper;

    iter_lower = s.lower_bound(30);        // 30 원소의 첫번째
    iter_upper = s.upper_bound(30);        // 30 원소 마지막의 다음 원소
    cout << *iter_lower << endl;
    cout << *iter_upper << endl;

    iter_lower = s.lower_bound(55);
    iter_upper = s.upper_bound(55);
    
    // 55의 첫번째 원소와 다음원소를 가리키는 iter가 같으면 값이 없다
    if (iter_lower != iter_upper)        
        cout << "55가 s에 있다" << endl;
    else
        cout << "55가 s에 없다" << endl;


    // equal_range는 해당 원소의 범위를 pair로 반환한다.
    pair<set<int>::iterator, set<int>::iterator> iter_pair;
    
    iter_pair = s.equal_range(30);
    cout << *iter_pair.first << endl;
    cout << *iter_pair.second << endl;

    iter_pair = s.equal_range(55);
    if (iter_pair.first != iter_pair.second)
        cout << "55가 s에 있다 " << endl;
    else
        cout << "55가 s에 없다 " << endl;

    return 0;
}


//출처: http://hyeonstorage.tistory.com/327 [개발이 하고 싶어요]