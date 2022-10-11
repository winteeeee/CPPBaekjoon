/*
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

class Edge {
public:
    int a;
    int b;
    int cost;
};

class comp {
public:
    bool operator()(const Edge &a, const Edge &b) {
        return a.cost > b.cost;
    }
};

int set[100001];
int find(int a, int b);
void addSet(int a, int b);
bool isCycle(int a, int b);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, int>> x;
    vector<pair<int, int>> y;
    vector<pair<int, int>> z;
    for(int i = 0; i < n; i++) {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        x.push_back({t1, i});
        y.push_back({t2, i});
        z.push_back({t3, i});
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    sort(z.begin(), z.end());

    priority_queue<Edge, vector<Edge>, comp> h;
    for(int i = 0; i < n - 1; i++) {
        h.push({x[i].second, x[i + 1].second, abs(x[i].first - x[i + 1].first)});
        h.push({y[i].second, y[i + 1].second, abs(y[i].first - y[i + 1].first)});
        h.push({z[i].second, z[i + 1].second, abs(z[i].first - z[i + 1].first)});
    }

    for(int i = 0; i < n; i++)
        set[i] = i;

    int result = 0;
    while(!h.empty()) {
        Edge cur = h.top(); h.pop();
        if(!isCycle(cur.a, cur.b)) {
            result += cur.cost;
            addSet(cur.a, cur.b);
        }
    }

    cout << result;
    return 0;
}

int find(int a) {
    if(set[a] == a)
        return a;

    set[a] = find(set[a]);
    return set[a];
}

void addSet(int a, int b) {
    int aParent = find(a);
    int bParent = find(b);

    if(aParent < bParent)
        set[bParent] = aParent;
    else if(aParent > bParent)
        set[aParent] = bParent;
}

bool isCycle(int a, int b) {
    return find(a) == find(b);
}
*/
