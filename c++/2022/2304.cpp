#include <bits/stdc++.h>
using namespace std;
#define L first
#define H second
int n, res;
pair<int, int> a[1000];
stack<pair<int, int>> s;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        int l, h;
        cin >> l >> h;
        a[i] = {l, h};
    }
    // 무작위로 들어오는 경우를 감안하여 L 오름차순 순서로 정렬함
    sort(a, a+n);
    
    int maxH = 0; // 스택 안의 제일 높은 기둥 높이 저장용 변수
    for(int i=0; i<n; i++){
        if(!s.empty() && a[i].H > s.top().H) // top의 기둥보다 높을 경우
            if(a[i].H > maxH) // 스택 안의 가장 높은 기둥보다 높을 경우
                while(s.top().H != maxH) // 해당 기둥이 나올 때까지 pop
                    s.pop();
            else // 스택 안의 가장 높은 기둥보단 낮을 경우
                while(s.top().H < a[i].H) // 내림차순이 만들어질 때까지 pop
                    s.pop();
        maxH = max(maxH, a[i].H); // 스택 내 기둥 최대 높이 갱신
        s.push(a[i]);
    }

    while(!s.empty()){
        auto cur = s.top();
        s.pop();
        res += cur.H; // 현재 기둥이 차지하는 넓이룰 더해줌
        if(s.empty()) continue;
        // top의 기둥과 현재 기둥 사이의 여분 면적을 계산함
        if(cur.H < s.top().H)
            res += (cur.L - (s.top().L + 1)) * cur.H;
        else
            res += (cur.L - (s.top().L + 1)) * s.top().H;
    }
    cout << res;

    return 0;
}

/*
오답 정리
개억까라고 생각했지만 억까한 건 나 자신이었구요
스택 안에 있는 가장 높은 기둥보다 더 높은 기둥이 나오는 경우는 잘 걸러냈지만
스택 안에 있는 가장 높은 기둥보다는 낮지만
스택의 top에 있는 기둥보다 큰 경우를 제대로 걸러내지 못했다
*/