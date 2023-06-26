/*
#include <iostream>
#include <vector>
using namespace std;

int n;
int root = 1;
int result;
vector<int> edges[1000001];
int edgeCount[1000001];
bool visited[1000001];
bool isEA[1000001];

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    edges[root].push_back(0);
    edges[0].push_back(root);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
}

bool hasEAChild(int s, int p) {
    for (int vertex : edges[s]) {
        if (vertex == 0 || vertex == p) {
            continue;
        }

        if (isEA[vertex]) {
            return true;
        }
    }

    return false;
}

bool isEAChildren(int s, int p) {
    for (int vertex : edges[s]) {
        if (vertex == 0 || vertex == p) {
            continue;
        }

        if (!isEA[vertex]) {
            return false;
        }
    }

    return true;
}

void findEarlyAdaptors(int s, int p) {
    if (visited[s]) {
        return;
    }

    //자식이 1명이면서 자식 중 하나라도 얼리 어댑터가 아니거나
    //자식이 2명 이상이면서 자식 모두 얼리어댑터가 아니라면
    //얼리어댑터로 취급함.
    //단 리프노드의 경우 바로 빠져나온다

    visited[s] = true;
    edgeCount[s] = edges[s].size();
    for (int vertex: edges[s]) {
        findEarlyAdaptors(vertex, s);
    }

    if ((edgeCount[s] > 2 && !isEAChildren(s, p)) || (edgeCount[s] > 1 && !hasEAChild(s, p))) {
        isEA[s] = true;
        result++;
    }
}

void solve() {
    findEarlyAdaptors(1, 0);
    cout << result;
}

int main() {
    input();
    solve();

    return 0;
}*/
