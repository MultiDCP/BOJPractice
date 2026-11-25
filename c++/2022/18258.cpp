#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    queue<int> q;
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        if(s == "push"){
            int m;
            cin >> m;
            q.push(m);
        }
        else if(s == "pop"){
            if(q.empty())
                cout << "-1\n";
            else{
                cout << q.front() << "\n";
                q.pop();
            }
        }
        else if(s == "size")
            cout << q.size() << "\n";
        else if(s == "empty")
            cout << q.empty() << "\n";
        else if(s == "front"){
            if(q.empty())
                cout << "-1\n";
            else
                cout << q.front() << "\n";
        }
        else if(s == "back"){
            if(q.empty())
                cout << "-1\n";
            else
                cout << q.back() << "\n";
        }
    }

    return 0;
}