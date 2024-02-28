/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long n, result;
vector<int> scoville(300001);
const int MOD = 1000000007;

long long findPow(int a, int b) {
    if (b == 1) {
        return a;
    } else if (b < 1) {
        return 1;
    }

    long long temp = findPow(a, b / 2) % MOD;
    if (b & 1) {
        return (temp % MOD * temp % MOD * a % MOD) % MOD;
    } else {
        return (temp % MOD * temp % MOD) % MOD;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> scoville[i];
    }

    sort(scoville.begin(), scoville.begin() + n);
    for (int i = 0; i < n; i++) {
        long long maxSum = findPow(2, i) % MOD;
        long long minSum = findPow(2, (n - 1 - i)) % MOD;
        result = (result % MOD + (scoville[i] * (maxSum + MOD - minSum)) % MOD) % MOD;
    }

    cout << result % MOD;
    return 0;
}*/
