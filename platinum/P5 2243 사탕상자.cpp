#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
class candy {
public:
    int A;
    int B;
    int C;
};
vector<candy> orders;
vector<int> candyBox;

void input() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        int A, B;

        cin >> A >> B;
        if (A == 2) {
            int C;
            cin >> C;
            orders.push_back({A, B, C});
        } else {
            orders.push_back({A, B - 1});
        }
    }
}

void solve() {
    for (int i = 0; i < orders.size(); i++) {
        candy cur = orders[i];

        if (cur.A == 1) {   //꺼내기
            cout << candyBox[cur.B] << '\n';
            copy(candyBox.begin() + cur.B + 1, candyBox.end(), candyBox.begin() + cur.B);
            candyBox.pop_back();
        } else {    //넣기
            if (cur.C > 0) {    //넣기
                vector<int> temp(cur.C, cur.B);
                candyBox.resize(candyBox.size() + cur.C);
                copy(temp.begin(), temp.end(), candyBox.end() - cur.C);
                sort(candyBox.begin(), candyBox.end());
            } else {    //꺼내기
                int targetIndex = lower_bound(candyBox.begin(), candyBox.end(), cur.B) - candyBox.begin();
                copy(candyBox.begin() + targetIndex + (cur.C * -1), candyBox.end(), candyBox.begin() + targetIndex);
                candyBox.resize(candyBox.size() + cur.C);
            }
        }
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