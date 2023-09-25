#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<int> arr;
vector<int> prefixSum;

bool isAssignable(const int& a) {
    int size = arr.size();
    return arr[a] * (size - 1 - a) <= m - prefixSum[a];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    cin >> m;

    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        if (i) {
            prefixSum.push_back(prefixSum.back() + arr[i]);
        } else {
            prefixSum.push_back(arr[i]);
        }
    }

    if (arr[0] * arr.size() > m) {
        //가장 작은 원소로도 배정이 불가능하다면 애초에 매개변수 탐색할 이유가 없음
        cout << m / arr.size();
    } else {
        int start = 0;
        int end = arr.size() - 1;
        int assignable = start;

        while (start <= end) {
            int mid = (start + end) / 2;

            if (isAssignable(mid)) {
                assignable = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        //arr[assignable]까진 반드시 배정 가능하다는 것을 보장한 상태.
        if (assignable == arr.size() - 1) {
            //배정 가능한 인덱스가 마지막 원소인 경우
            cout << arr[assignable];
        } else {
            //이 블록안에 들어온 경우 arr[assignable]은 반드시 답이 아님. (답이었다면 assignable 자체의 값이 1 올랐을 것)
            //따라서 그 사이에 있는 값을 구해줌
            cout << (m - prefixSum[assignable]) / (arr.size() - 1 - assignable);
        }
    }

    return 0;
}
