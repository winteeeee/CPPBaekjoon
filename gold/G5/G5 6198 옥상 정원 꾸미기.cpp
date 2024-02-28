/*
#include <iostream>
#include <stack>
using namespace std;

int n;
int building[80000];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> building[i];

    stack<int> s;
    long long result = 0;
    for(int i = 0; i < n; i++) {
        while(!s.empty() && s.top() <= building[i])
            s.pop();

        s.push(building[i]);
        result += s.size() - 1;
    }

    cout << result;
    return 0;
}
*/
