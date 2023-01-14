#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
int isWall[1000][1000];
int zeroCount[1000][1000];
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

void dfs(int r, int c, vector<pair<int, int>> &path, int &pathIndex, bool visited[][1000], int &count) {
    visited[r][c] = 1;

    for(int i = 0; i < 4; i++) {
        if((0 <= r + rowMoveSet[i] && r + rowMoveSet[i] < n) &&
           (0 <= c + columnMoveSet[i] && c + columnMoveSet[i] < m)) {
            if(!visited[r + rowMoveSet[i]][c + columnMoveSet[i]] &&
            !isWall[r + rowMoveSet[i]][c + columnMoveSet[i]]) {
                path[pathIndex++] = {r + rowMoveSet[i], c + columnMoveSet[i]};
                count++;
                dfs(r + rowMoveSet[i], c + columnMoveSet[i], path, pathIndex, visited, count);
            }
        }
    }
}

void countMovable(int r, int c) {
    bool isPlus[1000][1000] = {0};
    bool visited[1000][1000] = {0};
    queue<pair<int, int>> q;
    q.push({r, c});
    visited[r][c] = 1;

    while(!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();

        for(int i = 0; i < 4; i++) {
            if((0 <= cur.first + rowMoveSet[i] && cur.first + rowMoveSet[i] < n) &&
               (0 <= cur.second + columnMoveSet[i] && cur.second + columnMoveSet[i] < m)) {
                if(isWall[cur.first + rowMoveSet[i]][cur.second + columnMoveSet[i]]) {
                    if(!isPlus[cur.first + rowMoveSet[i]][cur.second + columnMoveSet[i]]) {
                        isPlus[cur.first + rowMoveSet[i]][cur.second + columnMoveSet[i]] = 1;
                        isWall[cur.first + rowMoveSet[i]][cur.second + columnMoveSet[i]] += zeroCount[r][c];
                    }
                } else {
                    if(!visited[cur.first + rowMoveSet[i]][cur.second + columnMoveSet[i]]) {
                        visited[cur.first + rowMoveSet[i]][cur.second + columnMoveSet[i]] = 1;
                        q.push({cur.first + rowMoveSet[i], cur.second + columnMoveSet[i]});
                    }
                }
            }
        }
    }
}

void countZero() {
    bool visited[1000][1000] = {0};
    vector<pair<int, int>> path(1000000);
    int pathIndex = 0;
    int count = 1;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!isWall[i][j] && !visited[i][j]) {
                path[pathIndex++] = {i, j};
                dfs(i, j, path, pathIndex, visited, count);

                for(int k = 0; k < pathIndex; k++) {
                    zeroCount[path[k].first][path[k].second] = count;
                }

                count = 1;
                pathIndex = 0;
                countMovable(i, j);
            }
        }
    }
}

void solve() {
    countZero();

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << isWall[i][j] % 10;
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