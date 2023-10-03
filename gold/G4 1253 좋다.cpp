#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, result;
vector<int> arr(2001);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //만일 벡터를 미리 할당해줬다면 sort할 때 범위 지정 주의
    sort(arr.begin(), arr.begin() + n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                int findTarget = arr[i] - arr[j];

                //일단 이분 탐색 해보고
                auto targetIdx = lower_bound(arr.begin(), arr.begin() + n, findTarget) - arr.begin();
                //찾은 녀석이 i, j와 같으면 안되므로 for문으로 밀어주고
                for (; targetIdx == i || targetIdx == j; targetIdx++) {}
                //그래도 조건을 만족하면 해당 수는 "좋다"로 취급
                if (arr[targetIdx] + arr[j] == arr[i]) {
                    result++;
                    break;
                }
            }
        }
    }

    cout << result;

    return 0;
}
