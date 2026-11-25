#include <bits/stdc++.h>
using namespace std;
int num[10001];
void SelfNum(){
    int n = 1;
    while(n <= 10000){
        int res = 0;
        int org = n;
        string s = to_string(n);
        for(int i=0; i<s.length(); i++)
            res += int(s[i] - '0');
        res += org;
        if(res <= 10000)
            num[res] = 1;
        n = org + 1;
    }
    for(int i=1; i<=10000; i++)
        if(num[i] == 0)
            cout << i << "\n";
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    SelfNum();
    
    return 0;
}