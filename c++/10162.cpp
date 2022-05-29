#include <bits/stdc++.h>
using namespace std;
int t, a, b, c;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t >= 10){
        if(t >= 300){
            a = t / 300;
            t %= 300;
        }
        else if(t >= 60){
            b = t / 60;
            t %= 60;
        }
        else{
            c = t / 10;
            t %= 10;
        }
    }
    if(t != 0)
        cout << -1;
    else
        cout << a << " " << b << " " << c;

    return 0;
}