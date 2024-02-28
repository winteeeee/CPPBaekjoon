/*
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class query {
public:
    int a;
    int b;
    int c;
};

class node {
public:
    int index;
    int val;
};

int N, M;
vector<int> sequence;
vector<query> queries;
vector<node> segmentTree(400000);

void input() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        sequence.push_back(temp);
    }

    cin >> M;
    for(int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        queries.push_back({a, b, c});
    }
}

node makeTree(int start, int end, int index) {
    if (start == end) {
        return segmentTree[index] = {start, sequence[start]};
    }

    int mid = (start + end) / 2;
    node left = makeTree(start, mid, index * 2);
    node right = makeTree(mid + 1, end, index * 2 + 1);


    if (left.val > right.val) {
        return segmentTree[index] = {right.index, right.val};
    } else if (left.val < right.val) {
        return segmentTree[index] = {left.index, left.val};
    } else {
        if (left.index > right.index) {
            return segmentTree[index] = {right.index, right.val};
        } else {
            return segmentTree[index] = {left.index, left.val};
        }
    }
}

node update(int start, int end, int index, int targetIndex, int targetVal) {
    if (targetIndex < start || end < targetIndex) {
        return segmentTree[index];
    }

    if (start != end) {
        int mid = (start + end) / 2;
        node left = update(start, mid, index * 2, targetIndex, targetVal);
        node right = update(mid + 1, end, index * 2 + 1, targetIndex, targetVal);

        if (left.val > right.val) {
            return segmentTree[index] = {right.index, right.val};
        } else if (left.val < right.val) {
            return segmentTree[index] = {left.index, left.val};
        } else {
            if (left.index > right.index) {
                return segmentTree[index] = {right.index, right.val};
            } else {
                return segmentTree[index] = {left.index, left.val};
            }
        }
    } else {
        return segmentTree[index] = {targetIndex, targetVal};
    }
}

node findMinNode(int start, int end, int index, int left, int right) {
    if (right < start || end < left) {
        return {INT_MAX, INT_MAX};
    }

    if (left <= start && end <= right) {
        return segmentTree[index];
    }

    int mid = (start + end) / 2;
    node leftNode = findMinNode(start, mid, index * 2, left, right);
    node rightNode = findMinNode(mid + 1, end, index * 2 + 1, left, right);

    if (leftNode.val > rightNode.val) {
        return rightNode;
    } else if (leftNode.val < rightNode.val) {
        return leftNode;
    } else {
        if (leftNode.index > rightNode.index) {
            return rightNode;
        } else {
            return leftNode;
        }
    }
}

void solve() {
    makeTree(0, N - 1, 1);

    for(int i = 0; i < queries.size(); i++) {
        query cur = queries[i];

        if (cur.a == 1) {
            update(0, N - 1, 1, cur.b - 1, cur.c);
        } else {
            cout << findMinNode(0, N - 1, 1, cur.b - 1, cur.c - 1).index + 1 << '\n';
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
