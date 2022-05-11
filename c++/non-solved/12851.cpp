#include <bits/stdc++.h>
using namespace std;
int pos[3] = {1, -1, 2};
int dis[100001];
int n, k, countT;
int minT = 0x7f7f7f7f;
queue<int> q;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    if(n >= k){
        cout << abs(n-k) << "\n1";
        return 0;
    }
    dis[n] = 0;
    q.push(n);
    bool isFound = false;
    int index = -1;
    while(!isFound){
        int cur = q.front();
        q.pop();
        if(cur == k){
            minT = dis[cur];
            index = cur;
            isFound = true;
        }
        else{
            for(int i=0; i<3; i++){
                int nx;
                if(i == 2) nx = cur * 2;
                else nx = cur + pos[i];

                if(nx < 0 || nx > 100000) continue;
                //if(dis[nx] == 0) dis[nx] = dis[cur] + 1;
                if(dis[nx] > 0) continue;
                dis[nx] = dis[cur] + 1;
                q.push(nx);
            }
        }
    }
    for(int i=0; i<3; i++){
        if(i == 2 && index % 2 == 0){
            //cout << index/2 << " " << dis[index/2] << "\n";
            if(dis[index / 2] == dis[index] - 1)
                countT++;
        }
        else if(i != 2){
            //cout << index+pos[i] << " " << dis[index+pos[i]] << "\n";
            if(dis[index + pos[i]] == dis[index] - 1)
                countT++;
        }
    }

    cout << minT << "\n" << countT;

    return 0;
}