#include <iostream>
using namespace std;

int n, k;
int energy[500001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> energy[i];
    }

    int result1 = energy[1] - k - energy[0];
    int result2 = energy[n - 2] - k - energy[n - 1];
    int beforeVal1 = energy[0];
    int beforeVal2 = energy[n - 1];

    for (int i = 2; i < n; i++) {
        result1 = max(result1, energy[i] - k * i - beforeVal1);
        result2 = max(result2, energy[n - i - 1] - k * i - beforeVal2);
        beforeVal1 = min(beforeVal1, energy[i] - k * i);
        beforeVal2 = min(beforeVal2, energy[n - i - 1] - k * i);
    }

    cout << max(result1, result2);
}