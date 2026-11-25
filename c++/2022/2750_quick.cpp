#include <bits/stdc++.h>
using namespace std;

int arr[1000];
int n;
void quick_sort(int st, int en){
    if(en <= st + 1) return;
    int pivot = st;
    int l = st+1;
    int r = en-1;
    while(l <= r){
        while(arr[l] <= arr[pivot] && l <= r) l++;
        while(arr[r] >= arr[pivot] && l <= r) r--;
        if(l > r){
            swap(arr[r], arr[pivot]);
            break;
        }
        swap(arr[l], arr[r]);
    }
    quick_sort(st, r);
    quick_sort(r+1, en);
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];
    quick_sort(0, n);

    for(int i=0; i<n; i++) cout << arr[i] << " ";
    return 0;
}

/*
복습 필요
퀵 소트 알고리즘 똑바로 이해하자
*/