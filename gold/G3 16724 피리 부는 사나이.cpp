/*
#include <iostream>
using namespace std;

int n, m;
char map[1001][1001];
bool visited[1001][1001];
pair<int, int> disjointSet[1001][1001];

void input() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        string temp;
        cin >> temp;

        for(int j = 0; j < m; j++) {
            map[i][j] = temp[j];
        }
    }
}

void makeSet() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            disjointSet[i][j] = {i, j};
        }
    }
}

pair<int, int> find(pair<int, int> me) {
    if(disjointSet[me.first][me.second].first == me.first && disjointSet[me.first][me.second].second == me.second) {
        return me;
    }

    disjointSet[me.first][me.second] = find(disjointSet[me.first][me.second]);
    return disjointSet[me.first][me.second];
}

void dfs(pair<int, int> pos) {
    visited[pos.first][pos.second] = 1;

    if(map[pos.first][pos.second] == 'U') {
        disjointSet[pos.first][pos.second] = find({pos.first - 1, pos.second});
        if(!visited[pos.first - 1][pos.second]) {
            dfs({pos.first - 1, pos.second});
        }
    } else if(map[pos.first][pos.second] == 'D') {
        disjointSet[pos.first][pos.second] = find({pos.first + 1, pos.second});
        if(!visited[pos.first + 1][pos.second]) {
            dfs({pos.first + 1, pos.second});
        }
    } else if(map[pos.first][pos.second] == 'L') {
        disjointSet[pos.first][pos.second] = find({pos.first, pos.second - 1});
        if(!visited[pos.first][pos.second - 1]) {
            dfs({pos.first, pos.second - 1});
        }
    } else {
        disjointSet[pos.first][pos.second] = find({pos.first, pos.second + 1});
        if(!visited[pos.first][pos.second + 1]) {
            dfs({pos.first, pos.second + 1});
        }
    }
}

int countingSet() {
    int result = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(disjointSet[i][j].first == i && disjointSet[i][j].second == j) {
                result++;
            }
        }
    }

    return result;
}

void solve() {
    makeSet();

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!visited[i][j]) {
                dfs({i, j});
            }
        }
    }

    cout << countingSet();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solve();
}*/
