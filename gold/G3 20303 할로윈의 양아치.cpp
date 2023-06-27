/*
#include <iostream>
#include <vector>
using namespace std;

class child {
public:
    int id;
    int candy;
    int groupSize;
};

int n, m, k;
child children[30001];
int dp[30001][3001];
vector<int> group;

child find(int a) {
    if (children[a].id == a) {
        return children[a];
    }

    children[a].id = find(children[a].id).id;
    return children[children[a].id];
}

void merge(int a, int b) {
    child aParent = find(a);
    child bParent = find(b);

    if (aParent.id != bParent.id) {
        children[bParent.id].id = aParent.id;
        children[aParent.id].candy += bParent.candy;
        children[aParent.id].groupSize += bParent.groupSize;
    }
}

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        int candy;
        cin >> candy;
        children[i + 1] = {i + 1, candy, 1};
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        merge(a, b);
    }
}

void findCandy(int groupCount) {
    for (int i = 1; i < groupCount; i++) {
        int idx = group[i];
        for (int j = 0; j <= k; j++) {
            if (j > children[idx].groupSize) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - children[idx].groupSize] + children[idx].candy);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
}

void solve() {
    group.push_back(0); //더미 삽입
    for (int i = 1; i <= n; i++) {
        if (children[i].id == i) {
            group.push_back(i);
        }
    }

    int groupCount = group.size();
    findCandy(groupCount);
    cout << dp[groupCount - 1][k];
}

int main() {
    input();
    solve();

    return 0;
}
*/
