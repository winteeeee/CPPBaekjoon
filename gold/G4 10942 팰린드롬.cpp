/*
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int SIZE;
    cin >> SIZE;
    int sequence[SIZE];

    for(int i = 0; i < SIZE; i++)
        cin >> sequence[i];

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
        if(sequence[i] == sequence[i + 1])
            DP[i][i + 1] = true;
    }

    for(int i = 2; i < SIZE; i++) {
        for(int j = 0; j + i < SIZE; j++) {
            if(sequence[j] == sequence[i + j] && DP[j + 1][i + j - 1])
                DP[j][i + j] = true;
        }
    }

    int m;
    cin >> m;

    for(int i = 0; i < m; i++) {
        int start, end;
        cin >> start >> end;

        if(DP[start - 1][end - 1])
            cout << "1\n";
        else
            cout << "0\n";
    }

    return 0;
}*/
