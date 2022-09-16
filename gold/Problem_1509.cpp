/*
#include <iostream>
#include <stack>
#include <climits>
using namespace std;

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;
    const int SIZE = str.size();
    bool DP[SIZE][SIZE];
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++) {
            DP[i][j] = false;
        }
    }

    for(int i = 0; i < SIZE; i++) {
        DP[i][i] = true;
    }

    for(int i = 0; i < SIZE - 1; i++) {
        if(str[i] == str[i + 1])
            DP[i][i + 1] = true;
    }

    for(int i = 2; i < SIZE; i++) {
        for(int j = 0; j + i < SIZE; j++) {
            if(str[j] == str[i + j] && DP[j + 1][i + j - 1])
                DP[j][i + j] = true;
        }
    }

    int minNum[SIZE + 1];
    minNum[0] = 0;
    for(int i = 1; i <= SIZE; i++) {
        minNum[i] = INT_MAX;
        for(int j = 1; j <= i; j++) {
            if(DP[j - 1][i - 1]) {
                minNum[i] = min(minNum[i], minNum[j - 1] + 1);
            }
        }
    }

    cout << minNum[SIZE];
    return 0;
}*/
