/*
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

class order {
public:
    ll a;
    ll b;
    ll c;
};

int N, M, K;
const int MOD = 1e9 + 7;
vector<ll> arr;
vector<order> orders;
vector<ll> segmentTree(1000000 * 4 + 1);

void input() {
    cin >> N >> M >> K;

    for(int i = 0; i < N; i++) {
        ll temp;
        cin >> temp;
        arr.push_back(temp);
    }

    for(int i = 0; i < M + K; i++) {
        ll a, b, c;
        cin >> a >> b >> c;

        if (a == 1) {
            orders.push_back({a, b - 1, c,});
        } else {
            orders.push_back({a, b - 1, c - 1});
        }
    }
}

ll makeTree(int start, int end, int index) {
    if (start == end) {
        return segmentTree[index] = arr[start];
    }

    int mid = (start + end) / 2;
    return segmentTree[index] = (makeTree(start, mid, index * 2) % MOD * makeTree(mid + 1, end, index * 2 + 1) % MOD) % MOD;
}

ll update(int start, int end, int index, int targetIndex, ll newVal) {
    if (targetIndex < start || end < targetIndex) {
        return segmentTree[index];
    }

    if (start == end) {
        return segmentTree[index] = newVal;
    }

    int mid = (start + end) / 2;
    return segmentTree[index] = (update(start, mid, index * 2, targetIndex, newVal) % MOD * update(mid + 1, end, index * 2 + 1, targetIndex, newVal) % MOD) % MOD;
}

ll mul(int start, int end, int index, int left, int right) {
    if (right < start || end < left) {
        return 1;
    }

    if (left <= start && end <= right) {
        return segmentTree[index];
    }

    int mid = (start + end) / 2;
    return (mul(start, mid , index * 2, left, right) % MOD * mul(mid + 1, end, index * 2 + 1, left, right) % MOD) % MOD;
}

void solve() {
    makeTree(0, N - 1, 1);

    for(int i = 0; i < orders.size(); i++) {
        order cur = orders[i];

        if (cur.a == 1) {
            update(0, N - 1, 1, cur.b,  cur.c);
            arr[cur.b] = cur.c;
        } else {
            cout << mul(0, N - 1, 1, cur.b, cur.c) % MOD << '\n';
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
