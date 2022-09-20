#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n, m;
int inEdge[32001];
vector<int> edges[32001];
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

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        inEdge[b]++;
    }
}

void solve() {
    cout.tie(NULL);

    stack<int> s;
    for(int i = 1; i <= n; i++) {
        if(inEdge[i] == 0) {
            s.push(i);
        }
    }

    while(!s.empty()) {
        int cur = s.top(); s.pop();
        cout << cur << " ";
        for(int i = 0; i < edges[cur].size(); i++) {
            inEdge[edges[cur][i]]--;

            if(inEdge[edges[cur][i]] == 0)
                s.push(edges[cur][i]);
        }
    }
}