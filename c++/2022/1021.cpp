#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    deque<int> d1;
    
    int n, m;
    int result = 0;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        d1.push_back(i);
    }
    deque<int> d2 = d1;

    for(int i=0; i<m; i++){
        int find;
        int front = 0; int back = 0;
        cin >> find;
        
        while(d1.front() != find && d2.front() != find){
            d1.push_back(d1.front());
            d1.pop_front();
            front++;
            
            d2.push_front(d2.back());
            d2.pop_back();
            back++;
        }

        if(d1.front() == find){
            result += front;
            d1.pop_front();
            d2 = d1;
        }
        else{
            result += back;
            d2.pop_front();
            d1 = d2;
        }
        front = 0;
        back = 0;
    }

    cout << result << '\n';

    return 0;
}