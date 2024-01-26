#include <iostream>
using namespace std;

class Participant {
public:
    int ac;
    int convertCount;
};

int n, m;
int mat[101][10];
Participant participants[101];

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

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int ac;
        cin >> ac;
        participants[i] = {ac, 0};

        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        int oneCount = 0;
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 1) {
                oneCount++;
            }
        }
        participants[i].convertCount = participants[i].ac - oneCount;
    }
}

bool condition1() {
    //조건 1. 모든 참가자가 한 문제 이상을 풀어야 한다.
    for (int i = 0; i < n; i++) {
        if (participants[i].ac == 0) {
            return false;
        }
    }

    return true;
}

bool condition2() {
    //조건 2. 모든 문제는 한 명 이상의 참가자에게 풀려야 한다.
    for (int j = 0; j < m; j++) {
        int zeroCount = 0;
        int minusCount = 0;
        int oneCount = 0;
        for (int i = 0; i < n; i++) {
            if (mat[i][j] == 0) {
                zeroCount++;
            } else if (mat[i][j] == 1) {
                oneCount++;
                break;
            } else {
                minusCount++;
            }
        }

        if (!oneCount) {
            if (zeroCount == n) {
                //이 경우 어느 누구도 해당 문제를 풀 수 없으므로 조건 만족 불가능
                return false;
            }

            bool converted = false;
            for (int i = 0; i < n; i++) {
                //그렇지 않다면 찢어진 부분 중 하나를 1로 바꿔 해당 문제를 푼 사람을 만든다.
                if (mat[i][j] == -1 && participants[i].convertCount > 0) {
                    mat[i][j] = 1;
                    participants[i].convertCount--;
                    converted = true;
                    break;
                }
            }

            if (!converted) {
                //어느 한 사람이라도 1로 바꿀 수 있어야 해당 문제를 푼 사람을 만들 수 있음.
                return false;
            }
        }
    }

    return true;
}

bool condition3() {
    //조건 3. 모든 문제를 푼 참가자는 없어야 한다.
    for (int i = 0; i < n; i++) {
        if (participants[i].ac == m) {
            //ac의 개수가 문제의 개수와 같다면 모든 문제를 푼 참가자가 존재
            return false;
        }
    }

    return true;
}

void solve() {
    /*
     * [풀이]
     * 조건 3개를 만족하는지 체크하여 결과를 출력하면 되는 문제
     * 조건 1과 3은 ac 수만 보고 바로 판별할 수 있기 때문에 어렵지 않다.
     * 조건 2의 경우에도 스코어보드를 보고 논리적으로 조건이 가능한지 불가능한지 따져주면 됨
     * 원래는 그리디하게 접근해야하는 생각도 필요한듯 보이지만
     * 애초에 ac 기준으로 정렬된 상태로 입력되기 때문에 그냥 바꿀 수 있을 때 바로 1로 바꿔버려도 문제가 없다.
     *
     * 시간복잡도는 O(NM). 입력 형태가 행렬이기 때문에 이 미만으로 줄일 수는 없다.
     */
    if (condition1() && condition2() && condition3()) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}