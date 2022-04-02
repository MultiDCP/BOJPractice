#include <bits/stdc++.h>
using namespace std;
int a, b, c;
int d[71][71][71];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);     

    for(int i=0; i<71; i++)
        for(int j=0; j<71; j++)
            for(int k=0; k<71; k++)
                if(i < 51 || j < 51 || k < 51) d[i][j][k] = 1;
                else if(i<j && j<k)
                    d[i][j][k] = d[i][j][k-1] + d[i][j-1][k-1] - d[i][j-1][k];
                else
                    d[i][j][k] = d[i-1][j][k] + d[i-1][j-1][k] + d[i-1][j][k-1] - d[i-1][j-1][k-1];
                
    while(true){
        cin >> a >> b >> c;
        if(a == -1 && b == -1 && c == -1) return 0;
        cout << "w(" << a << ", " << b << ", " << c << ") = ";
        if(a > 20 || b > 20 || c > 20){
            if(a > 0)
                a = 20;
            if(b > 0)
                b = 20;
            if(c > 0)
                c = 20;
        }
        cout << d[a+50][b+50][c+50] << "\n";
    }

    return 0;
}

/*
��ȭ�� �� �ű��
�ڵ� �� ¥����
����� �� ������
��ȣ �ϳ� ���� �� ��Ծ 1�ð��� �����ߴ�
�ڵ� �̻����̰� �ڽð� ���״� �׷� �� ������
������ ���� �ȹٷ� �ض�
��ǻ�ʹ� ������ ���Ѵ�
*/