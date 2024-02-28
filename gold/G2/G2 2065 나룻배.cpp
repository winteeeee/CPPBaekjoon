#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int count = 0;

class Info {
public:
    int num;
    int time;
    string pos;
};

istream& operator>>(istream& in, Info& i) {
    int t;
    string p;
    in >> t >> p;

    i.num = count++;
    i.time = t;
    i.pos = p;

    return in;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int m, t, n;
    cin >> m >> t >> n;

    bool isLeft = true;
    int time = 0;
    queue<Info> left;
    queue<Info> right;
    queue<Info> boat;
    vector<int> result(10001);

    for (int i = 0; i < n; i++) {
        Info cur;
        cin >> cur;

        if (cur.pos == "left") {
            left.push(cur);
        } else {
            right.push(cur);
        }
    }

    while (!left.empty() || !right.empty()) {
        //나룻배 최대 자리만큼, 현재 시간 이전에 도착한 사람들을 다 태움
        if (isLeft) {
            while (!left.empty() && boat.size() < m && left.front().time <= time) {
                boat.push(left.front());
                left.pop();
            }
        } else {
            while (!right.empty() && boat.size() < m && right.front().time <= time) {
                boat.push(right.front());
                right.pop();
            }
        }

        if (!boat.empty()) {
            isLeft = !isLeft;
            time += t;

            //반대편 정거장에 도착하여 내려주고 결과 배열에 기록
            while (!boat.empty()) {
                result[boat.front().num] = time;
                boat.pop();
            }
        } else {
            //반대편에 탈 손님이 있으면 그쪽으로 이동
            if ((!left.empty() && boat.size() <= m && left.front().time <= time) ||
                (!right.empty() && boat.size() <= m && right.front().time <= time)) {
                isLeft = !isLeft;
                time += t;
            } else {
                //반대편에도 없으면 바로 다음 손님이 올 때까지 대기
                if (left.empty()) {
                    time = right.front().time;
                } else if (right.empty()) {
                    time = left.front().time;
                } else {
                    time = left.front().time < right.front().time ? left.front().time : right.front().time;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << result[i] << '\n';
    }

    return 0;
}
