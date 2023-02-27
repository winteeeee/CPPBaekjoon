/*
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
const int MAX = 1000001;
vector<order> orders;
vector<int> candyBox(MAX * 4);

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

    if (start == end) {
        if (start == target) {
            return candyBox[index] += count;
        } else {
            return candyBox[index];
        }
    }

    int mid = (start + end) / 2;
    int left = update(start, mid, index * 2, target, count);
    int right = update(mid + 1, end, index * 2 + 1, target, count);
    return candyBox[index] = left + right;
}

int findCandy(int start, int end, int index, int target) {   //A가 1일 때
    if (start == end) {
        return start;
    }

    int left = candyBox[index * 2];
    int mid = (start + end) / 2;

    if (left < target) {    //오른쪽 서브트리를 선택한다면 오른쪽 서브트리 내의 target은 left만큼 빠진다.
        return findCandy(mid + 1, end, index * 2 + 1, target - left);
    } else {
        return findCandy(start, mid, index * 2, target);
    }
}

void solve() {
    for (int i = 0; i < orders.size(); i++) {
        order cur = orders[i];

        if (cur.A == 1) {
            int findedCandy = findCandy(ROOT, MAX, ROOT, cur.B);
            cout << findedCandy << '\n';
            update(ROOT, MAX, ROOT, findedCandy, -1);
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
}*/
