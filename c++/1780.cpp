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