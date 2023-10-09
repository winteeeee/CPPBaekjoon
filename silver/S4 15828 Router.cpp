#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    int input = 0;
    queue<int> q;
    while (input + 1) {
        cin >> input;

        if (input > 0 && q.size() < n) {
            //정보가 들어오면 큐에 push
            //이미 사이즈만큼 차 있다면 버려야 함
            q.push(input);
        } else if (!input) {
            //0이 들어오면 정보를 처리했으니 q에서 해당 정보 pop
            q.pop();
        }
    }

    if (q.empty()) {
        cout << "empty";
    } else {
        while (!q.empty()) {
            cout << q.front() << " "; q.pop();
        }
    }

    return 0;
}
