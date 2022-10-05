/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

vector<pair<int, int>> wire;
bool comp(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        wire.push_back({a, b});
    }

    sort(wire.begin(), wire.end());
    vector<pair<int, int>> result;
    vector<int> idx;
    result.push_back(wire[0]);
    idx.push_back(0);

    for(int i = 1; i < n; i++) {
        pair<int, int> cur = wire[i];
        int lowerIdx = lower_bound(result.begin(), result.end(), cur, comp) - result.begin();

        if(lowerIdx >= result.size()) {
            result.push_back(cur);
            idx.push_back(lowerIdx);
        }

        else {
            if (result[lowerIdx].second > cur.second) {
                result[lowerIdx] = cur;
                idx.push_back(lowerIdx);
            }
        }
    }

    stack<int> s;
    int size = result.size() - 1;
    for(int i = idx.size() - 1; i >= 0; i--) {
        if(idx[i] == size) {
            s.push(wire[i].first);
            size--;
        }
    }

    cout << n - s.size() << "\n";
    int i = 0;
    for(; !s.empty(); i++) {
        if(wire[i].first == s.top())
            s.pop();
        else
            cout << wire[i].first << "\n";
    }

    for(; i < wire.size(); i++)
        cout << wire[i].first << "\n";

    return 0;
}*/
