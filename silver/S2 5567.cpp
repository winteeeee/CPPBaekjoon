/*
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, result;
vector<int> adList[10001];
bool visited[501];

class Foo {
public:
    int p;
    int count;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adList[a].push_back(b);
        adList[b].push_back(a);
    }

    queue<Foo> q;
    visited[1] = true;
    q.push({1, 0});
    while(!q.empty()) {
        Foo cur = q.front(); q.pop();
        if (cur.count <= 2) {
            result++;
        }

        for (int i = 0; i < adList[cur.p].size(); i++) {
            if (!visited[adList[cur.p][i]] && cur.count < 2) {
                visited[adList[cur.p][i]] = true;
                q.push({adList[cur.p][i], cur.count + 1});
            }
        }
    }

    cout << result - 1;
    return 0;
}
*/
