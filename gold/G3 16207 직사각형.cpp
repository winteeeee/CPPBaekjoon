#include <iostream>
#include <algorithm>
using namespace std;

int n, arr[100001];
long long sum;

void input();
void solve();

int main() {
    input();
    solve();

    return 0;
}

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}


void solve() {
    /*
     * [풀이]
     * 자잘한 조건들이 많이 붙어있지만 정렬한 뒤 그리디하게 풀 수 있다는 것만 체크하면
     * 해당 조건들을 신경 쓸 필요가 없다.
     * 직사각형의 한 변이 될 수 있는 막대 2개를 잡아두고
     * 나머지 한 변이 될 수 있는 막대 2개가 찾아지면 바로 넓이로 더해버리면 된다.
     * 솔직히 골3은 너무 난이도가 높게 평가된 것 같다. 푸는데 30분도 안걸린듯
     *
     * 시간 복잡도는 O(N). 주어진 배열을 한 번만 순회하면 구할 수 있다.
     */
    sort(arr, arr + n);

    for (int i = n - 1; i > 0; i--) {
        if (arr[i] - arr[i - 1] < 2) {
            for (int j = i - 2; j > 0; j--) {
                if (arr[j] - arr[j - 1] < 2) {
                    sum += (long long)min(arr[i], arr[i - 1]) * (long long)min(arr[j], arr[j - 1]);
                    i = j - 1;
                    break;
                }
            }
        }
    }

    cout << sum;
}