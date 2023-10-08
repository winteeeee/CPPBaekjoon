#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str;
    cin >> str;


    stack<char> s;
    int result = 0;
    bool canBeLaser = false;
    for (const auto& ch : str) {
        if (ch == '(') {
            canBeLaser = true;
            s.push(ch);
        } else {
            s.pop();
            if (canBeLaser) {
                //레이저라면 현재 존재하는 쇠막대기만큼 더함
                canBeLaser = false;
                result += s.size();
            } else {
                //레이저가 아니라면 쇠막대기의 마지막으로 1도막 추가함
                result += 1;
            }
        }
    }

    cout << result;
    return 0;
}
