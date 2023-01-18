#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

int n, a, l;
pair<int, int> v[5001];
vector<vector<bool>> path(5001, vector<bool>(5001));
int dp[5001][5001];

void input() {
    cin >> n >> a >> l;

    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        v[i] = {x, y};
    }
}

void dpInit() {
    for(int i = 0; i < 5001; i++) {
        for(int j = 0; j < 5001; j++) {
            dp[i][j] = INT_MIN;
        }
    }
}

void solve() {
    dpInit();
    const bool A = 0;
    const bool L = 1;
    dp[0][l] = a;

    for(int i = 0; i < n; i++) {
        pair<int, int> attack = v[i];

        for(int life = 1; life <= l; life++) {
            if(dp[i][life] != INT_MIN) {
                if (attack.first == -1) {
                    if(life - attack.second > 0) {
                        dp[i + 1][life - attack.second] = dp[i][life];
                        path[i + 1][life - attack.second] = L;
                    }
                } else if (attack.second == -1) {
                    dp[i + 1][life] =  max(dp[i][life] - attack.first, 0);
                    path[i + 1][life] = A;
                } else {
                    if (life - attack.second > 0) {
                        dp[i + 1][life - attack.second] = dp[i][life];
                        path[i + 1][life - attack.second] = L;
                    }

                    if (dp[i][life] >= attack.first && attack.second != 0) {    //attack.second != 0 필요하지 않나?
                        dp[i + 1][life] = dp[i][life] - attack.first;
                        path[i + 1][life] = A;
                    }
                }
            }
        }
    }

    for(int life = 1; life <= l; life++) {
        if(dp[n][life] >= 0) {
            cout << "YES\n";

            vector<char> resultPath;
            int curLife = life;
            for(int i = n; i >= 0; i--) {
                if(path[i][curLife]) {
                    resultPath.push_back('L');
                } else {
                    resultPath.push_back('A');
                }

                if(path[i][curLife]) {
                    curLife -= v[i].second;
                }
            }

            for(int i = 0; i < resultPath.size(); i++) {
                cout << resultPath[i];
            }
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