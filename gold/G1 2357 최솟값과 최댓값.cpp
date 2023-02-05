/*
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int N, M;
vector<int> arr;
vector<pair<int ,int>> orders;
vector<pair<int, int>> segmentTree(400001);

void input() {
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        orders.push_back({a, b});
    }
}

pair<int, int> makeTree(int start, int end, int index) {
    if (start == end) {
        return segmentTree[index] = {arr[start], arr[start]};
    }

    int mid = (start + end) / 2;
    pair<int, int> left = makeTree(start, mid, index * 2);
    pair<int, int> right = makeTree(mid + 1, end, index * 2 + 1);
    int minVal = min(left.first, right.first);
    int maxVal = max(left.second, right.second);

    return segmentTree[index] = {minVal, maxVal};
}

pair<int, int> findMinMax(int start, int end, int index, int left, int right) {
    if (right < start || end < left) {
        return {INT_MAX, INT_MIN};
    }

    if (left <= start && end <= right) {
        return {segmentTree[index].first, segmentTree[index].second};
    }

    int mid = (start + end) / 2;
    pair<int, int> leftPair = findMinMax(start, mid, index * 2, left, right);
    pair<int, int> rightPair = findMinMax(mid + 1, end, index * 2 + 1, left, right);
    int minVal = min(leftPair.first, rightPair.first);
    int maxVal = max(leftPair.second, rightPair.second);

    return {minVal, maxVal};
}

void solve() {
    makeTree(0, N - 1, 1);

    for(int i = 0; i < orders.size(); i++) {
        int left = orders[i].first - 1;
        int right = orders[i].second - 1;

        pair<int, int> minMax = findMinMax(0, N - 1, 1, left, right);
        cout << minMax.first << " " << minMax.second << '\n';
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
