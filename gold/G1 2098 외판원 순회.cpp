#include <iostream>
#include <climits>
using namespace std;

int n;
int weight[16][16];
int DP[16][1 << 16];
int DFS(int curCity, int curBit);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> weight[i][j];
        }

        for(int j = 0; j < (1 << 16); j++)
            DP[i][j] = INT_MAX;
    }

    cout << DFS(0, 1);
    return 0;
}

int DFS(int curCity, int curBit) {
    if(curBit == (1 << n) - 1) {
        if(!weight[curCity][0])
            return INT_MAX;

        else
            return weight[curCity][0];
    }

    if(DP[curCity][curBit] != INT_MAX)
        return DP[curCity][curBit];

    for(int i = 0; i < n; i++) {
        if(curBit & (1 << i))
            continue;

        if(weight[curCity][i]) {
            DP[curCity][curBit] = min(DP[curCity][curBit], weight[curCity][i] + DFS(i, curBit | (1 << i)));
        }
    }

    return DP[curCity][curBit];
}