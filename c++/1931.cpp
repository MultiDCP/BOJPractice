#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n, result;
pair<int, int> a[100000];

bool compare(pair<int, int> a, pair<int, int> b){
    if(a.Y == b.Y)
        return a.X < b.X;
    else
        return a.Y < b.Y;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i=0; i<n; i++){
        int f, s;
        cin >> f >> s;
        a[i] = {f, s};
    }
    
    sort(a, a+n, compare);
    
    pair<int, int> cur = {0, 0};
    
    for(int i=0; i<n; i++)
        if(cur.Y <= a[i].X){
            result++;
            cur = a[i];
        }
    cout << result;

    return 0;
}

/*
강의의 힌트를 받아 푼 문제임. 복습 필요.
*/