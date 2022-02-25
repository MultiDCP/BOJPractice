#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    
    int arr[n];
    deque<int> d;
    vector<int> result;
    
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        arr[i] = tmp;
        d.push_back(i);
    }
    
    int wasFront = 1;
    
    while(!d.empty()){
        int index;
        if(wasFront){ // 지난 턴에 앞에서 진행함
            index = d.front();
            result.push_back(d.front()+1);
            d.pop_front();
        }
        else{ // 지난 턴에 뒤에서 진행함
            index = d.back();
            result.push_back(d.back()+1);
            d.pop_back();
        }
        
        if(arr[index] > 0){
            arr[index]--;
            for(int i=0; i<arr[index]; i++){
                d.push_back(d.front());
                d.pop_front();
            }
            wasFront = 1;
        }
        else{
            arr[index]++;
            for(int i=0; i<-arr[index]; i++){
                d.push_front(d.back());
                d.pop_back();
            }
            wasFront = 0;
        }
    }
    
    for(int i=0; i<result.size(); i++){
        cout << result[i] << " ";
    }
    
    return 0;
}

/*
언럭키 요세푸스...
왜 요세푸스가 큐를 쓰는지 알 수 있던 문제였다.
다만 이건 앞뒤로 빼서 더 복잡했던듯.
그래도 나름 잘 해결한 거 같다.
*/