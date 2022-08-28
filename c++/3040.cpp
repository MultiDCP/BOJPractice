#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i=0; i<9; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    do{
        int tmp = 0;
        for(int i=0; i<7; i++)
            tmp += v[i];
        
        if(tmp == 100){
            for(int i=0; i<7; i++)
                cout << v[i] << "\n";
            return 0;
        }
    }while(next_permutation(v.begin(), v.end()));

    return 0;
}