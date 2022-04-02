#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n;
int res[50];
int final[50];
pair<int, int> arr[50];
pair<int, int> tmp[50];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        arr[i] = {a, b};
        tmp[i] = {a, b};
    }
    sort(tmp, tmp+n);
    reverse(tmp, tmp+n);
    res[0] = 1;
    for(int i=1; i<n; i++){
        int rank = 1;
        for(int j=0; j<n; j++){
            if(tmp[i].X < tmp[j].X && tmp[i].Y < tmp[j].Y)
                rank++;
            else
                continue;
        }
        res[i] = rank;
    }
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(tmp[i].X == arr[j].X && tmp[i].Y == arr[j].Y)
                final[j] = res[i];

    for(int i=0; i<n; i++)
        cout << final[i] << " ";
    
    return 0;
}

/*
���� ����
�ټ�����ϰ� ������ ���� �ƴ϶�
�� ��쿡�� �ڱ��� ����� ���� ������ ���� �´�
���� ��� 90 180�� 1���� ��� 30 200�� ����� 1��� ���� ���̴�
��� ������ �ʿ䵵 ���� �ش� �˰��� �����ؼ� �׳� ��ĵ �� �ص� �ȴ�
*/