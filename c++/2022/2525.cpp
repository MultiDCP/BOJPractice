#include <bits/stdc++.h>
using namespace std;
int h, m, c;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> h >> m >> c;
    m += c;
    if(m >= 60){
        do{
            m -= 60;
            h++;
        }while(m >= 60);
        if(h >= 24)
            h -= 24;
    }
    cout << h << " " << m;

    return 0;
}