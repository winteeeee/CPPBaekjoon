#include <iostream>
#include <queue>
using namespace std;

int n, m;
bool isWall[1000][1000];
int result[1000][1000];
int rowMoveSet[4] = {1, -1, 0, 0};
int columnMoveSet[4] = {0, 0, 1, -1};

void input() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        string temp;
        cin >> temp;

        for(int j = 0; j < m; j++) {
            if(temp[j] == '1') {
                isWall[i][j] = 1;
            } else {
                isWall[i][j] = 0;
            }
        }
    }
}

int countMovable(int r, int c) {
    bool visited[1000][1000] = {0};
    int count = 1;
    queue<pair<int, int>> q;
    q.push({r, c});

    while(!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();

        for(int i = 0; i < 4; i++) {
            if((0 <= cur.first + rowMoveSet[i] && cur.first + rowMoveSet[i] < n) &&
            (0 <= cur.second + columnMoveSet[i] && cur.second + columnMoveSet[i] < m)) {
                if(!visited[cur.first + rowMoveSet[i]][cur.second + columnMoveSet[i]] &&
                !isWall[cur.first + rowMoveSet[i]][cur.second + columnMoveSet[i]]) {
                    count++;
                    visited[cur.first + rowMoveSet[i]][cur.second + columnMoveSet[i]] = 1;
                    q.push({cur.first + rowMoveSet[i], cur.second + columnMoveSet[i]});
                }
            }
        }
    }

    return count;
}

void solve() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(isWall[i][j]) {
                result[i][j] = countMovable(i, j) % 10;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << result[i][j];
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solve();
}