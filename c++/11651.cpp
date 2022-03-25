#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n;
pair<int, int> arr[100000];
bool compare(pair<int, int> a, pair<int, int> b){
    if(a.Y == b.Y)
        return a.X < b.X;
    else
        return a.Y < b.Y;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        arr[i] = {a, b};
    }
    sort(arr, arr+n, compare);
    for(int i=0; i<n; i++)
        cout << arr[i].X << " " << arr[i].Y << "\n";

    return 0;
}