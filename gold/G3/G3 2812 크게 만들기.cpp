#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    string number;
    cin >> n >> k >> number;

    stack<char> s;
    for (const auto& ch : number) {
        //push 하기 전 스택에 존재하는 자신보다 작은 원소들 모두 버림
        //k는 버릴 수 있는 횟수로 간주
        for (; !s.empty() && s.top() - '0' < ch - '0' && k; k--) {
            s.pop();
        }
        s.push(ch);
    }

    //주어진 수를 전부 다 봤지만 다 안버렸을 경우 끝부터 버림
    for (; !s.empty() && k; k--) {
        s.pop();
    }

    string result;
    while (!s.empty()) {
        result += s.top(); s.pop();
    }
    reverse(result.begin(), result.end());
    cout << result;

    return 0;
}
