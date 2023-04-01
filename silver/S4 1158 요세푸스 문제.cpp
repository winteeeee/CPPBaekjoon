/*
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, k;
queue<int> q;

void input() {
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        q.push(i);
    }
}

void solve() {
    vector<int> result;

    while (!q.empty()) {
        for (int i = 1; i <= k; i++) {
            int cur = q.front(); q.pop();
            if (i != k) {
                q.push(cur);
            } else {
                result.push_back(cur);
            }
        }
    }

    cout << "<";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << ", ";
        }
    }
    cout << ">";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input();
    solve();

    return 0;
}*/
