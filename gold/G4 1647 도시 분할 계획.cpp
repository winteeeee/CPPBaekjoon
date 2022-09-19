#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

const int SIZE = 1000001;
vector<pair<int, int>> road[SIZE];
bool visited[SIZE] = {false};
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> h;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        road[a].push_back({b, c});
        road[b].push_back({a, c});
    }
    h.push({0, 1});

    int max = INT_MIN;
    int sum = 0;
    for(int j = 0; j < n;) {
        pair<int, int> cur = h.top(); h.pop();
        int min = cur.first;
        int minIdx = cur.second;
        if(visited[minIdx])
            continue;

        j++;
        sum += min;
        visited[minIdx] = true;
        if(max < min)
            max = min;

        for(int i = 0; i < road[minIdx].size(); i++) {
            int nextIdx = road[minIdx][i].first;
            int nextWeight = road[minIdx][i].second;
            if(!visited[nextIdx]) {
                h.push({nextWeight, nextIdx});
            }
        }
    }

    cout << sum - max;
    return 0;
}