#include <bits/stdc++.h>
using namespace std;
#define W first
#define V second
int n, k;
int d[101][100001];
vector<pair<int, int>> item;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    item.push_back({0, 0});
    for(int i=1; i<=n; i++){
        int w, v;
        cin >> w >> v;
        item.push_back({w, v});
    }

    for(int i=1; i<=n; i++){ // ���� ��
        for(int j=1; j<=k; j++){ // ���� ����
            if(item[i].W <= j){
                d[i][j] = max(d[i-1][j], item[i].V + d[i-1][j-item[i].W]);
                /*
                �׷��ϱ� ���� ���ø� ���
                i�� 3�̰� j�� 7�̶�� ����
                �׷��� ���� ���� 13�� ��������, �ƴϸ�
                ���� ���� ��ġ���� ���� 7���� ���� ���� ���Ը� ��(4�� �� ��)
                ���� ��ġ���� ���������� �����ϰ� �� ���̴�.
                ���� �̰� ��¥�� 0�̰ų� ���� �� ������ ���� ���� �������� �׸��̰�
                (0�� ���� �Ƹ� ���� �� ���� ���ų� �׷� ���̴�)
                �װ� ���� �ִ밡 �Ǹ� �װ� ���������� �ȴ�
                */
            }
            else{
                d[i][j] = d[i-1][j];
            }
        }
    }

    cout << d[n][k] << "\n";

    return 0;
}

/*
���� �� ������ ������ �޾� �Բ� Ǯ��. ���� �ݵ�� �ʿ�.
*/