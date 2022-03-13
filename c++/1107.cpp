#include <bits/stdc++.h>
using namespace std;
int n, m, minNum;
int minCount = 600000;
int broken[10];
int arr[6]; // 숫자를 담는 변수

int powten(int i){ // 10의 제곱값을 반환함
    if(i == 0) return 1;
    int tmp = 1;
    for(int j=0; j<i; j++)
        tmp = tmp * 10;
    return tmp;
}
void func(int arr[], int k, int count){ // 백트래킹 사용
    if(k > 5){ // k가 5보다 클 경우 -> 10^5의 자리보다 커질 경우
        int tmp = 0;
        for(int i=0; i<6; i++)
            tmp += (arr[i] * powten(5-i)); // arr에 저장된 수를 실제로 환산한다
        
        // 만약 임시 수가 0인데 0이 부숴져서 0으로 바로 접근할 수 없는 경우 최솟값 계산에 포함하지 않는다
        if(tmp == 0 && broken[0] == 1) return;

        // n과 임시 수의 격차가 가장 작은 값을 찾는다
        if((int)abs(n - tmp) < minCount){
            minCount = (int)abs(n - tmp);
            minNum = tmp;
        }
    }
    else{
        for(int i=0; i<10; i++){
            if(broken[i]) // 버튼이 부숴진 경우(유망하지 않은 경우) 탐색하지 않는다
                if((i != 0) || count > 0) continue;
                /*
                 * 0에 대한 특수한 경우를 따로 판단하였다.
                 * 만약 0이 부숴졌는데 다른 숫자가 먼저 입력된 상태에서(count가 0보다 큰 상태에서)
                 * 중간에 0이 들어가는 경우는 불가능하므로 이 경우를 걸러서 탐색하지 않는다
                 * ex) 000001은 가능하지만, 000010은 불가능하다.
                 * 이 경우를 넘어갈 경우 000000은 추후 k>5의 상황에서 따로 구분한다.
                 */
            arr[k] = i;
            if(i != 0)
                func(arr, k+1, count+1); // i를 k번째 자리에 넣을 경우를 탐색한다.
            else
                func(arr, k+1, count); // i가 0인 경우 k번째 자리에 넣되, 숫자 개수를 의미하는 count는 증가시키지 않는다.
        }
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int isBroken = 1; // 모든 버튼이 부숴졌는지 체크
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int tmp;
        cin >> tmp;
        broken[tmp] = 1;
    }
    if(n == 100){ // N이 그대로 100일 경우 함수를 진행할 필요가 없으므로 0을 출력해준다
        cout << 0;
        return 0;
    }
    for(int i=0; i<10; i++)
        if(broken[i] == 0) // 만약 하나의 버튼이라도 멀쩡하다면
            isBroken = 0; // 함수를 진행할 수 있게 만든다
    
    if(isBroken){ // 리모컨이 운명을 다했다면
        cout << (int)abs(100 - n); // +, -만 입력할 수 있으므로 100-n의 절대값을 출력해준다
        return 0;
    }
    func(arr, 0, 0);
    if(n == minNum) // 함수의 결과값이 n이랑 같을 경우 +와 -만 입력해서 이동하는 값과 비교해서 빠른 쪽을 출력한다
        if(to_string(minNum).length() > (int)abs(100 - n))
            cout << (int)abs(100 - n);
        else cout << to_string(minNum).length();
    else // 함수의 결과값이 n보다 크거나 작을 경우 +와 -를 더 누르는 경우를 고려해서 계산한 뒤 비교하여 출력한다.
        if(to_string(minNum).length() + (int)abs(n - minNum) > (int)abs(100 - n))
            cout << (int)abs(100 - n);
        else cout << to_string(minNum).length() + (int)abs(n - minNum);

    return 0;
}

/*
오답 이유
리모컨 부수고 싶었는데 정말 다 부숴진 경우는 생각 못했지
수많은 반례가 있는데 이를 제대로 걸러내지 못해서 오류가 났다
다만 백트래킹 및 완전탐색을 이용하자는 생각은 잘했지만
이것도 어쨌든 '브루트 포스'라는 힌트를 얻고 풀은 거니
일단 기본적으로 브루트 포스로 풀 수 있는지를 먼저 생각해보고
시간 복잡도가 안 될 거 같으면 다른 방법을 찾는 식으로
풀이를 하는 것이 좋을 거 같다
*/