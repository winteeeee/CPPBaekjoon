#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
/*
 * [풀이]
 * 어떨 때 가장 작아지는가?
 * 반복 횟수는 어떤 것을 선택하느냐에 따라 달라진다.
 * 두 묶음을 하나로 합칠 때 한 번 비교하고 합쳐진 묶음을 다른 묶음과 더할 때 다시 한 번 더해지기 때문이다.
 * 즉 선택하여 더한 값이 결과에 2번 더해지기(즉, 곱셈) 때문에 어느 묶음을 선택하느냐에 따라 결과가 달라지는 것이다.
 * 따라서 합쳐지는 묶음의 값이 가장 작아질 때 반복 횟수가 가장 작아진다.
 * 이를 위해 카드 뭉치 중에서 가장 작은 2개를 고르고 더하는 연산을 반복하면 된다.
 * 항상 최소값을 뽑아내야 하므로 힙을 사용한다.
 */

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    priority_queue<int, vector<int>, greater<>> h;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        h.push(temp);
    }


    int result = 0;
    if (n == 1) {
        //입력이 1인 경우에는 애초에 비교를 할 필요가 없다
        cout << result;
    } else {
        //pop을 두 번해서 비교해야하므로 조건을 size로 걸어줌
        while (h.size() > 1) {
            //가장 작은 카드 뭉치 2개를 꺼내서 합침
            int sum = h.top(); h.pop();
            sum += h.top(); h.pop();
            result += sum;

            //합쳐진 카드 뭉치를 힙에 다시 넣음
            h.push(sum);
        }

        //반복을 빠져나왔다는 소리는 카드 뭉치가 1개, 즉 카드의 비교가 모두 끝났다는 소리
        cout << result;
    }

    return 0;
}
