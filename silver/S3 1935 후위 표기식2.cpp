/*
#include <iostream>
#include <stack>
using namespace std;

int n;
string formula;
int map[26];

void input() {
    cin >> n >> formula;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        map[i] = temp;
    }
}

void solve() {
    stack<double> s;

    for (int i = 0; i < formula.length(); i++) {
        double a, b;

        if (formula[i] == '+') {
            b = s.top(); s.pop();
            a = s.top(); s.pop();

            s.push(a + b);
        } else if (formula[i] == '-') {
            b = s.top(); s.pop();
            a = s.top(); s.pop();

            s.push(a - b);
        } else if (formula[i] == '*') {
            b = s.top(); s.pop();
            a = s.top(); s.pop();

            s.push(a * b);
        } else if (formula[i] == '/') {
            b = s.top(); s.pop();
            a = s.top(); s.pop();

            s.push(a / b);
        } else {
            s.push(map[formula[i] - 'A']);
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << s.top();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input();
    solve();

    return 0;
}*/
