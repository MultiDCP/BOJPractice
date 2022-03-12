#include <bits/stdc++.h>
using namespace std;
int n, m, minNum;
int minCount = 600000;
int broken[10];
int arr[6];

int powten(int i){
    if(i == 0) return 1;
    int tmp = 1;
    for(int j=0; j<i; j++)
        tmp = tmp * 10;
    return tmp;
}
void func(int arr[], int k, int count){
    if(k > 5){
        int tmp = 0;
        for(int i=0; i<6; i++)
            tmp += (arr[i] * powten(5-i));
        
        if(tmp == 0 && broken[0] == 1) return;

        if((int)abs(n - tmp) < minCount){
            minCount = (int)abs(n - tmp);
            minNum = tmp;
        }
    }
    else{
        for(int i=0; i<10; i++){
            if(broken[i]) 
                if((i != 0) || count > 0) continue;
            arr[k] = i;
            if(i != 0)
                func(arr, k+1, count+1);
            else
                func(arr, k+1, count);
        }
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int isBroken = 1;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int tmp;
        cin >> tmp;
        broken[tmp] = 1;
    }
    if(n == 100){
        cout << 0;
        return 0;
    }
    for(int i=0; i<10; i++)
        if(broken[i] == 0)
            isBroken = 0;
    
    if(isBroken){
        cout << (int)abs(100 - n);
        return 0;
    }
    func(arr, 0, 0);
    if(n == minNum)
        if(to_string(minNum).length() > (int)abs(100 - n))
            cout << (int)abs(100 - n);
        else cout << to_string(minNum).length();
    else
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