#include <bits/stdc++.h>
using namespace std;
int n, rm, root, res;
vector<int> v[51];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        int nd;
        cin >> nd;
        if(nd == -1)
            root = i;
        else
            v[nd].push_back(i);
    }

    cin >> rm;
    if(rm == root){
        cout << 0;
        return 0;
    }
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int tm = q.front();
        q.pop();
        for(int i : v[tm])
            if(i == rm)
                v[tm].erase(find(v[tm].begin(), v[tm].end(), i));
            else
                q.push(i);
    }

    while(!q.empty())
        q.pop();
    
    q.push(root);
    while(!q.empty()){
        int tm = q.front();
        q.pop();
        if(v[tm].empty()) res++;
        else
            for(int i : v[tm])
                q.push(i);
    }

    cout << res;

    return 0;
}

/*
틀린 이유
1. 루트 노드가 항상 0이라는 보장이 없음
2. 자식 노드가 3개 이상일 경우가 존재함 -> 이진 트리라고 당연히 생각하고 풀면 틀릴 수 있음
*/