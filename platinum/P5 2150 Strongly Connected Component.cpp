#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int v, e, numberOfSCC;
vector<vector<int>> graph(10001);
vector<vector<int>> inverseGraph(10001);
vector<int> inDegree(10001);
vector<int> topologicalSequence;

void input() {
    cin >> v >> e;

    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        inDegree[a]++;
    }
}

void topologicalSort() {
    stack<int> s;

    for (int i = 1; i <= v; i++) {   //진입 차수가 0인 정점 탐색
        if (!inDegree[i]) {
            s.push(i);
            topologicalSequence.push_back(i);
        }
    }

    while (!s.empty()) {
        int cur = s.top(); s.pop();

        for (int i = 0; i < graph[cur].size(); i++) {
            inDegree[graph[cur][i]]--;

            if (!inDegree[graph[cur][i]]) {
                s.push(graph[cur][i]);
                topologicalSequence.push_back(graph[cur][i]);
            }
        }
    }
}

void makeInverseGraph() {

}

void extractSCC() {

}

void solve() {
    topologicalSort();
    makeInverseGraph();
    extractSCC();

    cout << numberOfSCC;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solve();
    return 0;
}