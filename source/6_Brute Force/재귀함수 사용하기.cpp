/*
0���� n���� ������ �װ��� ���� ������ ����غ���
*/

// �ݺ���
for(int i=0;i<n;i++)
    for(int j=i+1;j<n;j++)
        for(int k=j+1;k<n;k++)
            for(int l=k+1;l<n;l++)
                {i,j,k,l}
// �����ϴ�.
// �����ؾ� �ϴ� ���� �þ�ٸ�? ��ٷο� ������ �߰��ȴٸ�?

// ����Լ�
vector<int> pick(int n, vector<int>& picked, int toPick)
{
    //�������
    if(toPick ==0) {return picked}

    int smallest = picked.empty() ? 0 : picked.back() + 1;

    for(int next = smallest; next < n; next++)
    {
        picked.push_back(next);
        pick(n, picked, toPick - 1);
        picked.pop_back();
    }
}
//���������� Ư���� ������ �����ϱ� ����