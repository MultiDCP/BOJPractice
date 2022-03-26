#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n, m;
int maxS = -1;
int b[500][500];

void block1(int i, int j){
    if(i+3 >= n) return;
    int one = 0;
    for(int k=0; k<4; k++)
        one += b[i+k][j];
    maxS = max(one, maxS);
}

void block1_1(int i, int j){
    if(j+3 >= m) return;
    int two = 0;
    for(int k=0; k<4; k++)
        two += b[i][j+k];
    maxS = max(two, maxS);
}

void block2(int i, int j){
    if(i+1 >= n || j+1 >= m) return;
    int tmp = 0;
    for(int k=0; k<2; k++)
        for(int l=0; l<2; l++)
            tmp += b[i+k][j+l];
    maxS = max(tmp, maxS);
}

void block3(int i, int j){ // 2*3 관리
    if(i+1 >= n || j+2 >= m) return;
    static pair<int, int> p[6]
        = {{1, 0}, {1, 1}, {1, 2}, {0, 0}, {0, 1}, {0, 2}};
    int tmp = 0;
    for(int k=0; k<2; k++){
        for(int l=0; l<3; l++)
            tmp += b[i+k][j+l];
        if(k == 0)
            for(int q=0; q<3; q++)
                maxS = max(maxS, tmp + b[i+p[q].X][j+p[q].Y]);
        else
            for(int q=0; q<3; q++)
                maxS = max(maxS, tmp + b[i+p[q+3].X][j+p[q+3].Y]);
        tmp = 0;
    }
    for(int k=0; k<2; k++)
        for(int l=0; l<3; l++)
            tmp += b[i+k][j+l];
    maxS = max(maxS, tmp - b[i+1][j+2] - b[i][j]);
    maxS = max(maxS, tmp - b[i+1][j] - b[i][j+2]);
}

void block4(int i, int j){
    if(i+2 >= n || j+1 >= m) return;
    static pair<int, int> p[6]
        = {{0, 1}, {1, 1}, {2, 1}, {0, 0}, {1, 0}, {2, 0}};
    int tmp = 0;
    for(int k=0; k<2; k++){
        for(int l=0; l<3; l++)
            tmp += b[i+l][j+k];
        if(k == 0)
            for(int q=0; q<3; q++)
                maxS = max(maxS, tmp + b[i+p[q].X][j+p[q].Y]);
        else
            for(int q=0; q<3; q++)
                maxS = max(maxS, tmp + b[i+p[q+3].X][j+p[q+3].Y]);
        tmp = 0;
    }
    for(int k=0; k<2; k++)
        for(int l=0; l<3; l++)
            tmp += b[i+l][j+k];
    maxS = max(maxS, tmp - b[i+2][j+1] - b[i][j]);
    maxS = max(maxS, tmp - b[i][j+1] - b[i+2][j]);
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> b[i][j];
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            block1(i, j);
            block1_1(i, j);
            block2(i, j);
            block3(i, j);
            block4(i, j);
        }
    }
    cout << maxS;

    return 0;
}

/*
오답 정리
테스트 케이스를 똑바로 넣는 연습을 많이 해보자
*/