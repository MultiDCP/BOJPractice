#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
pair<int, int> a[3];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i=0; i<3; i++)
        cin >> a[i].X >> a[i].Y;
    sort(a, a+3);
    int sameX, sameY;
    for(int i=0; i<2; i++){
        for(int j=i+1; j<3; j++){
            if(a[i].X == a[j].X) sameX = a[i].X;
            if(a[i].Y == a[j].Y) sameY = a[i].Y;
        }
    }
    int nx, ny;
    for(int i=0; i<3; i++){
        if(a[i].X == sameX && a[i].Y != sameY) ny = a[i].Y;
        if(a[i].Y == sameY && a[i].X != sameX) nx = a[i].X;
    }
    cout << nx << " " << ny;

    return 0;
}