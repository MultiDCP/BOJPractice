#include <bits/stdc++.h>
using namespace std;
int n;
int d[31];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    d[0] = 0;
    d[2] = 3;
    for(int i=4; i<=n; i+=2){
        d[i] += d[i-2] * 3; // d[i-2]�� d[2]�� ��ģ ��츦 �����
        for(int j=i-4; j>0; j-=2)
            d[i] += d[j] * 2; // d[i-4], d[i-6], ...�� ���� ������ ���� ����� �� 2���� ��ģ ��츦 �����
        d[i] += 2; // i���� ���� �� �ִ� ���� ����� �� 2���� ������
    }
    cout << d[n];

    return 0;
}

/*
�� �̵� ������ �� �־�
*/