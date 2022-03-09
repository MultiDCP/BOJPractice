#include <bits/stdc++.h>
using namespace std;

int arr[2187][2187];
int counts[3];
void func(int n, int x, int y){
    if(n == 1) {
        ++counts[arr[x][y] + 1];
        return;
    }
    int sum = 0; bool isSame = true;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            sum += arr[x+i][y+j];
            if(arr[x+i][y+j] != arr[x][y])
                isSame = false;
        }
    }
    if(sum == 0 || sum == (n*n) || sum == (n*n*-1))
        if(isSame){
            ++counts[arr[x][y] + 1];
            return;
        }
        
    if(n / 3 != 1)
        for(int i=0; i<3; i++)
            for(int j=0; j<3; j++)
                func(n/3, x+n/3*i, y+n/3*j);
    else
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                ++counts[arr[x+i][y+j] + 1];
    
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> arr[i][j];
    
    func(n, 0, 0);
    
    for(int i=0; i<3; i++)
        cout << counts[i] << "\n";

    return 0;
}

/*
오답 정리
오답의 원인은 다른 데에 있었는데 엉뚱한 데를 자꾸 디버깅하고 있었다
재귀를 돌리는 과정에서 x와 y의 원래 값을 n/3*i에 더해줘야 보정이 돼서
다음 함수에도 그 좌표가 유지가 되는데
멍청하게 이상한 곳에서 반례를 찾고 있었다
쉽게 말해 내가 했던 모든 삽질은 어짜피 시간이나 공간 측면에서
굉장히 너그러운 문제였기 때문에 최적화는 사실상 상관 없었고
그거 보정 하나 안 해서 몇 시간을 날려먹게 된 것이었다
좌표 가지고 재귀 돌릴 때는 보정 똑바로 해라
이 억까를 내가 자초했다는 게 더 화난다
심지어 이거 아니었다면
남들보다 메모리나 시간 측면에서 더 나았다는 게 더 어이가 없다
*/