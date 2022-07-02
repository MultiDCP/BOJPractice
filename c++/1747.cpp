#include <bits/stdc++.h>
using namespace std;
int n;
vector<bool> v(1005001, true);
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    v[1] = false;
    for(int i=2; i*i<=1005000; i++)
        if(v[i])
            for(int j=i*i; j<=1005000; j=j+i)
                v[j] = false;
    
    int tmp = n;
    while(tmp <= 1005000){
        if(!v[tmp]){
            tmp++;
            continue;
        }
        string s = to_string(tmp);
        int t1 = 0;
        int t2 = s.length()-1;
        bool isPelin = true;
        while(t1 <= t2){
            if(s[t1] != s[t2])
                isPelin = false;
            t1++; t2--;
        }
        if(isPelin){
            cout << s;
            return 0;
        }
        tmp++;
    }

    return 0;
}