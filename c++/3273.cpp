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
en�� st�� ���� �� !=�� ���� �ȵǴ� ����?
-> ���� ���Ƽ� ���� �����ϴ� ������ ����
en�̳� st�� ������ ���ϰ� �迭�� ������ ����
OutOfBound ��Ÿ�� ������ �վ����
*/