//#include <iostream>
//#include <vector>
//typedef long long ll;
//using namespace std;
//
//class order {
//public:
//    ll a;
//    ll b;
//    ll c;
//};
//
//ll N, M, K;
//vector<ll> arr;
//vector<order> orders;
//vector<ll> segmentTree(4000001);
//
//void input() {
//    cin >> N >> M >> K;
//
//    for(ll i = 0; i < N; i++) {
//        ll temp;
//        cin >> temp;
//        arr.push_back(temp);
//    }
//
//    for(ll i = 0; i < M + K; i++) {
//        ll a, b, c;
//        cin >> a >> b >> c;
//
//        if (a == 1) {
//            orders.push_back({a, b - 1, c});
//        } else {
//            orders.push_back({a, b - 1, c - 1});
//        }
//    }
//}
//
//ll makeTree(int start, int end, int index) {
//    if (start == end) {
//        return segmentTree[index] = arr[start];
//    }
//
//    int mid = (start + end) / 2;
//    return segmentTree[index] = makeTree(start, mid, index * 2) + makeTree(mid + 1, end, index * 2 + 1);
//}
//
//void update(int start, int end, int index, int targetIndex, ll targetVal) {
//    if (targetIndex < start || end < targetIndex) {
//        return;
//    }
//
//    segmentTree[index] += targetVal;
//    if (start == end) {
//        return;
//    }
//    int mid = (start + end) / 2;
//    update(start, mid, index * 2, targetIndex, targetVal);
//    update(mid + 1, end, index * 2 + 1, targetIndex, targetVal);
//}
//
//ll sum(int start, int end, int index, int left, int right) {
//    if (right < start || end < left) {
//        return 0;
//    }
//
//    if (left <= start && end <= right) {
//        return segmentTree[index];
//    }
//    int mid = (start + end) / 2;
//    return sum(start, mid, index * 2, left, right) + sum(mid + 1, end, index * 2 + 1, left, right);
//}
//
//void solve() {
//    makeTree(0, N - 1, 1);
//
//    for(int i = 0; i < orders.size(); i++) {
//        if (orders[i].a == 1) {
//            update(0, N - 1, 1, orders[i].b, orders[i].c - arr[orders[i].b]);
//            arr[orders[i].b] = orders[i].c;
//        } else {
//            cout << sum(0, N - 1, 1, orders[i].b, orders[i].c) << '\n';
//        }
//    }
//}
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//    input();
//    solve();
//    return 0;
//}