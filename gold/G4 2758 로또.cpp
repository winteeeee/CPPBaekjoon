#include <iostream>
using namespace std;

long long count = 0;
int t, n, m;
void counting(int cur, int selectCount) {
    if(selectCount >= n) {
        count++;
        return;
    }

    for(int i = cur * 2; i <= m; i++) {
        counting(i, selectCount + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    for(int i = 0; i < t; i++) {
        cin >> n >> m;
        counting(1, 1);
        cout << count << '\n';
        count = 0;
    }

    return 0;
}