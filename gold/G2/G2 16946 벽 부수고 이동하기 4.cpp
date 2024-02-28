/*
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
int isWall[1000][1000];
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

void dfs(int r, int c, vector<pair<int, int>> &wallPath, int &wallPathIndex, vector<vector<bool>> &wallVisited, vector<vector<bool>> &visited, int &count) {
    visited[r][c] = 1;

    for(int i = 0; i < 4; i++) {
        if((0 <= r + rowMoveSet[i] && r + rowMoveSet[i] < n) &&
           (0 <= c + columnMoveSet[i] && c + columnMoveSet[i] < m)) {
            if(!visited[r + rowMoveSet[i]][c + columnMoveSet[i]]) {
                if (!isWall[r + rowMoveSet[i]][c + columnMoveSet[i]]) {
                    count++;
                    dfs(r + rowMoveSet[i], c + columnMoveSet[i], wallPath, wallPathIndex, wallVisited, visited, count);
                } else {
                    if(!wallVisited[r + rowMoveSet[i]][c + columnMoveSet[i]]) {
                        wallPath[wallPathIndex++] = {r + rowMoveSet[i], c + columnMoveSet[i]};
                        wallVisited[r + rowMoveSet[i]][c + columnMoveSet[i]] = 1;
                    }
                }
            }
        }
    }
}

void makeResult() {
    vector<vector<bool>> visited(1000, vector<bool>(1000));
    vector<pair<int, int>> wallPath(1000000);
    vector<vector<bool>> wallVisited(1000, vector<bool>(1000));
    int wallPathIndex = 0;
    int count = 1;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!isWall[i][j] && !visited[i][j]) {
                dfs(i, j, wallPath, wallPathIndex, wallVisited, visited, count);

                for(int k = 0; k < wallPathIndex; k++) {
                    isWall[wallPath[k].first][wallPath[k].second] += count;
                    wallVisited[wallPath[k].first][wallPath[k].second] = 0;
                }

                count = 1;
                wallPathIndex = 0;
            }
        }
    }
}

void solve() {
    makeResult();

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
}*/
