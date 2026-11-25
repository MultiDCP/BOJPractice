#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000
ll n, b;
ll arr[5][5];
class Matrix{
    public:
        ll mat[5][5];
};

Matrix multiple(Matrix a, Matrix b){
    Matrix newMat;
    for(int i=0; i<n; i++){ // a 행 순회
        for(int j=0; j<n; j++){ // b 열 순회
            ll tmp = 0;
            for(int k=0; k<n; k++){
                tmp += (a.mat[i][k] % MOD) * (b.mat[k][j] % MOD);
            }
            tmp %= MOD;
            newMat.mat[i][j] = tmp;
        }
    }
    return newMat;
}

Matrix func(Matrix mat, ll b){
    if(b > 1){
        mat = func(mat, b/2);
        mat = multiple(mat, mat);
        if(b % 2 == 1){
            Matrix orgMat;
            for(int i=0; i<n; i++)
                for(int j=0; j<n; j++)
                    orgMat.mat[i][j] = arr[i][j];
            
            mat = multiple(mat, orgMat);
        }
    }
    else{
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                mat.mat[i][j] %= MOD;
    }
    return mat;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> b;
    Matrix mat;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
            mat.mat[i][j] = arr[i][j];
        }
    }

    mat = func(mat, b);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cout << mat.mat[i][j] << " ";
        cout << "\n";
    }

    return 0;
}