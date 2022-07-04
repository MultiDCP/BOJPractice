#include <bits/stdc++.h>
using namespace std;
int n, m;
unordered_map<string, int> st;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        st[s] = 1;
    }

    int res = 0;
    for(int i=0; i<m; i++){
        string s;
        cin >> s;
        if(st.find(s) != st.end())
            res++;
    }
    cout << res;

    return 0;
}