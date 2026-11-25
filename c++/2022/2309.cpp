#include <bits/stdc++.h>
using namespace std;

int a[9];
vector<int> r;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int sum = 0;
    int ban1, ban2;

    for(int i=0; i<9; i++){
        cin >> a[i];
        sum += a[i];
    }

    for(int i=0; i<8; i++){
        for(int j=i+1; j<9; j++){
            if((sum - a[i] - a[j]) == 100){
                ban1 = i; ban2 = j;
                break;
            }
        }
    }

    for(int i=0; i<9; i++){
        if(i == ban1 || i == ban2) continue;
        else
            r.push_back(a[i]);
    }

    sort(r.begin(), r.end());

    for(int i=0; i<7; i++)
        cout << r[i] << '\n';

    return 0;
}