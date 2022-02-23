#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    stack<int> s;
    queue<char> result;
    int n;
    int memory = 0;
    cin >> n;
    
    int a[n];
    
    for(int i=0; i<n; i++){
        int m;
        cin >> m;
        a[i] = m;
    }
    
    for(int i=0; i<n; i++){
        if(i == 0){
            for(int j=1; j<=a[i]; j++){
                s.push(++memory);
                result.push('+');
            }
            s.pop();
            result.push('-');
        }
        else if(s.empty() || a[i] > s.top()){
            for(int j=memory; j<a[i]; j++){
                s.push(++memory);
                result.push('+');
            }
            s.pop();
            result.push('-');
        }
        else if(a[i] < s.top()){
            cout << "NO\n";
            return 0;
        }
        else if(memory == n){
            if(a[i] != s.top()){
                cout << "NO\n";
                return 0;
            }
            else{
                s.pop();
                result.push('-');
            }
        }
        else if(a[i] == s.top()){
            s.pop();
            result.push('-');
        }
    }
    
    int size = result.size();
    for(int i=0; i<size; i++){
        cout << result.front() << ' ';
        result.pop();
    }
    cout << '\n';
    
    return 0;
}