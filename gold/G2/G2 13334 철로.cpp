/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class People {
public:
    int a;
    int b;
};

int n, d, result;
vector<People> segment;

bool comp(const People& a, const People& b) {
    return a.b < b.b;
}

struct comp2 {
    bool operator()(const People& a, const People& b) {
        return a.a > b.a;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a < b) {
            segment.push_back({a, b});
        } else {
            segment.push_back({b, a});
        }
    }
    cin >> d;

    sort(segment.begin(), segment.end(), comp);
    priority_queue<People, vector<People>, comp2> q;
    for (int i = 0; i < segment.size(); i++) {
        if (segment[i].a >= segment[i].b - d) {
            q.push(segment[i]);
        }

        while (!q.empty() && q.top().a < segment[i].b - d) {
            q.pop();
        }

        result = max(result, (int)q.size());
    }

    cout << result;
}*/
