/*
#include <iostream>
#include <queue>
using namespace std;

int n, m;
char map[601][601];
bool visited[601][601];
pair<int, int> me;
int x[4] = {1, -1, 0, 0};
int y[4] = {0, 0, 1, -1};
int result;

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];

            if (map[i][j] == 'I') {
                me = {i, j};
            }
        }
    }
}

void solve() {
    queue<pair<int, int>> q;
    visited[me.first][me.second] = true;
    q.push(me);

    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            if (!visited[cur.first + y[i]][cur.second + x[i]] &&
                    (0 <= cur.first + y[i] && cur.first + y[i] < n) &&
                    (0 <= cur.second + x[i] && cur.second + x[i] < m) &&
                    (map[cur.first + y[i]][cur.second + x[i]] != 'X')) {
                visited[cur.first + y[i]][cur.second + x[i]] = true;
                if (map[cur.first + y[i]][cur.second + x[i]] == 'P') {
                    result++;
                }

                q.emplace(cur.first + y[i], cur.second + x[i]);
            }
        }
    }

    if (result) {
        cout << result;
    } else {
        cout << "TT";
    }
}

int main() {
    input();
    solve();

    return 0;
}*/
