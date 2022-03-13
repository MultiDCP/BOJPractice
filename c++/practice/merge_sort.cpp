#include <bits/stdc++.h>
using namespace std;

// arr1, arr2는 이미 정렬이 되어있는 상태
void merge1(int *arr1, int len1, int *arr2, int len2){
    int arr_sort[len1+len2]; // arr1, arr2를 합친 결과를 저장하는 리스트
    int idx0 = 0; // arr_sort에 값을 넣기 위해 사용
    int idx1 = 0; // arr1의 값을 보기 위해 사용
    int idx2 = 0; // arr2의 값을 보기 위해 사용

    while(idx1 < len1 && idx2 < len2){ // 한 쪽의 리스트를 모두 볼 때까지 반복
        if(arr1[idx1] < arr2[idx2])
            arr_sort[idx0++] = arr1[idx1++];
        else
            arr_sort[idx0++] = arr2[idx2++];
    }

    // 어느 한 리스트에는 값이 남아있을 것임
    while(idx1 < len1)
        arr_sort[idx0++] = arr1[idx1++];
    while(idx2 < len2)
        arr_sort[idx0++] = arr2[idx2++];
    for(int i=0; i<len1+len2; i++)
        cout << arr_sort[i] << " ";
}

int n = 10;
int arr[1000001] = {9, 5, 8, 10, 2, 1, 4, 7, 3, 6};
int tmp[1000001];

void merge(int st, int en){
    int mid = (st+en)/2;
    int idx0 = 0;
    int idx1 = st;
    int idx2 = mid;
    while(idx1 < mid && idx2 < en)
        if(arr[idx1] < arr[idx2])
            tmp[idx0++] = arr[idx1++];
        else
            tmp[idx0++] = arr[idx2++];
    
    while(idx1 < mid)
        tmp[idx0++] = arr[idx1++];
    while(idx2 < en)
        tmp[idx0++] = arr[idx2++];
    
    for(int i=0; i<en-st; i++){
        arr[st+i] = tmp[i];
        tmp[i] = 0;
    }
}

void merge2(int st, int en){
    if(en - st == 1) return;
    int mid = (st + en) / 2;
    merge2(st, mid);
    merge2(mid, en);
    merge(st, en);
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //int a[5] = {-9, 1, 6, 8, 12};
    //int b[4] = {-7, 7, 13, 15};
    //merge1(a, 5, b, 4);
    merge2(0, n);
    for(int i=0; i<n; i++) cout << arr[i] << " ";
    return 0;
}