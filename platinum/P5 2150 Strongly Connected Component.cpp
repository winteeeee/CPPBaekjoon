/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int v, e, numberOfSCC;
vector<vector<int>> graph(10001);
vector<vector<int>> reverseGraph(10001);
vector<int> inDegree(10001);
vector<int> topologicalSequence;
vector<bool> topologicalVisited(10001);
vector<bool> visited(10001);
vector<vector<int>> result(10001);

void input() {
    cin >> v >> e;

    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        reverseGraph[b].push_back(a);
        inDegree[a]++;
    }
}

void topologicalDFS(int start) {
    topologicalVisited[start] = true;

    for (int i = 0; i < graph[start].size(); i++) {
        if (!topologicalVisited[graph[start][i]]) {
            topologicalDFS(graph[start][i]);
        }
    }

    topologicalSequence.push_back(start);
}

void topologicalSort() {
    for (int i = 1; i <= v; i++) {
        if (!topologicalVisited[i]) {
            topologicalDFS(i);
        }
    }
}

void DFS(int start) {
    visited[start] = true;

    for (int i = 0; i < reverseGraph[start].size(); i++) {
        if (!visited[reverseGraph[start][i]]) {
            result[numberOfSCC].push_back(reverseGraph[start][i]);
            DFS(reverseGraph[start][i]);
        }
    }
}

void extractSCC() {
    for (int i = topologicalSequence.size() - 1; i >= 0; i--) {
        if (!visited[topologicalSequence[i]]) {
            result[numberOfSCC].push_back(topologicalSequence[i]);
            DFS(topologicalSequence[i]);
            numberOfSCC++;
        }
    }
}

void solve() {
    topologicalSort();
    extractSCC();

    cout << numberOfSCC << '\n';
    for (int i = 0; i < numberOfSCC; i++) {
        sort(result[i].begin(), result[i].end());
    }

    sort(result.begin(), result.begin() + numberOfSCC);

    for (int i = 0; i < numberOfSCC; i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << "-1\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solve();
    return 0;
}*/
