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
     * 
     * 양의 진수로 바꾸는 경우는 우리가 이미 알고있는 진법 변환 식을 쓰면 된다.
     * 문제는 음의 진수로 바꾸는 경우인데 이 경우 몫과 나머지가 일반적인 연산자를 사용하면 원치 않는 결과가 나와
     * 따로 함수를 만들어서 음의 진수로 바꿔주면 된다.
     * 음의 진수로 바꾼다는 것이 처음에 직관적으로 이해가 안될 뿐이지
     * 검색하여 이해하면 구현 자체는 되게 간단한 문제.
     *
     * 시간 복잡도는 O(logX). 시간 제한도 넉넉하여 시간 초과가 날 걱정은 없다.
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