/*
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<int> edges[100001];
int result[100001];
bool visited[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int p1, p2;
        cin >> p1 >> p2;
        edges[p1].push_back(p2);
        edges[p2].push_back(p1);
    }

    queue<int> q;
    q.push(1);
    visited[1] = true;

    while(!q.empty()) {
        int root = q.front(); q.pop();
        for (int i = 0; i < edges[root].size(); i++) {
            if (!visited[edges[root][i]]) {
                visited[edges[root][i]] = true;
                q.push(edges[root][i]);
                result[edges[root][i]] = root;
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        cout << result[i] << '\n';
    }

    return 0;
}
*/
