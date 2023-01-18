/*
#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <stack>
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
                    if(life - attack.second > 0 && dp[i + 1][life - attack.second] < dp[i][life]) {
                        dp[i + 1][life - attack.second] = dp[i][life];
                        path[i + 1][life - attack.second] = L;
                    }
                } else if (attack.second == -1) {
                    int val = max(dp[i][life] - attack.first, 0);

                    if(dp[i + 1][life] < val) {
                        dp[i + 1][life] = val;
                        path[i + 1][life] = A;
                    }
                } else {
                    if (life - attack.second > 0 && dp[i + 1][life - attack.second] < dp[i][life]) {
                        dp[i + 1][life - attack.second] = dp[i][life];
                        path[i + 1][life - attack.second] = L;
                    }

                    if (dp[i][life] >= attack.first && dp[i + 1][life] < dp[i][life] - attack.first) {
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

            stack<char> s;
            int curLife = life;
            for(int i = n; i > 0; i--) {
                if(path[i][curLife]) {
                    s.push('L');
                    curLife += v[i - 1].second;
                } else {
                    s.push('A');
                }
            }

            while(!s.empty()) {
                cout << s.top(); s.pop();
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
}*/
