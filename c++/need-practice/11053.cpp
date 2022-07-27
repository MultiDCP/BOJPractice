#include <bits/stdc++.h>
using namespace std;
int n, mIdx;
int a[1001];
int d[1001];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];

    d[0] = 1;
    for(int i=1; i<n; i++){
        // Hint: 1~i-1까지의 원소들에서 i번째보다 값이 작은 것들 중 가장 큰 dp값 + 1
        int maxD = 0;
        for(int j=0; j<i; j++){
            if(a[j] < a[i]){
                maxD = max(maxD, d[j]);
            }
        }
        d[i] = maxD + 1;
        if(d[mIdx] < d[i])
            mIdx = i;
    }

    cout << d[mIdx];
    return 0;
}

/*
10 20 10 30 20 50 30 40 50 60
1  2  1  3  2  4  3  4  5  6
*/

/*
틀림 + 힌트를 받아서 풀음. 복습 반드시 필요.
*/

// 틀린 코드
/*
#include <bits/stdc++.h>
using namespace std;
int n;
int a[1000];
int d[1000];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];
    d[0] = 1;
    for(int i=1; i<n; i++){
        if(a[i-1] < a[i]) d[i] = d[i-1] + 1;
        else{
            d[i] = 1;
            int max = 0;
            for(int j=i-1; j>=0; j--){
                if(a[i] <= a[j] && max >= a[j]) continue;
                else{
                    d[i] = d[j] + 1;
                    max = a[j];
                }
            }
        }
    }
    for(int i=0; i<n; i++)
        cout << d[i] << " ";
    cout << "\n";
    cout << *max_element(d, d+n);

    return 0;
}
*/