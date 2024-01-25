#include <iostream>
using namespace std;

int n;
int mat[401][401];
int sumOfAnotherDiagonal[802][401];
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
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }
}

int getB(int i, int j, int k) {
    if (k == 0) {
        return mat[i][j];
    }

    int diff = min(i, n - 1 - (j + k));
    int startR = i - diff;
    int startC = j + k + diff;
    int idx = startR == 0 ? startC : n - 1 + startR;

    if (i + k - startR - (k + 1) >= 0) {
        return sumOfAnotherDiagonal[idx][i + k - startR] - sumOfAnotherDiagonal[idx][i + k - startR - (k + 1)];
    } else {
        return sumOfAnotherDiagonal[idx][i + k - startR];
    }
}

void solve() {
    /*
     * [풀이]
     * 부분 행렬을 구해야하므로 브루트포스스럽게 접근하는데
     * 합을 빠르게 구해야하므로 누적합을 이용한다.
     * 이때 주대각성분의 누적합은 브루트포스 과정에서 자연스럽게 구할 수 있으므로
     * 반대쪽 대각성분만 누적합을 이용하여 빠르게 구해준다.
     * 인덱스 실수를 너무 많이 해서 시간이 굉장히 오래걸렸던 문제
     *
     * 시간 복잡도는 O(n^3). n이 최대 400으로 크지 않아 n^3이 돈다.
     * 부분 행렬을 모두 봐야하므로 이 이상으로 줄일 수는 없는듯
     */
    int result = 0;

    for (int i = 0; i < n + (n - 1); i++) {
        int r = i < n ? 0 : i - n + 1;
        int c = i < n ? i : n - 1;
        for (int j = 0; r + j < n && c - j >= 0; j++) {
            sumOfAnotherDiagonal[i][j] += mat[r + j][c - j];

            if (j) {
                sumOfAnotherDiagonal[i][j] += sumOfAnotherDiagonal[i][j - 1];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int A = 0;
            int B = 0;
            for (int k = 0; i + k < n && j + k < n; k++) {
                A += mat[i + k][j + k];
                B = getB(i, j, k);
                result = max(result, A - B);
            }
        }
    }

    cout << result;
}