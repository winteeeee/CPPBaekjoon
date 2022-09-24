#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
int result = 0;
const int LEFT = 0;
const int RIGHT = 1;
const int UP = 2;
const int DOWN = 3;

void DFS(int depth, int max, int stat, int board[][21], bool movable[4]);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    int board[21][21];
    int max = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];

            if(max < board[i][j])
                max = board[i][j];
        }
    }

    bool movable1[4] = {true, true, true, true};
    bool movable2[4] = {true, true, true, true};
    bool movable3[4] = {true, true, true, true};
    bool movable4[4] = {true, true, true, true};
    int copyBoard1[21][21];
    copy(&board[0][0], &board[0][0] + 21 * 21, &copyBoard1[0][0]);
    DFS(0, max, LEFT, copyBoard1, movable1);

    int copyBoard2[21][21];
    copy(&board[0][0], &board[0][0] + 21 * 21, &copyBoard2[0][0]);
    DFS(0, max, RIGHT, copyBoard2, movable2);

    int copyBoard3[21][21];
    copy(&board[0][0], &board[0][0] + 21 * 21, &copyBoard3[0][0]);
    DFS(0, max, UP, copyBoard3, movable3);

    int copyBoard4[21][21];
    copy(&board[0][0], &board[0][0] + 21 * 21, &copyBoard4[0][0]);
    DFS(0, max, DOWN, copyBoard4, movable4);

    cout << result;
    return 0;
}

void DFS(int depth, int max, int stat, int board[][21], bool movable[4]) {
    if(depth == 10)
        return;

    int moveCount = 0;
    if(stat == LEFT) {
        for(int i = 0; i < n; i++) {
            int count = 0;
            for(int j = 1; j < n; j++) {
                int prev = board[i][j];
                if (board[i][j] != 0) {
                    if (board[i][0 + count] == board[i][j]) {
                        board[i][0 + count] *= 2;
                        board[i][j] = 0;

                        if (board[i][0 + count] > max)
                            max = board[i][0 + count];
                        count++;
                    }

                    else {
                        if (board[i][0 + count] == 0) {
                            board[i][0 + count] = board[i][j];
                            board[i][j] = 0;
                        }

                        else {
                            board[i][0 + count + 1] = board[i][j];
                            if(0 + count + 1 != j)
                                board[i][j] = 0;
                            count++;
                        }
                    }
                }

                if(prev == board[i][j]) {
                    moveCount++;
                }
            }
        }
    }

    else if(stat == RIGHT) {
        for(int i = 0; i < n; i++) {
            int count = 0;
            for(int j = n - 2; j >= 0; j--) {
                int prev = board[i][j];
                if (board[i][j] != 0) {
                    if (board[i][n - 1 - count] == board[i][j]) {
                        board[i][n - 1 - count] *= 2;
                        board[i][j] = 0;

                        if (board[i][n - 1 - count] > max)
                            max = board[i][n - 1 - count];
                        count++;
                    }

                    else {
                        if (board[i][n - 1 - count] == 0) {
                            board[i][n - 1 - count] = board[i][j];
                            board[i][j] = 0;
                        }

                        else {
                            board[i][n - 1 - count - 1] = board[i][j];
                            if(n - 1 - count - 1 != j)
                                board[i][j] = 0;
                            count++;
                        }
                    }
                }

                if(prev == board[i][j])
                    moveCount++;
            }
        }
    }

    else if(stat == UP) {
        for(int j = 0; j < n; j++) {
            int count = 0;
            for(int i = 1; i < n; i++) {
                int prev = board[i][j];
                if (board[i][j] != 0) {
                    if (board[0 + count][j] == board[i][j]) {
                        board[0 + count][j] *= 2;
                        board[i][j] = 0;

                        if (board[0 + count][j] > max)
                            max = board[0 + count][j];
                        count++;
                    }

                    else {
                        if (board[0 + count][j] == 0) {
                            board[0 + count][j] = board[i][j];
                            board[i][j] = 0;
                        }

                        else {
                            board[0 + count + 1][j] = board[i][j];
                            if(0 + count + 1 != i)
                                board[i][j] = 0;
                            count++;
                        }
                    }
                }

                if(prev == board[i][j])
                    moveCount++;
            }
        }
    }

    else {
        for(int j = 0; j < n; j++) {
            int count = 0;
            for(int i = n - 2; i >= 0; i--) {
                int prev = board[i][j];
                if (board[i][j] != 0) {
                    if (board[n - 1 - count][j] == board[i][j]) {
                        board[n - 1 - count][j] *= 2;
                        board[i][j] = 0;

                        if (board[n - 1 - count][j] > max)
                            max = board[n - 1 - count][j];
                        count++;
                    }

                    else {
                        if (board[n - 1 - count][j] == 0) {
                            board[n - 1 - count][j] = board[i][j];
                            board[i][j] = 0;
                        }

                        else {
                            board[n - 1 - count - 1][j] = board[i][j];
                            if(n - 1 - count - 1 != i)
                                board[i][j] = 0;
                            count++;
                        }
                    }
                }

                if(prev == board[i][j])
                    moveCount++;
            }
        }
    }

    if(moveCount == (n - 1) * n)
        movable[stat] = false;

    if(max > result)
        result = max;

    if(max * pow(2, 10 - depth) > result) {
        if(movable[LEFT]) {
            int copyBoard1[21][21];
            bool copyMovable[4];
            copy(&board[0][0], &board[0][0] + 21 * 21, &copyBoard1[0][0]);
            DFS(depth + 1, max, LEFT, copyBoard1, copyMovable);
        }

        if(movable[RIGHT]) {
            int copyBoard2[21][21];
            bool copyMovable[4];
            copy(&board[0][0], &board[0][0] + 21 * 21, &copyBoard2[0][0]);
            copy(movable, movable + 4, copyMovable);
            DFS(depth + 1, max, RIGHT, copyBoard2, copyMovable);
        }

        if(movable[UP]) {
            int copyBoard3[21][21];
            bool copyMovable[4];
            copy(&board[0][0], &board[0][0] + 21 * 21, &copyBoard3[0][0]);
            copy(movable, movable + 4, copyMovable);
            DFS(depth + 1, max, UP, copyBoard3, copyMovable);
        }

        if(movable[DOWN]) {
            int copyBoard4[21][21];
            bool copyMovable[4];
            copy(&board[0][0], &board[0][0] + 21 * 21, &copyBoard4[0][0]);
            copy(movable, movable + 4, copyMovable);
            DFS(depth + 1, max, DOWN, copyBoard4, copyMovable);
        }
    }
    board = NULL;
    movable = NULL;
}