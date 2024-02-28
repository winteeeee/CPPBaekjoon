#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int x, b;
vector<int> result;
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

    cin >> x >> b;
}

pair<int, int> foo(int x, int b) {
    double c = floor((double)x / (double)b);
    double d = x - b * c;
    return {c, d};
}

void solve() {
    /*
     * [풀이]
     * 양의 진수로 바꾸는 경우는 우리가 이미 알고있는 진법 변환 식을 쓰면 된다.
     * 문제는 음의 진수로 바꾸는 경우인데 이 경우 몫과 나머지가 일반적인 연산자를 사용하면 원치 않는 결과가 나와
     * 따로 함수를 만들어서 음의 진수로 바꿔주면 된다.
     * 음의 진수로 바꾼다는 것이 처음에 직관적으로 이해가 안될 뿐이지
     * 검색하여 이해하면 구현 자체는 되게 간단한 문제.
     *
     * 시간 복잡도는 O(logX). 시간 제한도 넉넉하여 시간 초과가 날 걱정은 없다.
     */
    if (!x) {
        cout << 0;
    } else {
        if (b > 0) {
            if (x < 0) {
                cout << '-';
                x *= -1;
            }

            while (x) {
                result.push_back(x % b);
                x /= b;
            }
        } else {
            b *= -1;

            while (x) {
                pair<int, int> v = foo(x, b);
                result.push_back(v.second);
                x = v.first;
                x *= -1;
            }
        }

        for (int i = result.size() - 1; i >= 0; i--) {
            cout << result[i];
        }
    }
}