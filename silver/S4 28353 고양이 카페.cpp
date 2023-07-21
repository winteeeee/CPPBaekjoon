/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k, result;
vector<int> w;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        w.push_back(temp);
    }

    sort(w.begin(), w.end());
    int i = 0;
    int j = w.size() - 1;
    for (; i < j; i++) {
        for (; k >= 0 && w[i] + w[j] > k; j--);

        if (i < j) {
            result++;
            j--;
        } else {
            break;
        }
    }

    cout << result;
    return 0;
}
*/
