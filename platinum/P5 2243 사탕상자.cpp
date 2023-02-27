#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
class order {
public:
    int A;
    int B;
    int C;
};
const int ROOT = 1;
const int MAX = 1000000;
vector<order> orders;
vector<int> candyBox((MAX + 1) * 4);

void input() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        int A, B;

        cin >> A >> B;
        if (A == 2) {
            int C;
            cin >> C;
            orders.push_back({A, B, C});
        } else {
            orders.push_back({A, B});
        }
    }
}

int update(int start, int end, int index, int target, int count) {  //A가 2일 때
    if (target < start || target > end) {
        return candyBox[index];
    }

    if (start == end && start == target) {
        return candyBox[index] += count;
    }

    int mid = (start + end) / 2;
    int left = update(start, mid, index * 2, target, count);
    int right = update(mid + 1, end, index * 2 + 1, target, count);
    return candyBox[index] = left + right;
}

int findCandy(int index, int target) {   //A가 1일 때

}

void solve() {
    for (int i = 0; i < orders.size(); i++) {
        order cur = orders[i];

        if (cur.A == 1) {
            cout << findCandy(ROOT, cur.B) << '\n';
            update(ROOT, MAX, ROOT, cur.B, -1);
        } else {
            update(ROOT, MAX, ROOT, cur.B, cur.C);
        }
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