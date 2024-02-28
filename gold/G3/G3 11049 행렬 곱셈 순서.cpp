/*
#include <iostream>
#include <climits>
using namespace std;

int DP[501][501];
pair<int, int> mat[501];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        int r, c;
        cin >> r >> c;
        mat[i] = {r, c};
    }

    for(int i = 1; i <= n; i++)
        DP[i][i] = 0;

    for(int i = 0; i < n - 1; i++) {
        int j = 1;
        for (int k = i + 2; k <= n; j++, k++) {
            DP[j][k] = INT_MAX;
            for(int l = j; l < k; l++) {
                int firstR = j;
                int firstC = l;
                int secondR = l + 1;
                int secondC = k;
                int temp = DP[firstR][firstC] + DP[secondR][secondC] +
                           mat[firstR].first * mat[secondR].first * mat[secondC].second;
                if (temp < DP[j][k])
                    DP[j][k] = temp;
            }
        }
    }

    cout << DP[1][n];
    return 0;
}*/
