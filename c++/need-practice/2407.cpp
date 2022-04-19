#include <bits/stdc++.h>
using namespace std;
int n, m;
string d[101][101];
string BigSum(string a, string b){
    int sum = 0;
    string newString = "";
    while(!a.empty() || !b.empty() || sum != 0){
        if(!a.empty()){
             sum += a.back() - '0';
             a.pop_back();
        }
        if(!b.empty()){
            sum += b.back() - '0';
            b.pop_back();
        }
        newString.push_back(sum % 10 + '0');
        sum /= 10;
    }
    reverse(newString.begin(), newString.end());
    return newString;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i=1; i<=n; i++){
        d[i][0] = "1";
        d[i][1] = to_string(i);
    }
    for(int i=2; i<=n; i++)
        for(int j=2; j<=m; j++)
            d[i][j] = BigSum(d[i-1][j-1], d[i-1][j]);
    
    cout << d[n][m];

    return 0;
}

/*
�ܺ��� ��Ʈ�� �޾� Ǯ����. ���� �ʿ�.

ū �� ���꿡 ���� �ͼ����� �ʿ䰡 �ֱ� �ϴ�.
���׿����� ���̽��̶�� ġƮŰ�� �ֱ⿡ ������ ����������
�׷��� C++���� ll�� �Ѿ�� ������ ����°� ����� �˾Ƶδ� �� ���� ���̴�
*/