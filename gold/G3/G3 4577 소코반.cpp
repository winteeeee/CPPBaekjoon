#include <iostream>
#include <string>
using namespace std;

int r, c, boxCount, targetCount, playerR, playerC;
int count = 1;
char map[16][16];
char steppedChar;
string key, state;

void run();
void input();
void move();
void print();
int main() {
    /*
     * [풀이]
     * 구현 문제라서 풀이라고 할 것도 없다.
     * 그냥 조건에 맞춰서 구현하면 끝
     */
    run();

    return 0;
}

void run() {
    /*
     * .: 빈 공간
     * #: 벽
     * +: 비어 있는 목표점
     * b: 박스
     * B: 목표점 위에 있는 박스
     * w: 캐릭터
     * W: 목표점 위에 있는 캐릭터
     * U: 위
     * D: 아래
     * L: 왼쪽
     * R: 오른쪽
     */

    while (true) {
        input();

        if (r == 0 && c == 0) {
            break;
        }

        move();
        print();
    }
}

void updateState() {
    if (targetCount == boxCount) {
        state = "complete";
    } else {
        state = "incomplete";
    }
}

void input() {
    targetCount = 0;
    boxCount = 0;
    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'w' || map[i][j] == 'W') {
                playerR = i;
                playerC = j;

                if (map[i][j] == 'w') {
                    steppedChar = '.';
                } else {
                    steppedChar = '+';
                }
            }

            if (map[i][j] == '+' || map[i][j] == 'B' || map[i][j] == 'W') {
                targetCount++;
                if (map[i][j] == 'B') {
                    boxCount++;
                }
            }
        }
    }

    updateState();
    cin >> key;
}

char& getDestinationChar(char k) {
    if (k == 'U') {
        return map[playerR - 1][playerC];
    } else if (k == 'D') {
        return map[playerR + 1][playerC];
    } else if (k == 'L') {
        return map[playerR][playerC - 1];
    } else {
        return map[playerR][playerC + 1];
    }
}

char& getDestinationCharForBox(char k) {
    if (k == 'U') {
        return map[playerR - 2][playerC];
    } else if (k == 'D') {
        return map[playerR + 2][playerC];
    } else if (k == 'L') {
        return map[playerR][playerC - 2];
    } else {
        return map[playerR][playerC + 2];
    }
}

void updatePlayerPos(char k) {
    if (k == 'U') {
        playerR--;
    } else if (k == 'D') {
        playerR++;
    } else if (k == 'L') {
        playerC--;
    } else {
        playerC++;
    }
}

void move() {
    for (int i = 0; i < key.length() && state == "incomplete"; i++) {
        char& destination = getDestinationChar(key[i]);

        if (destination == '.' || destination == '+') {
            map[playerR][playerC] = steppedChar;
            steppedChar = destination;
            destination = steppedChar == '.' ? 'w' : 'W';
            updatePlayerPos(key[i]);
        } else if (destination == 'b' || destination == 'B') {
            char& destinationForBox = getDestinationCharForBox(key[i]);

            if (destinationForBox == '.' || destinationForBox == '+') {
                if (destination == 'b' && destinationForBox == '+') {
                    boxCount++;
                    updateState();
                } else if (destination == 'B' && destinationForBox == '.') {
                    boxCount--;
                    updateState();
                }

                destinationForBox = destinationForBox == '.' ? 'b' : 'B';
                map[playerR][playerC] = steppedChar;
                steppedChar = destination == 'b' ? '.' : '+';
                destination = steppedChar == '.' ? 'w' : 'W';
                updatePlayerPos(key[i]);
            }
        }
    }
}

void print() {
    updateState();
    cout << "Game " << count++ << ": " << state << '\n';
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << map[i][j];
        }
        cout << '\n';
    }
}