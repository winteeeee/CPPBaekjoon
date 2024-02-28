/*
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

class Edge {
public:
    int a;
    int b;
    double cost;
};

class comp {
public:
    bool operator()(const Edge &a, const Edge &b) {
        return a.cost > b.cost;
    }
};

double getDistance(pair<double, double> a, pair<double, double> b);
int find(int a);
void addMST(int a, int b);
bool isCycle(int a, int b);
int MST[101];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<pair<double, double>> star;
    for(int i = 0; i < n; i++) {
        double a, b;
        cin >> a >> b;
        star.push_back({a, b});
        MST[i] = i;
    }

    priority_queue<Edge, vector<Edge>, comp> h;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i != j) {
                h.push({i, j, getDistance(star[i], star[j])});
            }
        }
    }

    double result = 0;
    while(!h.empty()) {
        Edge cur = h.top(); h.pop();
        if(!isCycle(cur.a, cur.b)) {
            addMST(cur.a, cur.b);
            result += cur.cost;
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << result;
    return 0;
}

double getDistance(pair<double, double> a, pair<double, double> b) {
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

int find(int a) {
    if(a == MST[a])
        return a;

    MST[a] = find(MST[a]);
    return MST[a];
}

void addMST(int a, int b) {
    int aParent = find(a);
    int bParent = find(b);

    if(aParent < bParent)
        MST[bParent] = aParent;
    else if(aParent > bParent)
        MST[aParent] = bParent;
}

bool isCycle(int a, int b) {
    return find(a) == find(b);
}
*/
