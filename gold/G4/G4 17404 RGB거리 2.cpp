/*
#include <iostream>
#include <vector>
using namespace std;

const int R = 0;
const int G = 1;
const int B = 2;
int n;
vector<int> price[1001];
int dp[1001][3][3];    //n번째 / 현재 택할 색 / 1번째 택한 색

void input() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        int r, g, b;
        cin >> r >> g >> b;
        price[i].push_back(r);
        price[i].push_back(g);
        price[i].push_back(b);
    }
}

void solve() {
    for(int i = 0; i < n; i++) {
        if(i != 0 && i != n - 1) {
            dp[i][R][R] = min(dp[i - 1][G][R], dp[i - 1][B][R]) + price[i][R];
            dp[i][R][G] = min(dp[i - 1][G][G], dp[i - 1][B][G]) + price[i][R];
            dp[i][R][B] = min(dp[i - 1][G][B], dp[i - 1][B][B]) + price[i][R];

            dp[i][G][R] = min(dp[i - 1][R][R], dp[i - 1][B][R]) + price[i][G];
            dp[i][G][G] = min(dp[i - 1][R][G], dp[i - 1][B][G]) + price[i][G];
            dp[i][G][B] = min(dp[i - 1][R][B], dp[i - 1][B][B]) + price[i][G];

            dp[i][B][R] = min(dp[i - 1][R][R], dp[i - 1][G][R]) + price[i][B];
            dp[i][B][G] = min(dp[i - 1][R][G], dp[i - 1][G][G]) + price[i][B];
            dp[i][B][B] = min(dp[i - 1][R][B], dp[i - 1][G][B]) + price[i][B];
        } else if(i == 0) {
            dp[i][R][R] = price[i][R];
            dp[i][R][G] = 10000000;
            dp[i][R][B] = 10000000;

            dp[i][G][R] = 10000000;
            dp[i][G][G] = price[i][G];
            dp[i][G][B] = 10000000;

            dp[i][B][R] = 10000000;
            dp[i][B][G] = 10000000;
            dp[i][B][B] = price[i][B];
        } else {
            dp[i][R][G] = min(dp[i - 1][G][G], dp[i - 1][B][G]) + price[i][R];
            dp[i][R][B] = min(dp[i - 1][G][B], dp[i - 1][B][B]) + price[i][R];

            dp[i][G][R] = min(dp[i - 1][R][R], dp[i - 1][B][R]) + price[i][G];
            dp[i][G][B] = min(dp[i - 1][R][B], dp[i - 1][B][B]) + price[i][G];

            dp[i][B][R] = min(dp[i - 1][R][R], dp[i - 1][G][R]) + price[i][B];
            dp[i][B][G] = min(dp[i - 1][R][G], dp[i - 1][G][G]) + price[i][B];
        }
    }

    int minR = min(dp[n - 1][R][G], dp[n - 1][R][B]);
    int minG = min(dp[n - 1][G][R], dp[n - 1][G][B]);
    int minB = min(dp[n - 1][B][R], dp[n - 1][B][G]);

    cout << min(min(minR, minG), minB);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solve();
}*/
