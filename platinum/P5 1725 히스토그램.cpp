/*
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int n;
int rectangle[100002];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    stack<int> s;
    s.push(0);

    for(int i = 1; i <= n; i++)
        cin >> rectangle[i];

    int result = 0;
    for(int i = 1; i <= n + 1; i++) {
        while (!s.empty() && rectangle[s.top()] > rectangle[i]) {
            int topIdx = s.top(); s.pop();
            result = max(result, rectangle[topIdx] * (i - s.top() - 1));
        }

        s.push(i);
    }

    cout << result;

    return 0;
}
*/
