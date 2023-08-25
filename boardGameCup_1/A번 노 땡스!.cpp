/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> v;

void input() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        v.push_back(temp);
    }
}

void solve() {
    sort(v.begin(), v.end());

    int sum = 0;
    int last = 0;
    for(int i = 0; i < n; i++) {
        if(i == 0) {
            sum += v[0];
            last = v[0];
        } else {
            if(v[i] - 1 == last) {
                last = v[i];
            } else {
                sum += v[i];
                last = v[i];
            }
        }
    }

    cout << sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solve();
}*/
