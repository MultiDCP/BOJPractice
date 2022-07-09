#include <bits/stdc++.h>
using namespace std;
bool arr[21];
int m;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m;
    for(int i=0; i<m; i++){
        string s;
        cin >> s;
        if(s == "all")
            for(int i=1; i<=20; i++)
                arr[i] = 1;
        else if(s == "empty")
            for(int i=1; i<=20; i++)
                arr[i] = 0;
        else{
            short n;
            cin >> n;
            if(s == "add")
                arr[n] = 1;
            else if(s == "remove")
                arr[n] = 0;
            else if(s == "check")
                cout << int(arr[n]) << "\n";
            else if(s == "toggle")
                if(arr[n])
                    arr[n] = 0;
                else
                    arr[n] = 1;
        }
    }

    return 0;
}