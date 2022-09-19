/*
#include <iostream>
using namespace std;

const int MOD = 1000000000;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    long long result = 0;
    cin >> n;
    long long dp[n + 1][10];
    dp[1][0] = 0;
    for(int i = 1; i < 10; i++)
        dp[1][i] = 1;

    for(int i = 2; i <= n; i++) {
        for(int j = 0; j < 10; j++) {
            if(j == 0)
                dp[i][j] = dp[i - 1][j + 1] % MOD;

            else if(j == 9)
                dp[i][j] = dp[i - 1][j - 1] % MOD;

            else
                dp[i][j] = (dp[i - 1][j - 1] % MOD + dp[i - 1][j + 1] % MOD) % MOD;

            if(i == n)
                result += dp[i][j];
        }
    }

    if(n != 1)
        cout << result % MOD;

    else
        cout << "9";
    return 0;
}*/
