/*
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> sequence;
int dp[100001][5][5];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(1) {
        int temp;
        cin >> temp;
        if(temp == 0)
            break;

        sequence.push_back(temp);
    }

    dp[0][sequence[0]][0] = 2;
    dp[0][0][sequence[0]] = 2;
    for(int i = 1; i < sequence.size(); i++) {
        for(int j = 0; j < 5; j++) {
            for(int k = 0; k < 5; k++) {
                if(dp[i - 1][j][k] != 0) {
                    int leftVal;
                    int rightVal;

                    if(sequence[i] == j)
                        leftVal = 1;
                    else if(j == 0)
                        leftVal = 2;
                    else if(abs(sequence[i] - j) != 2)
                        leftVal = 3;
                    else
                        leftVal = 4;

                    if(sequence[i] == k)
                        rightVal = 1;
                    else if(k == 0)
                        rightVal = 2;
                    else if(abs(sequence[i] - k) != 2)
                        rightVal = 3;
                    else
                        rightVal = 4;

                    int leftUpdate = min(dp[i - 1][j][k], dp[i - 1][k][j]) + leftVal;
                    int rightUpdate = min(dp[i - 1][j][k], dp[i - 1][k][j]) + rightVal;

                    if(leftUpdate < dp[i][sequence[i]][k] || dp[i][sequence[i]][k] == 0)
                        dp[i][sequence[i]][k] = leftUpdate;
                    if(rightUpdate < dp[i][j][sequence[i]] || dp[i][j][sequence[i]] == 0)
                        dp[i][j][sequence[i]] = rightUpdate;
                }
            }
        }
    }

    int result = INT_MAX;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(dp[sequence.size() - 1][i][j] < result && dp[sequence.size() - 1][i][j] != 0)
                result = dp[sequence.size() - 1][i][j];
        }
    }

    cout << result;
    return 0;
}*/
