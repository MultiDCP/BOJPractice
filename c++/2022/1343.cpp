#include <bits/stdc++.h>
using namespace std;
string s, newS;
int cnt = 0;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    for(int i=0; i<s.length(); i++){
        if(s[i] == 'X')
            cnt++;
        else if(s[i] == '.' && cnt > 0){
            while(cnt > 0){
                if(cnt >= 4){
                    for(int j=0; j<4; j++)
                        newS.push_back('A');
                    cnt -= 4;
                }
                else if(cnt >= 2){
                    for(int j=0; j<2; j++)
                        newS.push_back('B');
                    cnt -= 2;
                }
                else{
                    cout << -1;
                    return 0;
                }
            }
            newS.push_back('.');
        }
        else newS.push_back('.');
    }
    while(cnt > 0){
        if(cnt >= 4){
            for(int i=0; i<4; i++)
                newS.push_back('A');
            cnt -= 4;
        }
        else if(cnt >= 2){
            for(int i=0; i<2; i++)
                newS.push_back('B');
            cnt -= 2;
        }
        else{
            cout << -1;
            return 0;
        }
    }
    cout << newS;

    return 0;
}