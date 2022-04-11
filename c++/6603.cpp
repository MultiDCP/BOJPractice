#include <bits/stdc++.h>
using namespace std;
int k;
int a[49];
bool isUsed[49];
void select(int num, vector<int> v){
    if(num == 6){
        for(int i=0; i<v.size(); i++)
            cout << v[i] << " ";
        cout << "\n";
    }
    else{
        for(int i=0; i<k; i++){
            if(isUsed[i]) continue;
            if(!v.empty() && v.back() > a[i]) continue;
            v.push_back(a[i]);
            isUsed[i] = true;
            select(num+1, v);
            isUsed[i] = false;
            v.pop_back();
        }
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    while(true){
        cin >> k;
        if(k == 0) break;
        for(int i=0; i<k; i++)
            cin >> a[i];
        vector<int> v;
        select(0, v);
        cout << "\n";
        fill(a, a+49, 0);
    }

    return 0;
}