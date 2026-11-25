#include <bits/stdc++.h>
using namespace std;
int n, k;
int maxE = -1;
vector<int> v;
void bt(string s, int count){
    if(s != "" && count > 0)
        if(stoi(s) > n)
            return;
        else
            maxE = max(maxE, stoi(s));
            
    for(int i=0; i<k; i++){
        s.push_back(char(v[i] + '0'));
        count++;
        bt(s, count);
        s.pop_back();
        count--;
    }
    
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    for(int i=0; i<k; i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    bt("", 0);
    cout << maxE;

    return 0;
}