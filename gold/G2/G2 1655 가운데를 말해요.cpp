#include <iostream>
#include <queue>
using namespace std;

/* [풀이]
 * 시간 제한이 굉장히 빡빡한 문제.
 * 만일 정렬된 벡터를 유지할 수 있으면 벡터.size() / 2로 O(1)만에 찾을 수 있다.
 * 하지만 정렬된 벡터를 유지하려면 값을 입력 받을 때마다 정렬 해야하는데
 * 이 문제는 시간 제한이 0.1초로 굉장히 빡빡하기 때문에 반드시 시간 초과가 난다.
 *
 * 따라서 다른 접근법을 사용한다.
 * 이 문제의 포인트는 값이 정렬되어 있다고 가정할 때 값의 중간값을 기준으로 앞 혹은 뒤의 2개 원소만 보면 된다는 점이다.
 * 그 이외의 원소는 이미 중간값과는 거리가 멀어졌으므로 원소가 어떻게 들어오든 절대 중간값이 될 수 없다.
 * 따라서 우리는 우선순위 큐를 2개 사용한다는 아이디어를 떠올릴 수 있다.
 * 우선순위 큐는 항상 최소, 최대 값을 보장하므로 우리가 원하는 중간값 및 앞, 뒤 원소 2개를 지속적으로 관리할 수 있다.
 * 값이 들어올 때마다 큐에 삽입과 삭제 연산만 1, 2번 하면 되므로 O(N)에 문제를 해결할 수 있다.
 *
 * 최대힙과 최소힙 2개를 선언하고 최대힙에는 작은 값들을 보관, 최소힙에는 큰 값들을 보관하고
 * 두 힙 사이즈의 균형을 지속적으로 맞추며(짝수인 경우는 작은 녀석을 출력해야하므로 최대힙의 크기가 최대 1만 크도록)
 * 최대힙의 top 값을 출력해주면 된다.
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    priority_queue<int> h1;
    priority_queue<int, vector<int>, greater<>> h2;

    int n;
    cin >> n;
    vector<int> arr;

    if (n == 1) {
        int cur;
        cin >> cur;
        cout << cur;
    } else {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        if (temp1 < temp2) {
            h1.push(temp1);
            h2.push(temp2);
        } else {
            h1.push(temp2);
            h2.push(temp1);
        }
        cout << temp1 << '\n' << h1.top() << '\n';

        for (int i = 2; i < n; i++) {
            cin >> temp1;

            if (temp1 > h2.top()) {
                h2.push(temp1);
            } else {
                h1.push(temp1);
            }

            if (h1.size() - h2.size() == 2) {
                h2.push(h1.top()); h1.pop();
            } else if (h2.size() - h1.size() == 1) {
                h1.push(h2.top()); h2.pop();
            }

            cout << h1.top() << '\n';
        }
    }

    return 0;
}
