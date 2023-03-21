#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n;
long long result;
vector<int> arr;

void input() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
}

void solve() {
    stack<int> s;

    for (int i = 0; i < n; i++) {
        if (s.empty()) {
            s.push(arr[i]);
        } else {
            for (int top = s.top(); !s.empty() && top < arr[i];) {
                result++;
                s.pop();

                if (!s.empty()) {
                    top = s.top();
                }
            }

            result += s.size();
            s.push(arr[i]);
        }
    }

    cout << result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solve();

    return 0;
}