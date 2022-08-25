#include <bits/stdc++.h>
using namespace std;
string s;
const char a[10] = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(true){
        int res = 0;
        getline(cin, s);
        if(s == "#") break;
        for(int i=0; i<s.length(); i++)
            for(int j=0; j<10; j++)
                if(s[i] == a[j])
                    res++;
        cout << res << "\n";
    }

    return 0;
}