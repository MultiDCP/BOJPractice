#include <iostream>
#include <vector>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c;
    double max = -1;

    cin >> a >> b >> c;

    vector<double> result;

    result.push_back((double(a) * double(b)) / double(c));
    result.push_back(double(a) * (double(b) / double(c)));
    result.push_back((double(a) / double(b)) * double(c));
    result.push_back(double(a) / (double(b) * double(c)));

    for(int i=0; i<result.size(); i++){
        if(max < result[i]){
            max = result[i];
        }
    }

    cout << (long long)(max) << endl;
    return 0;
}

/*
브4 문제 따위에 무수히 많은 오답을 낸 이유
참고 답안 : https://j3sung.tistory.com/188

1. 오버플로우 및 언더플로우를 고려하지 못함
치명적이면서 전혀 간과하지 못한 주요한 오답 원인. 테스트 케이스를 여러 번 입력해보지 못했다.
값이 최대가 나올 수 있는 경우에 대해 미리 테스트를 거쳤어야 했으나 그러지 못함.
최대 입력값인 1000000 1000000 1을 넣었을 때, 1000000000000이 출력이 되어야 하나
자료형의 바이트 수 한계로 더 이상 값이 입력되지 못하고 오버플로우를 발생시킴.

2. 디버그 코드를 제대로 지우지 못함
절반의 오답을 낸 원인. 출력 형식이 잘못되거나 엉뚱한 답을 낸 것으로 인식하여 오답 처리가 됨.
출력과 같은 디버그 코드는 반드시 확인하고 지워야 하나
마음이 급하여 제대로 컴파일-실행 디버그 과정을 거치지 않고 바로 제출해버림.
*/