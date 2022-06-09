#include <bits/stdc++.h>
using namespace std;
int n, m, s; // n은 정점 개수, m은 간선 개수
int visited[1001];  
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> s;
/*
    // 배열 구현
    int graphArr[n+1][n+1];

    for(int i=0; i<=n; i++)
        for(int j=0; j<=n; j++)
            graphArr[i][j] = -1;    
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        graphArr[u][v] = graphArr[v][u] = 1;
        // 단방향은 graph[u][v] = 1;
        // 가중치가 있는 경우 graph[u][v] = 가중치값;
    }
*/
    // 벡터 리스트 구현
    vector<int> graphVec[n+1];
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        graphVec[u].push_back(v);
        sort(graphVec[u].begin(), graphVec[u].end());
        graphVec[v].push_back(u);
        sort(graphVec[v].begin(), graphVec[v].end());
        // 단방향의 경우 graph[u].push_back(v)만 작성
        // 가중치가 있는 경우 vector<pair<int, int>> graph[n+1];로 만들거나
        // 구조체를 만들어 가중치와 함께 저장한다
        // graph[u].push_back(make_pair(v, w)); => u->v 가중치 : w       
    }

    /* 단순 출력 코드
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