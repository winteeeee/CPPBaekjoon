#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

int n, a, l;
vector<pair<int, int>> v(5001);
vector<bool> path[5001];
int dp[5001][5001];

void input() {
    cin >> n >> a >> l;

    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        v[i] = {x, y};

        for(int j = 0; j < 5001; j++) {
            dp[i][j] = INT_MIN;
        }
    }

    for(int j = 0; j < 5001; j++) {
        dp[n][j] = INT_MIN;
    }
}

void solve() {
    const bool A = 0;
    const bool L = 1;
    dp[0][l] = a;

    for(int i = 0; i < n; i++) {
        pair<int, int> attack = v[i];

        for(int life = 1; life <= l; life++) {
            if(dp[i][life] != INT_MIN) {
                if (attack.first == -1 && life - attack.second > 0) {
                    dp[i + 1][life - attack.second] = max(dp[i][life], dp[i + 1][life - attack.second]);
                    path[life - attack.second] = path[life];
                    path[life - attack.second].push_back(L);
                } else if (attack.second == -1) {
                    dp[i + 1][life] = max(dp[i + 1][life], max(dp[i][life] - attack.first, 0));
                    path[life].push_back(A);
                } else {
                    if (life - attack.second > 0) {
                        dp[i + 1][life - attack.second] = max(dp[i][life], dp[i + 1][life - attack.second]);
                        path[life - attack.second] = path[life];
                        path[life - attack.second].push_back(L);
                    }

                    if (dp[i][life] >= attack.first) {
                        dp[i + 1][life] = max(dp[i][life] - attack.first, dp[i + 1][life]);

                        if(attack.second != 0) {
                            path[life].push_back(A);
                        }
                    }
                }
            }
        }
    }

    for(int life = 1; life <= l; life++) {
        if(dp[n][life] >= 0) {
            cout << "YES\n";

            string resultPath;
            for(int i = 0; i < path[life].size(); i++) {
                if(path[life][i]) {
                    resultPath += "L";
                } else {
                    resultPath += "A";
                }
            }

            cout << resultPath;
            exit(0);
        }
    }

    cout << "NO";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solve();
}