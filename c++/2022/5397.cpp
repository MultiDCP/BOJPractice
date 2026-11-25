#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        string s;
        cin >> s;

        list<char> l;
        list<char>::iterator t;
        t = l.begin();
        
        for(int j=0; j<s.length(); j++){
            if(s[j] == '<'){
                if(t != l.begin()){
                    t--;
                }
            }
            else if(s[j] == '>'){
                if(t != l.end()){
                    t++;
                }
            }
            else if(s[j] == '-'){
                if(t != l.begin() && !l.empty()){
                    --t;
                    t = l.erase(t);
                }
            }
            else{
                l.insert(t, s[j]);
            }
        }
        for(t=l.begin(); t!=l.end(); t++){
            cout << *t;
        }
        cout << '\n';
    }
    return 0;
}