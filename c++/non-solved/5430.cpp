#include <bits/stdc++.h>
using namespace std;

deque<int> d;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n;
    string p, x;
    cin >> t;

    for(int i=0; i<t; i++){
        cin >> p >> n >> x;
        char c[100001];
         
        bool isError = false;
        vector<string> v;

        x.erase(x.begin());
        x.erase(x.end()-1);
        if(x != ""){
            char *c = new char(x.size()+1);
            copy(x.begin(), x.end(), c);
            c[x.size()] = '\0';
    
            char *ptr = strtok(c, ",");
            while(ptr != NULL){
                d.push_back(atoi(ptr));
                ptr = strtok(NULL, ",");
            }
            delete[] c;
        }
        
        for(int j=0; j<p.length(); j++){
            if(p[j] == 'D'){
                if(!d.empty())
                    d.pop_front();
                else{
                    cout << "error\n";
                    isError = true;
                    break;
                }
            }
            else if(p[j] == 'R'){
                if(j != p.length()-1 && p[j+1] == 'R'){
                    j++;
                    continue;
                }
                else{
                    reverse(d.begin(), d.end());
                }
            }
        }

        if(!isError){
            int tmp = d.size();
            cout << "[";
            while(!d.empty()){
                cout << d.front();
                d.pop_front();
                if(!d.empty()){
                    cout << ",";
                }
            }
            cout << "]";
        }
    }

    return 0;
}

/*
오답 정리
깃에다 올리는 거라 차마 욕은 못하겠다
시간 단축을 위해 모든 방법을 써야 하긴 했을듯
다음은 차마 내가 생각하지 못한 시간 단축 방법이다
1. 뒤집는 명령이 나올 때 직접 뒤집지 않고 앞뒤에서 차례로 출력하는 식으로 할 수 있다
내가 너무 한 쪽에서만 제거하는 것을 생각했음
다시 알고리즘을 이 자리에서 생각해본다면
뒤집혔는지 여부를 파악하고
뒤집혔을 때는 뒤에서, 안 뒤집혔을 때는 앞에서 뽑는 식으로 처리가 가능하다
최종 출력 때 앞이면 앞 뒤면 뒤 이렇게 판단할 수 있었다
어떻게 보면 뒤집는 거 자체가 의미 없이 시간만 잡아먹는 행동이었다
2. 벡터를 활용해 문자열 쪼개기 이런 건 별로였다.
이렇게 해서 틀린 사람들이 있었음.
O(N)에 끝낼 수 있는 최적의 방법이 필요하긴 한데
그냥 문자열 쓱 돌면서 temp에 집어넣고
,나 [, ]가 나올 때 temp를 int로 바꿔서 집어넣은 뒤 초기화하는 그런 식으로 할 수 있다
3. 문제 자체에 너무 옭매였다
이건 내 자존심 싸움이 아니라 사실상 수능공부라는 걸 잊지 말자
4. char * 계열 다시는 쓰지 마라
런타임 에러 원인도 안 보여주는데 진짜 정신 나갈 거 같다
필요없는 상황인데 한 번 더 쓰면 손모가지 분지를거니
앞으로는 string을 애용하자
*/