#include <bits/stdc++.h>
using namespace std;

int n, m;
void func(int isUsed[], vector<int> arr, int k){
    if(k == m){
        for(int i=0; i<m; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    else{
        for(int i=0; i<n; i++){
            if(isUsed[i]) continue;
            arr.push_back(i+1);
            isUsed[i] = 1;
            func(isUsed, arr, k+1);
            isUsed[i] = 0; // 한 칸 뒤로 올라왔으면 이걸 반드시 해주어야 함.
            arr.pop_back();
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    int isUsed[n];
    for(int i=0; i<n; i++)
        isUsed[i] = 0;
    vector<int> arr;
    func(isUsed, arr, 0);

    return 0;
}

/*
강의에서 힌트를 받아 함께 푼 문제. 복습 필요.
핵심은 수를 추가하기 위해 어떤 수가 수열에 이미 쓰였으며,
어떤 수가 아직 쓰이지 않았는지를 따로 저장하고 있어야 함
또한 값을 각 함수가 알아서 저장하고 있어야 함.
이를 위해 배열 및 벡터를 사용할 수 있음.
*/