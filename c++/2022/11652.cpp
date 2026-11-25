#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
vector<ll> v;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        ll tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());

    ll maxE = v[0];
    int maxC = 0;
    int j = 0;
    while(v[j] == maxE)
        j++;

    maxC = j;

    int tmpC = 0;
    ll tmpE = v[j];
    for(int i=j; i<n; i++){
        if(v[i] == tmpE)
            tmpC++;
        else{
            if(max(tmpC, maxC) == tmpC){
                if(tmpC == maxC){
                    maxE = min(tmpE, maxE);
                }
                else{
                    maxC = tmpC;
                    maxE = tmpE;
                }
            }
            tmpE = v[i];
            tmpC = 0;
        }

        if(i == n-1){
            if(max(tmpC, maxC) == tmpC){
                if(tmpC == maxC){
                    maxE = min(tmpE, maxE);
                }
                else{
                    maxC = tmpC;
                    maxE = tmpE;
                }
            }
        }
    }
    cout << maxE;

    return 0;
}
