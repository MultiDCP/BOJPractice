#include <bits/stdc++.h>
using namespace std;
int n, res;
vector<bool> v(1001);
void check(int k){
    int gap = -1000;
    string s = to_string(k);
    if(s.length() == 1)
        res++;
    else{
        for(int i=1; i<s.length(); i++){
            int tmp = int(s[i-1] - '0') - int(s[i] - '0');
            if(gap != -1000 && gap != tmp)
                return;
            gap = tmp;
        }
        res++;
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=1; i<=n; i++)
        check(i);
    cout << res;

    return 0;
}