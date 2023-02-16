/*
#include <iostream>
using namespace std;

int T, N, W;
int enemy[2][10001];

void input() {
    cin >> T >> N >> W;

    for(int i = 0; i < N; i++) {
        cin >> enemy[0][i];
    }

    for(int i = 0; i < N; i++) {
        cin >> enemy[1][i];
    }
}

void solve() {
    for(int i = 0; i < T; i++) {
        */
/*
         * 1, 2, 8, 9 다 되는 상황에서
8을 먼저보는 로직이여서 8까지 커버하도록 했는데 이 때문에 결과적으로 더 많은 특수소대가 배치될 수 있다.

인접하는 구역?
원 자체가 달라지는 경우는 인덱스 + N.
오른쪽 왼쪽의 경우 인덱스 - 1, + 1을 하면 문제없으나 1일 때와 마지막 번호일 때는 조금 다르다.
1일 때는 1, 1 + 1, 1 + 8, N이다.
N일 때는 N, N - 1, N + N, 1이다.
         *//*

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solve();
}
*/
