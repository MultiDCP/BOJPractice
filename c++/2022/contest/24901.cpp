#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    string s;
    for(int i=0; i<=n; i++){
        int tmp = i;
        string tmps;
        do{
            tmps += to_string(tmp%2);
            tmp /= 2;
        } while(tmp > 0);
        reverse(tmps.begin(), tmps.end());
        s += tmps;
    }
    cout << s;

    return 0;
}

/*
이게 문제냐???????????????????????????????
*/