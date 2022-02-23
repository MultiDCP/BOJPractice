#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    stack<int> s;
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        string c;
        cin >> c;
        if(c == "push"){
            int m;
            cin >> m;
            s.push(m);
        }
        else if(c == "pop"){
             if(s.empty())
                cout << "-1\n";
            else{
                cout << s.top() << '\n';
                s.pop();
            }
        }
        else if(c == "size"){
            cout << s.size() << '\n';
        }
        else if(c == "empty"){
            cout << s.empty() << '\n';
        }
        else if(c == "top"){
            if(s.empty())
                cout << "-1\n";
            else
                cout << s.top() << '\n';
        }
    }
    
    return 0;
}