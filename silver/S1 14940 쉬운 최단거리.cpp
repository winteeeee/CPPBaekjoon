/*
#include <iostream>
#include <queue>
using namespace std;

int n, m;
int map[1001][1001];
int result[1001][1001];
bool visited[1001][1001];
pair<int, int> target;
int x[4] = {1, -1, 0, 0};
int y[4] = {0, 0, 1, -1};

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];

            if (map[i][j] == 2) {
                target = {i, j};
            }
        }
    }
}

void solve() {
    queue<pair<int, int>> q;
    result[target.first][target.second] = 0;
    visited[target.first][target.second] = true;
    q.push(target);

    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            if ((0 <= cur.first + x[i] && cur.first + x[i]) < n && (0 <= cur.second + y[i] && cur.second + y[i] < m)) {
                if (map[cur.first + x[i]][cur.second + y[i]] != 0 && !visited[cur.first + x[i]][cur.second + y[i]]) {
                    result[cur.first + x[i]][cur.second + y[i]] = result[cur.first][cur.second] + 1;
                    visited[cur.first + x[i]][cur.second + y[i]] = true;
                    q.emplace(cur.first + x[i], cur.second + y[i]);
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] != 0 && !visited[i][j]) {
                cout << -1 << " ";
            } else {
                cout << result[i][j] << " ";
            }
        }
        cout << '\n';
    }
}

int main() {
    input();
    solve();

    return 0;
}*/
