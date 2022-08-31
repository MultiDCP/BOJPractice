#include <bits/stdc++.h>
using namespace std;
#define FLR first
#define CNT second
int f, g, s;
int ud[2];
bool vis[1000001];
queue<pair<int, int>> q;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> f >> s >> g >> ud[0] >> ud[1];

    q.push({s, 0});
    vis[s] = true;

    while(!q.empty()){
        auto k = q.front();
        q.pop();

        if(k.FLR == g){
            cout << k.CNT << "\n";
            return 0;
        }

        for(int i=0; i<2; i++){
            int newF = k.FLR;
            if(i == 0) newF += ud[0];
            else newF -= ud[1];

            if(newF > f || newF < 1) continue;
            if(vis[newF] == true) continue;

            vis[newF] = true;
            q.push({newF, k.CNT+1});
        }
    }

    cout << "use the stairs\n";

    return 0;
}