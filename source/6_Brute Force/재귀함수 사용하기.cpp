/*
0부터 n까지 원소중 네개를 고르는 문제를 고려해보자
*/

// 반복문
for(int i=0;i<n;i++)
    for(int j=i+1;j<n;j++)
        for(int k=j+1;k<n;k++)
            for(int l=k+1;l<n;l++)
                {i,j,k,l}
// 간단하다.
// 선택해야 하는 수가 늘어난다면? 까다로운 조건이 추가된다면?

// 재귀함수
vector<int> pick(int n, vector<int>& picked, int toPick)
{
    //기저사례
    if(toPick ==0) {return picked}

    int smallest = picked.empty() ? 0 : picked.back() + 1;

    for(int next = smallest; next < n; next++)
    {
        picked.push_back(next);
        pick(n, picked, toPick - 1);
        picked.pop_back();
    }
}
//복잡하지만 특수한 조건을 적용하기 쉬움