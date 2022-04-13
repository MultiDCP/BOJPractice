#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define MOD 1000000007
ull n;
class Matrix{
public:
    ull mat[4];
};
Matrix multiple(Matrix mat1, Matrix mat2){
    Matrix newMat = Matrix();
    newMat.mat[0] = (mat1.mat[0] % MOD) * (mat2.mat[0] % MOD) + (mat1.mat[1] % MOD) * (mat2.mat[2] % MOD);
    newMat.mat[0] %= MOD;
    newMat.mat[1] = (mat1.mat[0] % MOD) * (mat2.mat[1] % MOD) + (mat1.mat[1] % MOD) * (mat2.mat[3] % MOD);
    newMat.mat[1] %= MOD;
    newMat.mat[2] = (mat1.mat[2] % MOD) * (mat2.mat[0] % MOD) + (mat1.mat[3] % MOD) * (mat2.mat[2] % MOD);
    newMat.mat[2] %= MOD;
    newMat.mat[3] = (mat1.mat[2] % MOD) * (mat2.mat[1] % MOD) + (mat1.mat[3] % MOD) * (mat2.mat[3] % MOD);
    newMat.mat[3] %= MOD;
    return newMat;
}

Matrix fib(Matrix mat, ull n){
    if(n > 1){
        mat = fib(mat, n/2);
        mat = multiple(mat, mat);
        if(n % 2 == 1){
            Matrix newMat = {1, 1, 1, 0};
            mat = multiple(mat, newMat);
        }
    }
    return mat; // ������(n = 1) {1,1,1,0}��
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    Matrix newMat = {1, 1, 1, 0};
    newMat = fib(newMat, n);
    cout << newMat.mat[1];

    return 0;
}

/*
��Ʈ : ��İ� ���������� ����ؾ� �Ѵ�.
��Ʈ�� �ް� Ǯ�̸� �����ϸ� Ǯ����. ���� �ݵ�� �ʿ�.
������ �ʿ��� �κ� : �Ǻ���ġ�� ������������ �����ϴ� ��Ŀ����, ����� �ŵ�����
*/