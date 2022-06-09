#include <bits/stdc++.h>
using namespace std;
int n, m, s; // n�� ���� ����, m�� ���� ����
int visited[1001];  
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> s;
/*
    // �迭 ����
    int graphArr[n+1][n+1];

    for(int i=0; i<=n; i++)
        for(int j=0; j<=n; j++)
            graphArr[i][j] = -1;    
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        graphArr[u][v] = graphArr[v][u] = 1;
        // �ܹ����� graph[u][v] = 1;
        // ����ġ�� �ִ� ��� graph[u][v] = ����ġ��;
    }
*/
    // ���� ����Ʈ ����
    vector<int> graphVec[n+1];
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        graphVec[u].push_back(v);
        sort(graphVec[u].begin(), graphVec[u].end());
        graphVec[v].push_back(u);
        sort(graphVec[v].begin(), graphVec[v].end());
        // �ܹ����� ��� graph[u].push_back(v)�� �ۼ�
        // ����ġ�� �ִ� ��� vector<pair<int, int>> graph[n+1];�� ����ų�
        // ����ü�� ����� ����ġ�� �Բ� �����Ѵ�
        // graph[u].push_back(make_pair(v, w)); => u->v ����ġ : w       
    }

    /* �ܼ� ��� �ڵ�
    int s;
    cin >> s;
    for(int i : graphVec[s]){
        cout << i << " ";
    }
    cout << "\n";
    */

    stack<int> st;
    cout << s << " ";
    visited[s] = 1;
    for(int i=graphVec[s].size()-1; i>=0; i--){
        st.push(graphVec[s][i]);
    }
    while(!st.empty()){
        int tmp = st.top();
        st.pop();
        if(visited[tmp] == 1) continue;
        cout << tmp << " ";
        visited[tmp] = 1;
        for(int i=graphVec[tmp].size()-1; i>=0; i--){
            st.push(graphVec[tmp][i]);
        }
    }
    cout << "\n";

    for(int i=0; i<=n; i++)
        visited[i] = 0;

    queue<int> q; // BFS
    cout << s << " ";

    visited[s] = 1;
    for(int i : graphVec[s]){
        q.push(i);
    }
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        if(visited[tmp] == 1) continue;
        cout << tmp << " ";
        visited[tmp] = 1;
        for(int i : graphVec[tmp]){
            q.push(i);
        }
    }
    cout << "\n";
    

    return 0;
}