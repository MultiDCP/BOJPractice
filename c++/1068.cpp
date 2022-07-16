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
Ʋ�� ����
1. ��Ʈ ��尡 �׻� 0�̶�� ������ ����
2. �ڽ� ��尡 3�� �̻��� ��찡 ������ -> ���� Ʈ����� �翬�� �����ϰ� Ǯ�� Ʋ�� �� ����
*/