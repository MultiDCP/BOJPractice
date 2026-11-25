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
오답 정리
줄세우기하고 끝내는 것이 아니라
각 경우에서 자기의 등수를 따로 따지는 것이 맞다
예를 들어 90 180이 1등일 경우 30 200은 등수가 1등과 같을 것이다
사실 정렬할 필요도 없이 해당 알고리즘 적용해서 그냥 스캔 쭉 해도 된다
*/