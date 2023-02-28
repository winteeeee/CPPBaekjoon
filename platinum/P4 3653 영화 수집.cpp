#include <iostream>
#include <vector>
using namespace std;

int t, n, m;
vector<int> movie;

void input() {
    cin >> n >> m;
    movie.reserve(n);

    for(int i = 0; i < m; i++) {
        cin >> movie[i];
    }
}

void solve() {
    cin >> t;

    for(int i = 0; i < t; i++) {
        input();
        //i번째 인덱스가 선택되면 0 ~ i - 1번째 인덱스의 값을 증가시키고 i번째 인덱스는 값을 0으로 만드는 쿼리를 logN으로 구현
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solve();
    return 0;
}
