/*
#include <iostream>
#include <climits>
using namespace std;

int n, m, k;
char map[501][501];
char pattern[501][501];

void check() {
    int alphabet[26] = {0, };

    for (int a = 0; a < k; a++) {
        for (int b = 0; b < k; b++) {
            for (int i = 0; i < n / k; i++) {
                for (int j = 0; j < m / k; j++) {
                    alphabet[map[i * k + a][j * k + b] - 'A']++;
                }
            }

            int maxVal = INT_MIN;
            int maxValIdx = 0;
            for (int i = 0; i < 26; i++) {
                if (alphabet[i] > maxVal) {
                    maxVal = alphabet[i];
                    maxValIdx = i;
                }
            }
            pattern[a][b] = maxValIdx + 'A';

            for (int i = 0; i < 26; i++) {
                alphabet[i] = 0;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    check();
    int diff = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] != pattern[i % k][j % k]) {
                diff++;
            }
        }
    }

    cout << diff << '\n';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << pattern[i % k][j % k];
        }
        cout << '\n';
    }
}
*/
