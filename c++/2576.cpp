#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int min = 1001;
    int sum = 0;

    for(int i=0; i<7; i++){
        int tmp;
        cin >> tmp;

        if(tmp % 2 == 1){
            sum += tmp;
            if(min > tmp)
                min = tmp;
        }
    }

    if(sum == 0)
        cout << -1;
    else
        cout << sum << "\n" << min;

    return 0;
}