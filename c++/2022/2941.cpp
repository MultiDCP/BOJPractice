#include <bits/stdc++.h>
using namespace std;
string s;
int n;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    for(int i=0; i<s.length(); i++){
        if(s[i] == 'c'){
            if(i+1<s.length() && (s[i+1] == '=' || s[i+1] == '-')){
                ++n; ++i;
            }
            else ++n;
        }
        else if(s[i] == 'd'){
            if(i+2<s.length() && s[i+1] == 'z' && s[i+2] == '='){
                ++n; i+=2;
            }
            else if(i+1<s.length() && s[i+1] == '-'){
                ++n; ++i;
            }
            else ++n;
        }
        else if(s[i] == 'l'){
            if(i+1<s.length() && s[i+1] == 'j'){
                ++n; ++i;
            }
            else ++n;
        }
        else if(s[i] == 'n'){
            if(i+1<s.length() && s[i+1] == 'j'){
                ++n; ++i;
            }
            else ++n;
        }
        else if(s[i] == 's'){
            if(i+1<s.length() && s[i+1] == '='){
                ++n; ++i;
            }
            else ++n;
        }
        else if(s[i] == 'z'){
            if(i+1<s.length() && s[i+1] == '='){
                ++n; ++i;
            }
            else ++n;
        }
        else ++n;
    }
    cout << n;

    return 0;
}