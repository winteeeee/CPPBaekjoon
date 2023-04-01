/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class lineSegment {
public:
    int start;
    int end;
};

int n, m;
vector<int> point;
vector<lineSegment> lineSegments;

void input() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        point.push_back(temp);
    }

    for (int i = 0; i < m; i++) {
        int start, end;
        cin >> start >> end;
        lineSegments.push_back({start, end});
    }
}

void solve() {
    sort(point.begin(), point.end());

    for (int i = 0; i < lineSegments.size(); i++) {
        int startIndex = lower_bound(point.begin(), point.end(), lineSegments[i].start) - point.begin();
        int endIndex = upper_bound(point.begin(), point.end(), lineSegments[i].end) - point.begin();

        if (point[startIndex] == point[endIndex]) {
            cout << 0;
        } else {
            cout << (endIndex - 1) - startIndex + 1;
        }

        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solve();

    return 0;
}
*/
