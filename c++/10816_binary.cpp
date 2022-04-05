#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> a;
bool binary(int target, int len){
    int st = 0; 
    int en = len-1;
    while(st <= en){
        int mid = (st+en) / 2;
        if(a[mid] == target)
            return true;
        else if(a[mid] > target)
            en = mid-1;
        else
            st = mid+1;
    }
    return false;
}
int lower_idx(int target, int len){
    int st = 0;
    int en = len;
    while(st < en){
        int mid = (st + en) / 2;
        if(a[mid] >= target) en = mid;
        else st = mid + 1;
    }
    return st;
}

int upper_idx(int target, int len){
    int st = 0;
    int en = len;
    while(st < en){
        int mid = (st + en) / 2;
        if(a[mid] > target) en = mid;
        else st = mid + 1;
    }
    return st;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    sort(a.begin(), a.end());

    cin >> m;
    for(int i=0; i<m; i++){
        int tmp;
        cin >> tmp;
        if(binary(tmp, a.size()))
            cout << upper_idx(tmp, a.size()) - lower_idx(tmp, a.size()) << " ";
        else cout << 0 << " ";
    }

    return 0;
}

/*
강의와 함께 진행함. 복습 필요
*/