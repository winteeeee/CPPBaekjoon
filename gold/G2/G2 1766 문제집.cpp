/*
#include <iostream>
#include <queue>
using namespace std;

vector<int> info[100001];
int inEdge[32001] = {};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        info[a].push_back(b);
        inEdge[b]++;
    }

    priority_queue<int, vector<int>, greater<int>> h;
    for(int i = 1; i <= n; i++) {
        if(inEdge[i] == 0)
            h.push(i);
    }

    while(!h.empty()) {
        int cur = h.top(); h.pop();

        for(int i = 0; i < info[cur].size(); i++) {
            inEdge[info[cur][i]]--;

            if(inEdge[info[cur][i]] == 0)
                h.push(info[cur][i]);
        }
        cout << cur << " ";
    }

    return 0;
}*/
