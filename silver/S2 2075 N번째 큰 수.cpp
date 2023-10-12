#include <iostream>
#include <queue>
using namespace std;

istream& operator>>(istream& in, priority_queue<int, vector<int>, greater<>>& h) {
    int temp;
    in >> temp;
    h.push(temp);

    return in;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    priority_queue<int, vector<int>, greater<>> h;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> h;
        }

        while (h.size() > n) {
            h.pop();
        }
    }

    cout << h.top();

    return 0;
}
