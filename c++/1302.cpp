#include <bits/stdc++.h>
using namespace std;
int n, maxC;
unordered_map<string, int> m;
vector<string> maxV;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        if(m.find(s) != m.end()){
            m[s]++;
            if(m[s] >= maxC){
                if(m[s] > maxC){
                    maxC = m[s];
                    maxV.clear();
                }
                maxV.push_back(s);
            }
        }
        else{
            m.insert({s, 1});
            if(maxC == 0){
                maxC = 1;
                maxV.push_back(s);
            }
            if(m[s] == maxC)
                maxV.push_back(s);
        }
    }
    sort(maxV.begin(), maxV.end());
    cout << maxV[0];

    return 0;
}