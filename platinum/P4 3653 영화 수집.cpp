/*
#include <iostream>
#include <vector>
using namespace std;

int t, n, m;
vector<int> movie;
vector<int> idx;
vector<int> tree;

void input() {
    cin >> n >> m;
    movie = vector<int>(m);
    idx = vector<int>(n + 1);
    tree = vector<int>((n + m) * 4);

    for(int i = 0; i < m; i++) {
        cin >> movie[i];
    }

    for(int i = 0; i < n; i++) {
        idx[i + 1] = m + i;
    }
}

int makeTree(int start, int end, int index) {
    if (start == end) {
        if (start < m) {
            return tree[index] = 0;
        } else {
            return tree[index] = 1;
        }
    }

    int mid = (start + end) / 2;
    int left = makeTree(start, mid, index * 2);
    int right = makeTree(mid + 1, end, index * 2 + 1);

    return tree[index] = left + right;
}

int sum(int start, int end, int targetL, int targetR, int index) {
    if (targetR < start || targetL > end) {
        return 0;
    }

    if (targetL <= start && end <= targetR) {
        return tree[index];
    }

    int mid = (start + end) / 2;
    int left = sum(start, mid, targetL, targetR, index * 2);
    int right = sum(mid + 1, end, targetL, targetR, index * 2 + 1);

    return left + right;
}

int update(int start, int end, int targetRange, int val, int index) {
    if (targetRange < start || targetRange > end) {
        return tree[index];
    }

    if (start == end && start == targetRange) {
        return tree[index] = val;
    }

    int mid = (start + end) / 2;
    int left = update(start, mid, targetRange, val, index * 2);
    int right = update(mid + 1, end, targetRange, val, index * 2 + 1);

    return tree[index] = left + right;
}

void solve() {
    cin >> t;

    for (int i = 0; i < t; i++) {
        input();
        makeTree(1, n + m, 1);

        for (int j = 0; j < m; j++) {
            cout << sum(1, n + m, 1, idx[movie[j]] - 1, 1) << " ";
            update(1, n + m, idx[movie[j]], 0, 1);
            idx[movie[j]] = (m - 1) - j;
            update(1, n + m, idx[movie[j]], 1, 1);
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}
*/
