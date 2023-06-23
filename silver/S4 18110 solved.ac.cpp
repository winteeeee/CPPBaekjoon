#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n;
vector<int> rating;

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        rating.push_back(temp);
    }
}

void solve() {
    int exceptionCount = floor(rating.size() * 0.15 + 0.5);
    int sum = 0;
    int length = rating.size() - 2 * exceptionCount;

    for (int i = 0; i < length; i++) {
        sum += rating[i + exceptionCount];
    }

    cout << floor((double)sum / length + 0.5);
    //n이 0일 때 예외처리
}

int main() {
    input();
    solve();

    return 0;
}