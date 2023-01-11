/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int answer = -1;
bool table[10][10];
bool curTable[10][10];
int xRange[5] {-1, 1, 0, 0, 0};
int yRange[5] {0, 0, -1, 1, 0};

void assign() {
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            curTable[i][j] = table[i][j];
        }
    }
}

void input() {
    char temp;

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cin >> temp;

            if(temp == '#') {
                table[i][j] = 0;
            }

            else {
                table[i][j] = 1;
            }
        }
    }

    assign();
}

void convertSwitch(int i, int j) {
    for(int k = 0; k < 5; k++) {
        if((0 <= i + yRange[k] && i + yRange[k] < 10) && (0 <= j + xRange[k] && j + xRange[k] < 10)) {
            curTable[i + yRange[k]][j + xRange[k]] = !curTable[i + yRange[k]][j + xRange[k]];
        }
    }
}

int counting() {
    int result = 0;

    for(int i = 1; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if(curTable[i - 1][j]) {
                convertSwitch(i, j);
                result++;
            }
        }
    }

    return result;
}

bool isOff() {
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if(curTable[i][j]) {
                return false;
            }
        }
    }

    return true;
}

void solve() {
    for(int i = 0; i <= 10; i++) { //i개를 택한다.
        vector<int> combination(10);
        for(int j = 0; j < i; j++) {
            combination[9 - j] = 1;
        }

        do {
            for(int j = 0; j < 10; j++) { //선택된 1째줄 전구를 누름
                if(combination[j]) {
                    convertSwitch(0, j);
                }
            }

            int curCount;

            curCount = counting() + i;
            if(isOff()) {
                if(answer == -1) {
                    answer = curCount;
                }

                else {
                    answer = min(answer, curCount);
                }
            }

            assign();
        } while(next_permutation(combination.begin(), combination.end()));
    }

    cout << answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solve();
}

*/
