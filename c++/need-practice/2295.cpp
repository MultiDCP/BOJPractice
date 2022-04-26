#include <bits/stdc++.h>
using namespace std;
int n, d;
int a[1000];
vector<int> v;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];
    sort(a, a+n);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            d = a[i] + a[j];
            v.push_back(d);
        }
    }
    sort(v.begin(), v.end());
    int tmp;
    for(int i=n-1; i>=0; i--)
        for(int j=0; j<i; j++)
            if(binary_search(v.begin(), v.end(), a[i]-a[j])){
                cout << a[i];
                return 0;
            }

    return 0;
}

/*
���� ����
�̰� ���� ������ �ؾ߰ڴ�
�� �� �̺�Ž���� ��¥ ������ ���ϴ� �ɱ�

1. ���� ���� ��ü�� �۷��Ծ���
�ƹ� ���� �ߺ����� ��� �ϸ� �Ǵ� �Ÿ� ������ �� ���� ��ã�� �־���
2003�� ���� Ǯ�ٰ� �� ȸ�ΰ� ������ �Ȱ��� ������ �� ����
2. �ڵ� �ٺ��̳� ���� ����̳� �� �۷��Ծ���
a + b + c = d �� a + b = d - c�� �����ϴ� �ָ� ã�Ƶ� �ȴ�
�׷��� O(N^3)���� O(N^2)�� �پ��ϱ�
�ٵ� �� ����� Ǯ�̸� ����� �������� ���޾Ұ�
���ٵ� �����ϰ� �ϸ鼭 Ʋ�� �ڵ带 �ڲ� �����ϰ� ������
������ ��� ���� ���ۿ� ����
�׸��� �̺� Ž���� �ٷ� ������ �Ǵ� ���� �ε��� ã�Ƽ� �ذ��ϰڴٰ�
�׷��ٰ� Meet in the middle �Ẹ�ڴٰ�
������ �������� �ϰ� �־���
3. ���� ���� ���� ���Ѵ�
���� ���� �� ��µ� ���� �� ��� �ؾ��Ѵ� ���ΰ�
*/