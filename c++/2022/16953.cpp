#include <bits/stdc++.h>
using namespace std;
#define V first
#define C second
#define ll long long
ll a, b;
queue<pair<ll, ll>> q;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b;
    q.push({a, 0});
    while(!q.empty()){
        auto k = q.front();
        q.pop();
        if(k.V == b){
            cout << k.C + 1 << "\n";
            return 0;
        }
        for(int i=0; i<2; i++){
            ll ne = k.V;
            if(i == 0)
                ne *= 2;
            else
                ne = ne * 10 + 1;
            if(ne > b) continue;
            q.push({ne, k.C+1});
        }
    }
    cout << -1 << "\n";

    return 0;
}