#include <bits/stdc++.h>
using namespace std;
double a, b, v;
int result;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b >> v;
    if(a - b != 1){
        double tmp = v/(a-b) - a/(a-b) + 1;
        result = ceil(tmp);
    }
    else result = (v-a)+1;

    cout << result;

    return 0;
}

/*
ceil과 floor이 뭐하는 놈인지 익히자
*/