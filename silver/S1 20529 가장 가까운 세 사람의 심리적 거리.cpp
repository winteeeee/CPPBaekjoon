/*
#include <iostream>
#include <climits>
using namespace std;

int t, n;
string MBTI[100001];

void input() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> MBTI[i];
    }
}

int find2Distance(string a, string b) {
    int result = 0;

    for (int i = 0; i < 4; i++) {
        if (a[i] != b[i]) {
            result++;
        }
    }

    return result;
}

int find3Distance(string a, string b, string c) {
    return find2Distance(a, b) + find2Distance(b, c) + find2Distance(a, c);
}

int distanceCalc() {
    int distance = INT_MAX;

    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                distance = min(distance, find3Distance(MBTI[i], MBTI[j], MBTI[k]));
            }
        }
    }

    return distance;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    for (int i = 0; i < t; i++) {
        input();
        if (n > 48) {
            cout << "0\n";
        } else {
            cout << distanceCalc() << '\n';
        }
    }
}

int main() {
    solve();

    return 0;
}*/
