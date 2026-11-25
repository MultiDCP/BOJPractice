#include <bits/stdc++.h>
using namespace std;
int n, m, sCnt;
unordered_set<string> s;
vector<string> v;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<n; i++){
        string st;
        cin >> st;
        s.insert(st);
    }

    for(int i=0; i<m; i++){
        string st;
        cin >> st;
        if(s.find(st) != s.end()){
            sCnt++;
            v.push_back(st);
        }
    }
    
    sort(v.begin(), v.end());
    cout << sCnt << "\n";
    for(int i=0; i<v.size(); i++)
        cout << v[i] << "\n";

    return 0;
}