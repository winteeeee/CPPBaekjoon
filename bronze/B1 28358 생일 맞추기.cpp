/*
#include <iostream>
using namespace std;

int t;
int numbers[10];
int lastDay[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void numbersInput() {
    for (int& e : numbers) {
        cin >> e;
    }
}

bool check(int month, int day) {
    string monthStr = to_string(month);
    string dayStr = to_string(day);

    for (char e : monthStr) {
        if (numbers[e - '0']) {
            return false;
        }
    }

    for (char e : dayStr) {
        if (numbers[e - '0']) {
            return false;
        }
    }

    return day <= lastDay[month];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    for (int i = 0; i < t; i++) {
        numbersInput();

        int result = 0;
        for (int j = 1; j <= 12; j++) {
            for (int k = 1; k <= 31; k++) {
                if (check(j, k)) {
                    result++;
                }
            }
        }
        cout << result << '\n';
    }

    return 0;
}
*/
