#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

class Info {
public:
    int reservationTime;
    int arrivalTime;
};

bool cmp(const Info& a, const Info& b) {
    if (a.arrivalTime == b.arrivalTime) {
        return a.reservationTime < b.reservationTime;
    } else {
        return a.arrivalTime < b.arrivalTime;
    }
}

int n, result;
Info arr[100001];
bool waiting[300001];
bool visited[300001];
queue<Info> q;

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
    for(int i = 0; i < n; i++) {
        int reservationTime, arrivalTime;
        cin >> reservationTime >> arrivalTime;
        arr[i] = {reservationTime, arrivalTime};
    }

    sort(arr, arr + n, cmp);
}

void solve() {
    /*
     * [풀이]
     * 쉬워보였는데 낮은 정답율을 기록한 이유가 있었음
     * 문제를 계속 고민하다보면 결국 큐를 사용할 수 밖에 없다.
     * 우선순위 큐를 사용하고 싶어도 시간에 따라 우선순위가 바뀌기 때문에 사용하지 못한다.
     * 결국 큐를 사용해야하는데 큐에서 front가 아닌 원소를 pop 할 수가 없으므로
     * 따로 bool 배열을 통해 예약한 사람의 존재 여부를 기록하는 것이 핵심 아이디어
     *
     * 그 외에 주어진 수 범위를 벗어날 수 있는데 여기서 억까를 당했다.
     */

    int i = 0;
    int t = 1;
    for (; i < n || !q.empty(); t++) {
        for (; i < n && arr[i].arrivalTime == t; i++) {
            waiting[arr[i].reservationTime] = true;
            q.push(arr[i]);
        }

        if (waiting[t]) {
            visited[t] = true;
        } else {
            while (!q.empty() && visited[q.front().reservationTime]) {
                waiting[q.front().reservationTime] = false;
                result = max(result, q.front().reservationTime - q.front().arrivalTime); q.pop();
            }

            if (!q.empty()) {
                waiting[q.front().reservationTime] = false;
                result = max(result, t - q.front().arrivalTime); q.pop();
            }
        }
    }

    cout << result;
}