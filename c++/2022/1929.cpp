#include <bits/stdc++.h>
using namespace std;
int m, n;
vector<bool> arr(1000001, true);
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> m >> n;
    arr[1] = 0;
    for(int i=1; i*i<=n; i++){
        if(i == 1) continue;
        if(arr[i])
            for(int j=i*i; j<=n; j=j+i)
                if(j % i == 0)
                    arr[j] = 0;
    }    
    for(int i=m; i<=n; i++)
        if(arr[i])
            cout << i << "\n";

    return 0;
}

/*
여담
여러모로 수학적 사고력을 많이 요구하는 문제였다
최적화가 어디까지 되는지를 잘 고심해볼 필요가 있는듯
*/