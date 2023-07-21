/*
#include <iostream>
#include <queue>
using namespace std;

int n, m, k;
int map[1001][1001];
int patternR[4] = {1, -1, 0, 0};
int patternC[4] = {0, 0, 1, -1};

void printMap() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << map[i][j] << " ";
        }
        cout << '\n';
    }
}

void emplaceNumber(int r, int c) {
    bool check[5];
    for (bool& e : check) {
        e = true;
    }

    for (int i = r - 1; i <= r + 1; i++) {
        for (int j = c - 1; j <= c + 1; j++) {
            if ((0 <= i && i < n) && (0 <= j && j < m)) {
                check[map[i][j]] = false;
            }
        }
    }

    for (int i = 1; i < 5; i++) {
        if (check[i]) {
            map[r][c] = i;
            k = max(k, i);
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    queue<pair<int, int>> q;
    emplaceNumber(0, 0);
    q.emplace(0, 0);

    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        int r = cur.first;
        int c = cur.second;

        for (int i = 0; i < 4; i++) {
            if (!map[r + patternR[i]][c + patternC[i]] &&
                (0 <= r + patternR[i] && r + patternR[i] < n) &&
                (0 <= c + patternC[i] && c + patternC[i] < m)) {
                emplaceNumber(r + patternR[i], c + patternC[i]);
                q.emplace(r + patternR[i], c + patternC[i]);
            }
        }
    }

    cout << k << '\n';
    printMap();
    return 0;
}
*/
