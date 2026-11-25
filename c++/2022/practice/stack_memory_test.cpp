#include <bits/stdc++.h>
using namespace std;

void test(int a){
    if(a>0) test(a-1);
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    test(35000);
    cout << "DONE";

    return 0;
}