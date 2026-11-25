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

    for(int i=1; i<=n; i++){ // 짐의 수
        for(int j=1; j<=k; j++){ // 짐의 무게
            if(item[i].W <= j){
                d[i][j] = max(d[i-1][j], item[i].V + d[i-1][j-item[i].W]);
                /*
                그러니까 대충 예시를 들면
                i가 3이고 j가 7이라고 하자
                그러면 위의 값인 13을 가져올지, 아니면
                현재 짐의 가치값과 무게 7에서 현재 짐의 무게를 뺀(4가 될 것)
                것의 가치값을 가져올지를 결정하게 될 것이다.
                만약 이게 어짜피 0이거나 값이 더 작으면 위의 값을 가져오면 그만이고
                (0인 경우는 아마 넣을 수 없는 경우거나 그럴 것이다)
                그게 값이 최대가 되면 그걸 때려박으면 된다
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
강의 및 예제의 도움을 받아 함께 풀음. 복습 반드시 필요.
*/