#include <bits/stdc++.h>
using namespace std;
int n;
int d[1000001];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    d[2] = 1;
    d[3] = 1;
    for(int i=4; i<=n; i++)
        if(i % 3 == 0)
            if(i % 2 == 0)
                d[i] = 1 + min(d[i/3], min(d[i/2], d[i-1]));
            else
                d[i] = 1 + min(d[i/3], d[i-1]);
        else if(i % 2 == 0) d[i] = 1 + min(d[i/2], d[i-1]);
        else d[i] = 1 + d[i-1];
    cout << d[n] << "\n";

    int tmp = n;
    while(tmp > 1){
        cout << tmp << " ";
        if(tmp % 3 == 0)
            if(tmp % 2 == 0)
                if(d[tmp] == 1 + d[tmp/3])
                    tmp /= 3;
                else if(d[tmp] == 1 + d[tmp/2])
                    tmp /= 2;
                else
                    tmp--;
            else
                if(d[tmp] == 1 + d[tmp/3])
                    tmp /= 3;
                else
                    tmp--;
        else if(tmp % 2 == 0)
            if(d[tmp] == 1 + d[tmp/2])
                tmp /= 2;
            else
                tmp--;
        else tmp--;
    }
    cout << 1;

    return 0;
}

/*
���� ����
i�� "6�� ���"�� ��츦 �������� ���ߴ�.
�� ���� /3, /2, -1 �� �ƴ� ���� �� ������
��� ��Һ񱳸� �߾�� �ߴ�.
*/