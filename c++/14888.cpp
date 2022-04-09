#include <bits/stdc++.h>
using namespace std;
int n;
int maxE = -0x7f7f7f7f;
int minE = 0x7f7f7f7f;
int a[11];
vector<char> oper;
bool isUsedOper[10];
void calc(int numCount, int result){
    if(numCount == n-1){
        maxE = max(maxE, result);
        minE = min(minE, result);
    }
    else{
        if(numCount == 0)
            result += a[0];
        int origResult = result;
        for(int i=0; i<n-1; i++){
            if(isUsedOper[i]) continue;
            if(oper[i] == '+')
                result += a[numCount+1];
            else if(oper[i] == '-')
                result -= a[numCount+1];
            else if(oper[i] == '*')
                result *= a[numCount+1];
            else if(oper[i] == '/')
                result /= a[numCount+1];
            isUsedOper[i] = true;
            calc(numCount+1, result);
            isUsedOper[i] = false;
            result = origResult;
        }  
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];
    for(int i=0; i<4; i++){
        int tmp;
        cin >> tmp;
        switch(i){
            case 0:
                for(int j=0; j<tmp; j++)
                    oper.push_back('+');
                break;
            case 1:
                for(int j=0; j<tmp; j++)
                    oper.push_back('-');
                break;
            case 2:
                for(int j=0; j<tmp; j++)
                    oper.push_back('*');
                break;
            case 3:
                for(int j=0; j<tmp; j++)
                    oper.push_back('/');
                break;
        }
    }
    calc(0, 0);
    cout << maxE << "\n" << minE;

    return 0;
}