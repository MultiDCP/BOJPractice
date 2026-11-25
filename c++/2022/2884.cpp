#include <iostream>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int h, m;

    cin >> h >> m;

    if(m < 45){
        m = m + 60 - 45;
        --h;
        if(h < 0)
            h = 23;
    }
    else{
        m -= 45;
    }

    cout << h << " " << m << '\n';

    return 0;
}