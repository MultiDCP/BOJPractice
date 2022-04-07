#include <bits/stdc++.h>
using namespace std;
int t, n;
string p, m;
deque<int> d;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    for(int i=0; i<t; i++){
        cin >> p >> n >> m;
        string tmp = "";
        for(int j=1; j<m.length(); j++)
            if(m[j] == ',' || m[j] == ']'){
                if(tmp == "") continue;
                d.push_back(stoi(tmp));
                tmp = "";
            }
            else tmp += m[j];
        
        bool isReverse = false;
        bool isBreak = false;
        for(int j=0; j<p.length(); j++)
            if(p[j] == 'R') isReverse = !isReverse;
            else if(p[j] == 'D' && !isBreak)
                if(d.empty()){
                    cout << "error\n";
                    isBreak = true;
                    break;
                }
                else if(isReverse)
                    d.pop_back();
                else
                    d.pop_front();

        if(!isBreak){
            cout << '[';
            if(!d.empty())
                while(!d.empty()){
                    if(isReverse){
                        cout << d.back();
                        d.pop_back();
                    }
                    else{
                        cout << d.front();
                        d.pop_front();
                    }
                    if(!d.empty()) cout << ',';
                }
            cout << "]\n";
        }
    }

    return 0;
}