#include <iostream>
using namespace std;

int n, m;
int sumOfCost = 0;
int memory[101];
int cost[101];
int DP[101][10001];

void input();
void solve();
int main() {
    ios_base::sync_with_stdio(false);
    input();
    solve();

    return 0;
}

void input() {
    cin.tie(NULL);
    cin >> n >> m;

    for(int i = 1; i <= n; i++)
        cin >> memory[i];
    for(int i = 1; i <= n; i++) {
        cin >> cost[i];
        sumOfCost += cost[i];
    }
}

void solve() {
    cout.tie(NULL);
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= sumOfCost; j++) {
            if(j - cost[i] >= 0)
                DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - cost[i]] + memory[i]);
            else
                DP[i][j] = DP[i - 1][j];
        }
    }

    for(int i = 1; i <= sumOfCost; i++) {
        if(DP[n][i] >= m) {
            cout << i;
            break;
        }
    }
}