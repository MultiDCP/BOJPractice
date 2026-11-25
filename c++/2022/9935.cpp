#include <bits/stdc++.h>
using namespace std;
string org, es;
stack<char> s;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> org >> es;
    for(int i=0; i<org.length(); i++){
        if(org[i] == es[es.length()-1]){
            string tmp;
            tmp.push_back(org[i]);
            int count = 1;
            while(!s.empty() && count < es.length()){
                tmp.push_back(s.top());
                s.pop();
                count++;
            }
            reverse(tmp.begin(), tmp.end());
            if(tmp != es){
                for(int j=0; j<tmp.length(); j++)
                    s.push(tmp[j]);
            }
        }
        else{
            s.push(org[i]);
        }
    }

    if(s.empty())
        cout << "FRULA\n";
    else{
        string tmp;
        while(!s.empty()){
            tmp.push_back(s.top());
            s.pop();
        }
        reverse(tmp.begin(), tmp.end());
        cout << tmp << "\n";
    }

    return 0;
}