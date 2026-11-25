#include <iostream>
using namespace std;

// 미해결

void NumberCheck(int arr[][6]){
    for(int i=0; i<6; i++){
        for(int j=0; j<6; j++){
            if(arr[i][j] > 9){
                arr[i][j] = 0;
            }
            else if(arr[i][j] < 0){
                arr[i][j] = 9;
            }
        }
    }
}

void FunctionOne(int arr[][6], int i){
    for(int j=0; j<6; j++){
        arr[i][j]++;
    }
    NumberCheck(arr);
}

void FunctionTwo(int arr[][6], int i){
    for(int j=0; j<6; j++){
        arr[i][j]--;
    }
    NumberCheck(arr);
}

void FunctionThree(int arr[][6], int i){
    for(int j=0; j<6; j++){
        arr[j][i]++;
    }
    NumberCheck(arr);
}

void FuntionFour(int arr[][6], int i){
    for(int j=0; j<6; j++){
        arr[j][i]--;
    }
    NumberCheck(arr);
}

void FunctionFive(int arr[][6]){
    for(int i=0; i<6; i++){
        arr[i][i]++;
    }
    NumberCheck(arr);
}

void FunctionSix(int arr[][6]){
    int j = 5;
    for(int i=0; i<6; i++){
        arr[i][j]++;
        j--;
    }
    NumberCheck(arr);
}

void FunctionSeven(int arr[][6]){
    for(int i=0; i<6; i++){
        arr[i][i]--;
    }
    NumberCheck(arr);
}

void FunctionEight(int arr[][6]){
    int j = 5;
    for(int i=0; i<6; i++){
        arr[i][j]--;
        j--;
    }
    NumberCheck(arr);
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[6][6];
    int max = -1;

    for(int i=0; i<6; i++){
        for(int j=0; j<6; j++){
            cin >> arr[i][j];
        }
    }

    return 0;

}