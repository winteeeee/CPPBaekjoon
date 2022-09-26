/*
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int n;
long long rectangle[100002];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(1) {
        cin >> n;

        if(!n)
            break;

        stack<int> s;
        s.push(0);

        for (int i = 1; i <= n; i++)
            cin >> rectangle[i];
        rectangle[n + 1] = -1;

        long long result = 0;
        for (int i = 1; i <= n + 1; i++) {
            while (!s.empty() && rectangle[s.top()] > rectangle[i]) {
                long long topIdx = s.top();
                s.pop();
                long long temp = s.empty() ? rectangle[topIdx] * i : rectangle[topIdx] * (i - s.top() - 1);
                result = max(result, temp);
            }

            s.push(i);
        }

        cout << result << "\n";
    }

    return 0;
}*/
