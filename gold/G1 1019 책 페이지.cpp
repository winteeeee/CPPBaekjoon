#include <iostream>
using namespace std;

int n;
int result[10];

void input() {
    cin >> n;
}

void solve() {
    for(int i = 1; i <= n; i++) {
        string cur = to_string(i);

        for(int j = 0; j < cur.size(); j++) {
            result[cur[j] - '0']++;
        }

        if (i % 1000 == 0) {
            cout << i << " : ";
            cout << result[0] << " " << result[1] << " " << result[2] << " " << result[3] << " " << result[4] << " " << result[5] << " " << result[6] << " " << result[7] << " " << result[8] << " " << result[9];
            cout << '\n';
        }
    }
    cout << "최종 결과 : ";
    cout << result[0] << " " << result[1] << " " << result[2] << " " << result[3] << " " << result[4] << " " << result[5] << " " << result[6] << " " << result[7] << " " << result[8] << " " << result[9];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solve();
    return 0;
}