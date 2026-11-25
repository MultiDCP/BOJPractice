#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int tc;
    cin >> tc;
    
    for(int i=0; i<tc; i++){
        int n, m;
        cin >> n >> m;
        
        queue<int> q;
        int max = -1;
        int myNum; // 내 문서
        int myPos = m;
        
        for(int j=0; j<n; j++){
            int tmp;
            cin >> tmp;
            if(j == m)
                myNum = tmp;
            if(tmp > max)
                max = tmp;
            q.push(tmp);
        }
        
        int count = 1;
        
        while(!q.empty()){
            if(myNum == max && myPos == 0){
                cout << count << '\n';
                break;
            }
            
            if(q.front() == max && myPos != 0){
                q.pop();
                count++;
                max = -1;
                for(int j=0; j<q.size(); j++){
                    if(q.front() > max)
                        max = q.front();
                    q.push(q.front());
                    q.pop();
                }
                myPos--;
            }
            else{
                q.push(q.front());
                q.pop();
                if(myPos != 0){
                    myPos--;
                }
                else
                    myPos = q.size() - 1;
            }
        }
    }
    return 0;
}

/*
문제 풀 때 '중요도가 같은 경우'를 신경쓰지 못했다.
그래서 시간이 조금 더 들어갔다.
모든 경우에 다 만족할 수 있도록 설계를 해야한다.
*/