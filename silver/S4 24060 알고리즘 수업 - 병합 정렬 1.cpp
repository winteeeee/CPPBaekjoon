/*
#include <iostream>
#include <vector>
using namespace std;

int n, k, count;
vector<int> array;

void input() {
    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        array.push_back(temp);
    }
}

void check(int result) {
    if(count == k) {
        cout << result;
        exit(0);
    }
}

void merge(vector<int> &a, int p, int q, int r) {
    int i = p;
    int j = q + 1;
    int t = 1;

    static vector<int> temp(n + 1);
    while(i <= q && j <= r) {
        if(a[i] <= a[j]) {
            temp[t++] = a[i++];
            count++;
            check(temp[t - 1]);
        } else {
            temp[t++] = a[j++];
            count++;
            check(temp[t - 1]);
        }
    }

    while(i <= q) {
        temp[t++] = a[i++];
        count++;
        check(temp[t - 1]);
    }

    while(j <= r) {
        temp[t++] = a[j++];
        count++;
        check(temp[t - 1]);
    }

    i = p;
    t = 1;

    while(i <= r) {
        a[i++] = temp[t++];
    }
}

void merge_sort(vector<int> &a, int p, int r) {
    if(p < r) {
        int q = (p + r) / 2;
        merge_sort(a, p, q);
        merge_sort(a, q + 1, r);
        merge(a, p, q, r);
    }
}

void solve() {
    merge_sort(array, 0, n - 1);
    cout << -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solve();
}*/
