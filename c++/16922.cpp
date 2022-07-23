#include <bits/stdc++.h>
using namespace std;
const int romN[4] = {1, 5, 10, 50};
int n, res;
bool vis[1001];
void bt(int curN, int lnt, int mn){
    if(lnt >= n){
        if(!vis[curN]) {
            vis[curN] = true;
            //cout << curN << " ";
        }
    }
    else{
        for(int i=0+mn; i<4; i++){
            curN += romN[i];
            bt(curN, lnt+1, i);
            curN -= romN[i];
        }
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    bt(0, 0, 0);

    for(int i=1; i<=1000; i++)
        if(vis[i]) res++;

    cout << res << "\n";

    return 0;
}