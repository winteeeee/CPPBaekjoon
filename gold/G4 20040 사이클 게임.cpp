/*
#include <iostream>
#include <vector>
using namespace std;

int n, m, result;
vector<pair<int, int>> numbers;
int disjointSet[500001];

void input() {
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        numbers.push_back({a, b});
    }
}

void makeSet() {
    for(int i = 0; i < n; i++) {
        disjointSet[i] = i;
    }
}

int find(int i) {
    if(disjointSet[i] == i) {
        return i;
    }

    disjointSet[i] = find(disjointSet[i]);
    return disjointSet[i];
}

void unionSet(pair<int, int> a, int i) {
    int parentF = find(a.first);
    int parentS = find(a.second);

    if(parentF != parentS) {
        disjointSet[parentS] = parentF;
    } else {
        if(!result) {
            result = i;
        }
    }
}

void solve() {
    makeSet();

    for(int i = 0; i < m; i++) {
        unionSet(numbers[i], i + 1);
    }

    cout << result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solve();
}*/
