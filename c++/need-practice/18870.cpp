#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> v1;
vector<int> v2;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        v1.push_back(tmp);
        v2.push_back(tmp);
    }
    sort(v2.begin(), v2.end());
    v2.erase(unique(v2.begin(), v2.end()), v2.end());
    for(int i=0; i<n; i++)
        cout << lower_bound(v2.begin(), v2.end(), v1[i]) - v2.begin() << " ";

    return 0;
}

/*
�ܺ��� ��Ʈ�� �޾Ƽ� Ǯ����. ���� �ʿ�

��ũ�� : unique�� lower_bound(���� Ž��)�� ���� �ð����⵵�� ���δ�.
��κ��� ���� �����ߴ� Ǯ�̴� ��� O(N^2) Ǯ�̵��̾���.
������ ���� Ž���� �� �� ����Ž���� ������� �ʾұ⿡ �׷� ����� ���Դ�.
unique �Լ��� ���� ���ĵ� �ӽ� ���Ϳ��� �ߺ����� �ɷ�����,
���� ������ ���� �ӽ� ������ ��� ��ġ���ִ��� �ε����� ��ȯ������ �ȴ�.
�� Ž���� �������� ���� Ž���� ����� �� ������,
lower_bound �Լ��� ����� �ε����� ��ȯ���� �� �ִ�.
�׷��� O(NlgN)���� �ð����⵵�� �����ų �� �ְ� �ȴ�.
*/