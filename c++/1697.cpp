#include <bits/stdc++.h>
using namespace std;

int dis[100001];
int pos[3] = {-1, 1, 2};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    bool isFind = 0;
    int min = 1000000;
    cin >> n >> k;

    if(n >= k){
        cout << abs(k-n);
    }
    else{
        for(int i=0; i<=k; i++){
            dis[i] = -1;
        }

        queue<int> q;

        q.push(n);
        dis[n] = 0;

        while(!isFind){
            int cur = q.front();
            if(cur == k){
                cout << dis[cur];
                isFind = true;
            }
            q.pop();

            for(int i=0; i<3; i++){
                int tmp;
                if(i != 2)
                    tmp = cur + pos[i];
                else tmp = cur * 2;
                if(tmp < 0 || tmp > 100000) continue;
                if(dis[tmp] > 0) continue;
                dis[tmp] = dis[cur] + 1;
                q.push(tmp);
            }
        }
    }

    return 0;
}

/*
오답 이유
일단 규칙 잘 찾아서 이게 BFS를 쓰는 거라는 것을
굉장히 잘 찾아냈다 칭찬할만하다
다만 동생이 더 뒤에 있는 경우를 제대로 작성하지 못했다
마이너스 값이 나올 수가 없으니 말이다
그러니까 제발 테스트 케이스 좀 제대로 쳐넣고 생각해
다 맞혀놓고 뭐하는 거야 으으윽 흑흑
*/