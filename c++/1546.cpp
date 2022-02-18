#include <iostream>
#include <vector>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int tempScore;
    vector<double> score;
    int max = -1;

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> tempScore;
        score.push_back(double(tempScore));

        if(max < tempScore)
            max = tempScore;
    }

    double sum;

    for(int i=0; i<n; i++){
        score[i] = (score[i] / max) * 100;
        sum += score[i];
    }

    double avg = sum / n;
    cout << fixed;
    cout.precision(6);
    cout << avg << endl;

    return 0;
}