#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> arr;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int sum = 0;
    int max = 0;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);

        sum += temp;
        if (max < temp) {
            max = temp;
        }
    }
    cin >> m;

    if (sum > m) {

    } else {
        cout << max;
    }

    return 0;
}
