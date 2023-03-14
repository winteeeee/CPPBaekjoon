/*
#include <iostream>
using namespace std;

int n;
int result[10];

void input() {
    cin >> n;
}

void countNumber(int num, int cipher) {
    while(num > 0) {
        result[num % 10] = result[num % 10] + 1 * cipher;
        num /= 10;
    }
}

void countUnitsDigit(int a, int b, int cipher) {
    int tempB = b / 10;
    int tempA = a / 10;

    for (int i = 0; i < 10; i++) {
        result[i] += ((tempB - tempA + 1) * cipher);
    }
}

int findCipher(int b) {
    int cipher = 0;

    while (b > 0) {
        cipher++;
        b /= 10;
    }

    return cipher;
}

void countAtoB(int a, int b) {
    if (a == b) {
        while (a > 0) {
            result[a % 10]++;
            a /= 10;
        }
        return;
    }

    int count = 1;
    for (; a > 0; count *= 10, a /= 10, b /= 10) {
        int test = b;
        while (test % 10 != 9) {
            test--;

            if (test < 0) break;
        }

        if (test > 0 && test < a) {
            while (b % 10 != 9) {
                countNumber(b, count);
                b--;
            }

            return;
        }


        while (a % 10 != 0) {
            countNumber(a, count);
            a++;
            if (a > b) return;
        }

        while (b % 10 != 9) {
            countNumber(b, count);
            b--;
        }

        countUnitsDigit(a, b, count);
    }
}

int makeNines(int bCipher) {
    int temp = 9;
    for (int i = 0; i < bCipher - 1; i++) {
        temp = temp * 10 + 9;
    }

    return temp;
}


void solve() {
    */
/*
     * N이 3596이면
     * 1000 ~ 3596을 세고
     * 100 ~ 999를 세고
     * 10 ~ 99를 세고
     * 1 ~ 9를 센다
     *//*


    int a = 1;
    int b = n;
    int bCipher = findCipher(b);
    for (int i = 0; i < bCipher - 1; i++) {
        a *= 10;
    }

    for (; a > 0; a /= 10, b = makeNines(--bCipher)) {
        countAtoB(a, b);
    }

    cout << result[0] << " " << result[1] << " " << result[2] << " " << result[3] << " " << result[4] << " " << result[5] << " " << result[6] << " " << result[7] << " " << result[8] << " " << result[9];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solve();
    return 0;
}*/
