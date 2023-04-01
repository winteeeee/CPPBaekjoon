/*
#include <iostream>
#include <deque>
using namespace std;

int n;
deque<pair<int, int>> d;

void input() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int temp;
        cin >> temp;
        d.emplace_back(temp, i);
    }
}

void solve() {
    pair<int, int> cur = d.front(); d.pop_front();
    cout << cur.second;

    while (!d.empty()) {
        pair<int, int> temp;

        for (int i = 1; i <= abs(cur.first); i++) {
            if (cur.first > 0) {
                temp = d.front();
                d.pop_front();
                if (i != abs(cur.first)) {
                    d.push_back(temp);
                }
            } else {
                temp = d.back();
                d.pop_back();
                if (i != abs(cur.first)) {
                    d.push_front(temp);
                }
            }
        }

        if (!d.empty()) {
            cur = temp;
        }
        cout << " " << temp.second;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input();
    solve();

    return 0;
}*/
