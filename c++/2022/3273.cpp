#include <bits/stdc++.h>
using namespace std;
int n, x, st, en, tmp, res;
int arr[100000];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    cin >> x;
    sort(arr, arr+n);

    en = n-1;
    if(n == 1){
        if(arr[0] == x)
            res++;
    }
    else{
        while(st < en){
            tmp = arr[st] + arr[en];
            if(tmp == x){
                res++;
                st++; en--;
            }
            else if(tmp > x)
                en--;
            else
                st++;
        }
    }
    cout << res;
    return 0;
}

/*
en과 st를 비교할 때 !=를 쓰면 안되는 이유?
-> 값이 같아서 둘이 교차하는 순간이 오면
en이나 st가 멈추지 못하고 배열의 끝까지 가서
OutOfBound 런타임 에러를 뿜어버림
*/