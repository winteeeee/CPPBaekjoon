/*
#include <iostream>
using namespace std;

long long dp[101][10][1 << 10];
const int MOD = 1000000000;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    long long result = 0;
    cin >> n;
    if(n < 10)
        cout << "0";

    else {
        for (int i = 1; i < 10; i++) {
            dp[1][i][1 << i] = 1;
        }

        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < (1 << 10); k++) {
                    int curBit = k | (1 << j);

                    if (j == 0)
                        dp[i][j][curBit] = (dp[i][j][curBit] % MOD + dp[i - 1][j + 1][k] % MOD) % MOD;

                    else if (j == 9)
                        dp[i][j][curBit] = (dp[i][j][curBit] % MOD + dp[i - 1][j - 1][k] % MOD) % MOD;

                    else
                        dp[i][j][curBit] = (dp[i][j][curBit] % MOD + dp[i - 1][j - 1][k] % MOD + dp[i - 1][j + 1][k] % MOD) % MOD;
                }

                if(i == n)
                    result = (result % MOD + dp[i][j][(1 << 10) - 1] % MOD) % MOD;
            }
        }

        cout << result % MOD;
    }
    return 0;
}*/
