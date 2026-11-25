#include <bits/stdc++.h>
using namespace std;
int n, m, p, res;
vector<char> v[26];
bool isCht[26];
bool isNotMain[26];

queue<char> q;
bool vis[26];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<m; i++){
        char from, to;
        cin >> from >> to;
        v[(from - 'A')].push_back(to);
        isNotMain[(to - 'A')] = true;
    }

    cin >> p;
    for(int i=0; i<p; i++){
        char cht;
        cin >> cht;
        v[cht - 'A'].clear();
        isCht[cht - 'A'] = true;
    }

    for(int i=0; i<n; i++){
        if(!isNotMain[i]){
            char startNode = i + 'A';
            q.push(startNode);

            while(!q.empty()){
                char tmp = q.front();
                q.pop();

                if(vis[tmp - 'A']) continue;
                if(isCht[tmp - 'A']) continue;
                
                vis[tmp - 'A'] = true;
                if(tmp != startNode)
                    res++;

                for(char k : v[tmp - 'A'])
                    q.push(k);
            }
        }
    }
    
    cout << res << "\n";

    return 0;
}