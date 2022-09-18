#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> road[m + 1];
    for(int i = 0; i < m; i++) {
        int a, b, c;
        road[a].push_back({b, c});
        road[b].push_back({a, c});
    }

    return 0;
}