#include <iostream>
#include <vector>
using namespace std;

class Digit {
public:
    int zero;
    int one;
};

long long n;
vector<int> arr;
vector<Digit> digitArr(21);
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
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        arr.push_back(temp);
    }
}

void solve() {
    /*
     * [풀이]
     * 각 자리의 0과 1의 숫자를 센다.
     * 모든 자릿수 별로 연산의 총 개수는 NC2로 나타낼 수 있다.
     * 이때 같은 숫자끼리 수행하는 연산은 더해도 0이므로 결과에 영향을 끼치지 않는다.
     * 따라서 다른 숫자끼리 수행하는 연산을 구하기 위해 전체 연산 수 - 같은 숫자 연산 수를 계산한다.
     * 이후 이전 자릿수에서 올림수가 올라올 수도 있으므로 해당 올림수도 같이 반영한다.
     * 즉 다른 숫자 연산 + 올림수가 바로 해당 자릿수에 영향을 끼칠 수 있는 수들이며
     * 이를 적절히 연산하여 결과를 구한다.
     *
     * 시간 복잡도는 처음 모든 수의 0과 1의 개수를 셀 때 O(N)이 걸리지만
     * 이후 연산은 비트의 자릿수만큼만 수행되므로 상수 시간만큼이 들어
     * 최종 시간 복잡도는 O(N)이다.
     */
    for (int i = 0; i < n; i++) {
        int target = arr[i];

        for (int j = 0; j < 21; j++) {
            if (target & (1 << j)) {
                digitArr[j].one++;
            } else {
                digitArr[j].zero++;
            }
        }
    }

    long long result = 0;
    long long carry = 0;
    long long totalCalc = n * (n - 1) / 2;
    for (int i = 0; i < 21; i++) {
        long long zero = digitArr[i].zero;
        long long one = digitArr[i].one;
        long long equalCalc = (zero * (zero - 1) / 2) + (one * (one - 1) / 2);
        long long diffCalc = totalCalc - equalCalc;

        result += ((diffCalc + carry) % 2) << i;
        carry = (diffCalc + carry) / 2;
    }

    for (int i = 21; carry; i++) {
        result += (carry % 2) << i;
        carry /= 2;
    }

    cout << result;
}