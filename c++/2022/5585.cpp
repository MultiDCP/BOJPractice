#include <bits/stdc++.h>
using namespace std;
int n, cnt;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    n = 1000 - n;
    while(n >= 1){
        if(n >= 500){
            cnt += (n / 500);
            n %= 500;
        }
        else if(n >= 100){
            cnt += (n / 100);
            n %= 100;
        }
        else if(n >= 50){
            cnt += (n / 50);
            n %= 50;
        }
        else if(n >= 10){
            cnt += (n / 10);
            n %= 10;
        }
        else if(n >= 5){
            cnt += (n / 5);
            n %= 5;
        }
        else{
            cnt += n;
            n = 0;
        }
    }
    cout << cnt;

    return 0;
}