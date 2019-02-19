## Minimum/maximum operations
- max_element(구간) : 구간내의 최댓값의 iterator 또는 포인터 반환
- min_element(구간) : ''
- clamp(v, lo, hi)  : v의 범위를 lo~hi로 제한한다. operator< 를 사용하여 비교한다. (C++17 이상하게 vs-studio에 없다)

## Permutation operations
- is_permutation(s시작, s끝, d시작) : d가 s의 permutation인지 확인, (애너그램확인가능)
- next_permutation(구간)    : 오름차순으로 다음 순열을 만들고 true반환, 마지막이면 false반환
- pre_permutation(구간)     : ''

## Set operations (정렬돼있어야 함)
- includes (a구간, b구간)   : b가 a에 포함되면 true
- set_difference(a구간,b구간,저장위치)      : a-b 차집합 
- set_intersection(a구간,b구간,저장위치)    : 교집합
- set_symmetric_difference(a구간, b구간, 저장위치)  : 전체집합-교집합
- set_union(구간1,구간2,저장위치) : 합집합 계산 저장
- (iterator를 반환하는데 저장할 공간을 iterator의 크기?만큼 설정해줘야 한다)

## Modifying sequence operations (구현하려면 귀찮은데 알고보니 있었음)
- swap(a,b)
- reverse(구간)
- rotate(시작점, 시작점+회전할 횟수, 끝점) : 왜 있는지 몰랐을까 진짜로
- unique(구간) : 정렬된 상태에서 사용하면 중복된 원소는 뒤로 보내고 그것들의 시작 iter를 반환한다. erase(iter,v.end()) 하면 중복만 지워짐

## Non-modifying sequence operations
count_if(구간, 함수포인터or람다) : count_if(ALL(arr2), [](int i) {return i % 2; }); // arr2원소중 짝수의 갯수 반환함
